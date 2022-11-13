# include "libft.h"

char		**__rc_strsplit ( char *ptr, int *nb, char *sep ) {
	assert( ptr != NULL && nb != NULL && sep != NULL );

	char	**arr = 0X00;
	char *tmp = strdup( ptr );
	if ( ! tmp )
		goto __rc_strsplit_end;
	*nb = strsplit( tmp, NULL, 0, sep );
	free( tmp );
	if ( *nb <= 0X00 )
		goto __rc_strsplit_end;
	arr = calloc(sizeof(char *), *nb + 0X01 );
	if ( ! arr )
		goto __rc_strsplit_end;
	strsplit( ptr, arr, *nb, sep);
__rc_strsplit_end:
		return ( arr );
		
}
