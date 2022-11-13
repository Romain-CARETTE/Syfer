# include "libft.h"
static void	init_random( void ) {
	srand(time(NULL));
}

int
_random( int max, int min) {
	static uint8_t init = 0X00;
	if ( init == 0X00 )
	{
		(void )init_random(); 
		init |= 0X01; 
	}
	int n = (rand() % (max - min + 1)) + min;
	return ( n );
}

int
_random_except( int max, int min, int *except, int nb ) {

	int n = 0X00;	
	while ( 1 )
	{
		_ready_random:
			n = _random( max, min );
			for( int iterator = 0X00; iterator < nb; ++iterator )
				if ( n == except[ iterator ] )
					goto _ready_random;
			goto _random_except_end;
	}
_random_except_end:
		return ( n );
}
