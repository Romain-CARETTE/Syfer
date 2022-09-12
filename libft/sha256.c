#include "libft.h"

void	sha256( char *str, size_t len, unsigned char *output ) {
	SHA256_CTX	ctx = {0};
	SHA256_Init( &ctx );
	SHA256_Update( &ctx, str, len );

	unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
	SHA256_Final( hash, &ctx );
	memcpy( output, hash, SHA256_DIGEST_LENGTH );
}
