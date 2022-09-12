#include "libft.h"

#define MAX_LEN 1024
#define MAXSIZE 1000000
#define M_ITERATION 15

void	__print_k( unsigned char *k, int n ) {
	for( int i = 0; i < n; ++i ) {
		printf("%x ", (unsigned char)k[i]);
	}
	printf("\n");
}

/*
 * \fn static void	__private_key( int *, int, int );
 * \brief Generate the private key.
 */
static void	__private_key( int *private, int n, int generator ) {
	for( int i = 0; i < n; ++i )
		private[ i ] = ( rand() % ( generator -1) + 1 );
}

/*
 * \fn static void	__private_key( int *, int, int );
 * \brief Generate the public key.
 */
static void	__public_key( int *private, int *public, int n, int generator, int prime ) {
	
	for( int i = 0; i < n; ++i )
		public[ i ] = compute_exp_modulo( generator, private[ i ], prime );
}

/*
 * \fn int		__exchange_key_srv( unsigned char *, int, int );
 * \brief ...
 */
int		__exchange_key_srv( unsigned char *secret_k, int n, int fd ) {
	
	int	prime;
	int res = recv( fd, &prime, sizeof( int ), 0X00 );
	if ( res == 0X00 )
		return ( 0X01 );

	int generator;
	res = recv( fd, &generator, sizeof( int ), 0X00 );
	if ( res == 0X00 )
		return ( 0X01 );

	int	public_k_srv[ 0X20 ];
	res = recv( fd, &public_k_srv, sizeof( int )*n, 0X00 );
	if ( res == 0X00 )
		return ( 0X01 );

	
	int	private_k[ n ];
	__private_key( private_k, n, generator );
	int	public_k[ n ];
	__public_key( private_k, public_k, n, generator, prime );
	
	for ( int i = 0; i < n; ++i )
		secret_k[ i ] = ( compute_exp_modulo( public_k_srv[ i ], private_k[ i ], prime) & 0XFF );

	res = send( fd, public_k, sizeof( int )*n, MSG_DONTWAIT );
	if ( res == -1 )
		return ( 0x01 );
	memset( public_k, 0, sizeof(int)*n);
	memset( private_k, 0, sizeof(int)*n);
	return ( 0X00 );
}

int		__exchange_key_clt( unsigned char *secret_k, int n, int fd ) {
	
	int prime = GeneratePrime();
	int generator = GeneratePrimitiveRoot( prime );

	int	private_k[ n ];
	__private_key( private_k, n, generator );
	int	public_k[ n ];
	__public_key( private_k, public_k, n, generator, prime );

	// Send prime number generator number.
	int res = send( fd, &prime, sizeof( int ), MSG_DONTWAIT );
	if ( res == -1 )
		return ( 0X01 );

	// Send generator number.
	res = send( fd, &generator, sizeof( int ), MSG_DONTWAIT );
	if ( res == -1 )
		return ( 0X01 );

	// Send public key
	res = send( fd, public_k, sizeof( int )*n, MSG_DONTWAIT );
	if ( res == -1 )
		return ( 0X01 );


	// Get public key of client.
	res = recv( fd, &public_k, sizeof( int )*n, 0X00 );
	if ( res == 0X00 )
		return ( 0X01 );
	for ( int i = 0; i < n; ++i )
		secret_k[ i ] = ( compute_exp_modulo( public_k[ i ], private_k[ i ], prime) & 0XFF );
	memset( public_k, 0, sizeof(int)*n);
	memset( private_k, 0, sizeof(int)*n);
	return ( 0X00 );
}


/* Function to compute (a ^ b) mod p */
int
compute_exp_modulo( int a, int b, int p ) {
	long long x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1)
			x = (x * y) % p;
		y = (y * y) % p;
		b /= 2;
	}
	return (int)(x % p);
}

/* Function to check primality of random generated numbers using Miller-Rabin Test */
int
MillerRabinTest( int value, int iteration ) {
	if (value < 2)
		return 0;
	int q = value - 1, k = 0;
	while (!(q % 2)) {
		q /= 2;
		k++;
	}
	for (int i = 0; i < iteration; i++) {
		int a = rand() % (value - 1) + 1;
		int current = q;
		int flag = 1;
		int mod_result = compute_exp_modulo(a, current, value);
		for (int i = 1; i <= k; i++) {
			if (mod_result == 1 || mod_result == value - 1) {
				flag = 0;
				break;
			}
			mod_result = (int)((long long)mod_result * mod_result % value);
		}
		if (flag)
			return 0;
	}
	return 1;
}

/* Generate a prime number that is going to be shared 
 * globally between client and server
 */
int
GeneratePrime() {
	srand(time(NULL));
	while(1) {
		int current_value = rand() % INT_MAX;
		if (!(current_value % 2))
			current_value++;
		if (MillerRabinTest(current_value, M_ITERATION) == 1)
			return current_value;
	}
}

/* Generate the primitive root by checking for random numbers */
int
GeneratePrimitiveRoot( int p ) {
	/* Construct sieve of primes */
	int sieve[MAXSIZE];
	memset(&sieve, 0, MAXSIZE*sizeof(int) );
	sieve[0] = sieve[1] = 1;
	for (int i = 4; i < MAXSIZE; i += 2)
		sieve[i] = 1;
	for (int i = 3; i < MAXSIZE; i += 2) {
		if (!sieve[i]) {
			for (int j = 2 * i; j < MAXSIZE; j += i)
				sieve[j] = 1;
		}
	}
	while (1) {
		int a = rand() % (p - 2) + 2;
		int phi = p - 1, flag = 1, root = sqrt(phi);
		for (int i = 2; i <= root; i++) {
			if (!sieve[i] && !(phi % i)) {
				int mod_result = compute_exp_modulo(a, phi / i, p);
				if (mod_result == 1) {
					flag = 0;
					break;
				}
				if (MillerRabinTest(phi / i, M_ITERATION) && !(phi % (phi / i))) {
					int mod_result = compute_exp_modulo(a, phi / (phi / i), p);
					if (mod_result == 1) {
						flag = 0;
						break;
					}
				}
			}
		}
		if ( flag ) 
			return a;
	}
}
