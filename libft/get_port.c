# include "libft.h"

uint32_t	get_port ( struct sockaddr_in *addr ) {
	return ( htons(addr->sin_port) );
}
