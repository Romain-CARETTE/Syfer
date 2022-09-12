# include "libft.h"
char 		*get_ip( struct sockaddr_in *addr ) {
	return ( inet_ntoa( addr->sin_addr ));
}
