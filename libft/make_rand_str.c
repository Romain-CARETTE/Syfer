#include "libft.h"

char	*make_rand_str( char *str, int n ) {
	
	static const int a = 'a', z = 'z';
	int	seed = ( unsigned int)time( NULL );
	srand( seed );

	for ( int i = 0; i < n; ++i )
		str[ i ] = ( rand() % ( z-a + 0X01) + a ) ;
	return ( str );
}
