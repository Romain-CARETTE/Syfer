# include "libft.h"

uint8_t		*__rc_read_file ( const char *filename, struct stat *sb ) {
	assert( filename != NULL );
	assert( sb != NULL );


	uint8_t	*ptr = 0X00;

	int	fd  = open( filename, O_RDONLY );
	if ( fd == -1 )
		goto __rc_map_file_end;
	else if ( fstat( fd, sb ) == -1 )
		goto __rc_map_file_end;
	else if ( S_ISREG(sb->st_mode) == 0X00 )
		goto __rc_map_file_end;
	else if ( ( ptr = calloc( sizeof( char), sb->st_size )) == NULL )
		goto __rc_map_file_end;
	else if ( read( fd, ptr, sb->st_size ) == sb->st_size )
		goto __rc_map_file_end;

	free( ptr );
	ptr = 0X00;

__rc_map_file_end:
		(fd != -1) ? close ( fd ) : 0X00;
		return ( ptr );
		
}
