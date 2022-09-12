# include "libft.h"

unsigned short	__rc_checksum( void *b, int len ) {   
       	unsigned short *buf = b;
	unsigned int sum = 0X00;
	for ( sum = 0; len > 1; len -= 2 )
		sum += *buf++;
	if ( len == 1 )
		sum += *(unsigned char*)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	return ( ~sum );
}
