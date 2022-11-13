#include "../include/main.h"
unsigned char handler_x64_2[] = {
  0xe9, 0xb9, 0x00, 0x00, 0x00, 0xc3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x00, 0xb8, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xe8, 0x0c,
  0x00, 0x00, 0x00, 0x2e, 0x2e, 0x2e, 0x53, 0x79, 0x66, 0x65, 0x72, 0x2e,
  0x2e, 0x2e, 0x0a, 0xbf, 0x01, 0x00, 0x00, 0x00, 0x5e, 0xba, 0x0c, 0x00,
  0x00, 0x00, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc3, 0x55, 0x48,
  0x89, 0xe5, 0x48, 0x83, 0xec, 0x10, 0x48, 0x89, 0xf8, 0x48, 0x89, 0x45,
  0xf0, 0xba, 0x00, 0x10, 0x00, 0x00, 0x48, 0x63, 0xca, 0x48, 0x31, 0xd2,
  0x48, 0xf7, 0xf1, 0x48, 0x89, 0xd0, 0x48, 0xf7, 0xd8, 0x48, 0x01, 0x45,
  0xf0, 0x48, 0x8b, 0x7d, 0xf0, 0xc9, 0xc3, 0x55, 0x48, 0x89, 0xe5, 0x48,
  0x89, 0x7d, 0xf8, 0x89, 0x75, 0xf4, 0x48, 0x89, 0x55, 0xe8, 0xc7, 0x45,
  0xe4, 0x00, 0x00, 0x00, 0x00, 0x8b, 0x45, 0xe4, 0x3b, 0x45, 0xf4, 0x73,
  0x37, 0x48, 0x8b, 0x45, 0xf8, 0x8b, 0x4d, 0xe4, 0x89, 0xca, 0x0f, 0xb6,
  0x0c, 0x10, 0x48, 0x8b, 0x45, 0xe8, 0x8b, 0x75, 0xe4, 0x89, 0xf2, 0x48,
  0x83, 0xe2, 0x07, 0x0f, 0xb6, 0x34, 0x10, 0x31, 0xf1, 0x48, 0x8b, 0x45,
  0xf8, 0x8b, 0x75, 0xe4, 0x89, 0xf2, 0x88, 0x0c, 0x10, 0x8b, 0x45, 0xe4,
  0x83, 0xc0, 0x01, 0x89, 0x45, 0xe4, 0xeb, 0xc1, 0x5d, 0xc3, 0x50, 0x51,
  0x53, 0x52, 0x57, 0x56, 0xe8, 0x4d, 0xff, 0xff, 0xff, 0x48, 0x8d, 0x3d,
  0x30, 0xff, 0xff, 0xff, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x57,
  0xe8, 0x5d, 0xff, 0xff, 0xff, 0x48, 0x31, 0xf6, 0x90, 0x90, 0x90, 0x90,
  0x90, 0xba, 0x07, 0x00, 0x00, 0x00, 0xb8, 0x0a, 0x00, 0x00, 0x00, 0x0f,
  0x05, 0x5f, 0x48, 0x8d, 0x15, 0x0d, 0xff, 0xff, 0xff, 0x90, 0x90, 0x90,
  0x90, 0x90, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x70, 0xe8, 0x5c,
  0xff, 0xff, 0xff, 0x48, 0x83, 0xc4, 0x70, 0x5d, 0x55, 0x48, 0x89, 0xe5,
  0x48, 0x81, 0xec, 0x00, 0x02, 0x00, 0x00, 0x48, 0x8d, 0x3d, 0xe3, 0xfe,
  0xff, 0xff, 0x48, 0x8d, 0x35, 0xe6, 0xfe, 0xff, 0xff, 0x48, 0x89, 0x3c,
  0x24, 0x48, 0xc7, 0x44, 0x24, 0x08, 0x00, 0x00, 0x00, 0x04, 0x48, 0x89,
  0x74, 0x24, 0x10, 0xb8, 0x0d, 0x00, 0x00, 0x00, 0xbf, 0x05, 0x00, 0x00,
  0x00, 0x48, 0x89, 0xe6, 0x48, 0x31, 0xd2, 0x41, 0xba, 0x08, 0x00, 0x00,
  0x00, 0x0f, 0x05, 0xc9, 0x5e, 0x5f, 0x5a, 0x5b, 0x59, 0x58, 0x90, 0x90,
  0x90, 0x90, 0x90
};

unsigned char handler_x64[] = {
  0x4c, 0x8d, 0x3d, 0x0c, 0x00, 0x00, 0x00, 0x4c, 0x8d, 0x35, 0x51, 0x02,
  0x00, 0x00, 0xe9, 0x77, 0x02, 0x00, 0x00, 0x48, 0x89, 0xe7, 0x48, 0x81,
  0xc7, 0xb0, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3f, 0xe8, 0x3d, 0x01, 0x00,
  0x00, 0x48, 0x83, 0xf8, 0x01, 0x74, 0x7b, 0x48, 0x31, 0xd2, 0x48, 0x31,
  0xc0, 0xb8, 0x1b, 0x00, 0x00, 0x00, 0x66, 0x8b, 0x17, 0x48, 0xf7, 0xe2,
  0x48, 0x8d, 0x35, 0x74, 0x03, 0x00, 0x00, 0x48, 0x8b, 0x36, 0x48, 0x01,
  0xc6, 0x80, 0x3e, 0x01, 0x74, 0x0f, 0x57, 0x56, 0x41, 0xba, 0x07, 0x00,
  0x00, 0x00, 0xe8, 0xc8, 0x01, 0x00, 0x00, 0x5e, 0x5f, 0x48, 0x83, 0xc7,
  0x02, 0x48, 0x89, 0xf0, 0x48, 0x31, 0xf6, 0x48, 0x8b, 0x70, 0x03, 0x48,
  0xff, 0xce, 0x48, 0x89, 0xc2, 0x52, 0x41, 0x5f, 0x48, 0x83, 0xc2, 0x13,
  0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x70, 0xc6, 0x04, 0x37, 0xcc,
  0xe8, 0x26, 0x00, 0x00, 0x00, 0x41, 0xc6, 0x07, 0x01, 0x48, 0x83, 0xc4,
  0x70, 0x5d, 0xe8, 0x6f, 0x00, 0x00, 0x00, 0x48, 0x83, 0xef, 0x03, 0xc6,
  0x07, 0x55, 0xc6, 0x47, 0x01, 0x48, 0xc6, 0x47, 0x02, 0x89, 0x48, 0x89,
  0xbc, 0x24, 0xb0, 0x00, 0x00, 0x00, 0xc3, 0x55, 0x48, 0x89, 0xe5, 0x48,
  0x89, 0x7d, 0xf8, 0x89, 0x75, 0xf4, 0x48, 0x89, 0x55, 0xe8, 0xc7, 0x45,
  0xe4, 0x00, 0x00, 0x00, 0x00, 0x8b, 0x45, 0xe4, 0x3b, 0x45, 0xf4, 0x73,
  0x37, 0x48, 0x8b, 0x45, 0xf8, 0x8b, 0x4d, 0xe4, 0x89, 0xca, 0x0f, 0xb6,
  0x0c, 0x10, 0x48, 0x8b, 0x45, 0xe8, 0x8b, 0x75, 0xe4, 0x89, 0xf2, 0x48,
  0x83, 0xe2, 0x07, 0x0f, 0xb6, 0x34, 0x10, 0x31, 0xf1, 0x48, 0x8b, 0x45,
  0xf8, 0x8b, 0x75, 0xe4, 0x89, 0xf2, 0x88, 0x0c, 0x10, 0x8b, 0x45, 0xe4,
  0x83, 0xc0, 0x01, 0x89, 0x45, 0xe4, 0xeb, 0xc1, 0x5d, 0xc3, 0x48, 0x8d,
  0x35, 0xaa, 0x02, 0x00, 0x00, 0x48, 0x8b, 0x76, 0x08, 0x48, 0x8b, 0x0e,
  0x48, 0x83, 0x06, 0x01, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x83, 0x3e, 0x00,
  0x74, 0x06, 0x48, 0x83, 0xc6, 0x12, 0xe2, 0xf4, 0x57, 0x48, 0x01, 0xd7,
  0x48, 0x83, 0xc7, 0x02, 0x48, 0x89, 0x3e, 0x5f, 0x49, 0x8b, 0x47, 0x03,
  0x48, 0x89, 0x46, 0x08, 0x6a, 0x00, 0x58, 0x66, 0x41, 0x8b, 0x47, 0x01,
  0x66, 0x89, 0x46, 0x10, 0xc3, 0x6a, 0x00, 0x58, 0xb8, 0x1b, 0x00, 0x00,
  0x00, 0x48, 0xf7, 0xe2, 0x48, 0x8d, 0x35, 0x5c, 0x02, 0x00, 0x00, 0x48,
  0x8b, 0x36, 0x48, 0x01, 0xc6, 0xc3, 0x48, 0x8d, 0x35, 0x4e, 0x02, 0x00,
  0x00, 0x48, 0x8b, 0x76, 0x08, 0x48, 0x8b, 0x0e, 0x48, 0x83, 0xf9, 0x00,
  0x0f, 0x84, 0xa5, 0x00, 0x00, 0x00, 0x48, 0x83, 0xc6, 0x08, 0x48, 0x8b,
  0x16, 0x48, 0x39, 0xd7, 0x74, 0x0b, 0x48, 0x83, 0xc6, 0x12, 0xe2, 0xf2,
  0xe9, 0x8e, 0x00, 0x00, 0x00, 0x48, 0x31, 0xd2, 0x66, 0x8b, 0x56, 0x10,
  0x48, 0xc7, 0x06, 0x00, 0x00, 0x00, 0x00, 0x48, 0xc7, 0x46, 0x08, 0x00,
  0x00, 0x00, 0x00, 0x66, 0xc7, 0x46, 0x10, 0x00, 0x00, 0x48, 0x8d, 0x35,
  0x03, 0x02, 0x00, 0x00, 0x48, 0x8b, 0x76, 0x08, 0x48, 0x83, 0x2e, 0x01,
  0xe8, 0x88, 0xff, 0xff, 0xff, 0x57, 0x48, 0x8b, 0x56, 0x03, 0x48, 0x29,
  0xd7, 0x48, 0x83, 0xef, 0x03, 0xc6, 0x07, 0xcc, 0x48, 0x31, 0xdb, 0x66,
  0x8b, 0x5e, 0x01, 0x66, 0x89, 0x5f, 0x01, 0x48, 0x83, 0xc7, 0x03, 0x48,
  0x83, 0xc6, 0x13, 0x57, 0x56, 0x52, 0x48, 0x89, 0xf7, 0xbe, 0x08, 0x00,
  0x00, 0x00, 0x48, 0x31, 0xd2, 0xb8, 0x3e, 0x01, 0x00, 0x00, 0x0f, 0x05,
  0x5a, 0x5e, 0x5f, 0x48, 0x87, 0xf2, 0x48, 0xff, 0xce, 0x55, 0x48, 0x89,
  0xe5, 0x48, 0x83, 0xec, 0x70, 0xe8, 0xa1, 0xfe, 0xff, 0xff, 0x48, 0x83,
  0xc4, 0x70, 0x5d, 0x5f, 0x48, 0x83, 0xef, 0x01, 0xc6, 0x07, 0xc3, 0x6a,
  0x01, 0x58, 0xc3, 0x6a, 0x00, 0x58, 0xc3, 0x55, 0x48, 0x89, 0xe5, 0x48,
  0x83, 0xec, 0x10, 0x48, 0x89, 0xf8, 0x48, 0x89, 0x45, 0xf0, 0xba, 0x00,
  0x20, 0x00, 0x00, 0x48, 0x63, 0xca, 0x48, 0x31, 0xd2, 0x48, 0xf7, 0xf1,
  0x48, 0x89, 0xd0, 0x48, 0xf7, 0xd8, 0x48, 0x01, 0x45, 0xf0, 0x48, 0x8b,
  0x7d, 0xf0, 0xbe, 0x00, 0x20, 0x00, 0x00, 0x4c, 0x89, 0xd2, 0xb8, 0x0a,
  0x00, 0x00, 0x00, 0x0f, 0x05, 0xc9, 0xc3, 0xb8, 0x0f, 0x00, 0x00, 0x00,
  0x0f, 0x05, 0xe8, 0x0c, 0x00, 0x00, 0x00, 0x2e, 0x2e, 0x2e, 0x53, 0x79,
  0x66, 0x65, 0x72, 0x2e, 0x2e, 0x2e, 0x0a, 0xbf, 0x01, 0x00, 0x00, 0x00,
  0x5e, 0xba, 0x0c, 0x00, 0x00, 0x00, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x0f,
  0x05, 0xc3, 0x50, 0x51, 0x53, 0x52, 0x57, 0x56, 0x48, 0x8b, 0x7c, 0x24,
  0x38, 0xbe, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x02, 0x00, 0x00, 0x00, 0x0f,
  0x05, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x10, 0x48, 0x89, 0x04,
  0x24, 0x48, 0x89, 0xc7, 0xb8, 0x08, 0x00, 0x00, 0x00, 0xfc, 0xfc, 0xfc,
  0xfc, 0xfc, 0xba, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xb8, 0x09, 0x00,
  0x00, 0x00, 0x48, 0x31, 0xff, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xba, 0x03,
  0x00, 0x00, 0x00, 0x41, 0xba, 0x22, 0x00, 0x00, 0x00, 0x49, 0xc7, 0xc0,
  0xff, 0xff, 0xff, 0xff, 0x4d, 0x31, 0xc9, 0x0f, 0x05, 0x48, 0x89, 0x44,
  0x24, 0x08, 0x48, 0x8b, 0x3c, 0x24, 0x48, 0x8b, 0x74, 0x24, 0x08, 0xfc,
  0xfc, 0xfc, 0xfc, 0xfc, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xe8,
  0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x24, 0xb9, 0x00, 0x20, 0x00,
  0x00, 0xba, 0x00, 0x00, 0x00, 0x00, 0x48, 0xf7, 0xf1, 0x48, 0x89, 0xd0,
  0x48, 0xf7, 0xd8, 0x48, 0x01, 0x04, 0x24, 0x5f, 0xbe, 0x00, 0x20, 0x00,
  0x00, 0xba, 0x07, 0x00, 0x00, 0x00, 0xb8, 0x0a, 0x00, 0x00, 0x00, 0x0f,
  0x05, 0x48, 0x8d, 0x1d, 0x7f, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x54, 0x24,
  0x08, 0x48, 0x89, 0x13, 0x48, 0x83, 0xc4, 0x10, 0x5d, 0xe8, 0x1c, 0xff,
  0xff, 0xff, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x81, 0xec, 0x00, 0x02, 0x00,
  0x00, 0x4c, 0x89, 0x3c, 0x24, 0x48, 0xc7, 0x44, 0x24, 0x08, 0x00, 0x00,
  0x00, 0x04, 0x4c, 0x89, 0x74, 0x24, 0x10, 0xb8, 0x0d, 0x00, 0x00, 0x00,
  0xbf, 0x05, 0x00, 0x00, 0x00, 0x48, 0x89, 0xe6, 0x48, 0x31, 0xd2, 0x41,
  0xba, 0x08, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc9, 0xb8, 0x09, 0x00, 0x00,
  0x00, 0x48, 0x31, 0xff, 0xbe, 0x00, 0x00, 0x01, 0x00, 0xba, 0x03, 0x00,
  0x00, 0x00, 0x41, 0xba, 0x22, 0x00, 0x00, 0x00, 0x49, 0xc7, 0xc0, 0xff,
  0xff, 0xff, 0xff, 0x4d, 0x31, 0xc9, 0x0f, 0x05, 0x48, 0x8d, 0x3d, 0x0c,
  0x00, 0x00, 0x00, 0x48, 0x89, 0x47, 0x08, 0x5e, 0x5f, 0x5a, 0x5b, 0x59,
  0x58, 0xeb, 0x10, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x90, 0x90, 0x90, 0x90, 0x90
};

static void
SY_sha256( char *str, size_t len, char *output ) {
	SHA256_CTX	ctx = {0};
	SHA256_Init( &ctx );
	SHA256_Update( &ctx, str, len );

	unsigned char hash[SHA256_DIGEST_LENGTH] = {0};
	SHA256_Final( hash, &ctx );
	for ( int i = 0; i < SHA256_DIGEST_LENGTH; i++ )
		sprintf( output + i * 2, "%02x", hash[i] );
}

void	__sy_create_file( const char *ptr, const char *out_filename, size_t *size  )
{
	char filename[ PATH_MAX ] = { 0x00 }, hash[ SHA256_DIGEST_LENGTH * 2 + 1 ] = { 0x00 };
	SY_sha256( (char *)ptr, *size + __ALIGN_MASK( getpagesize(), *size ), hash );
	sprintf( filename, "OUT_bin/%s.%s", out_filename, hash );
	rename( "woody", filename );
}

static uint8_t
__sy_key_generation( unsigned char *key ) {
	if (syscall(SYS_getrandom, key, 16, 0) == -1 )
		return ( 0X01 );
	return ( 0X00 );
}

void	set_shdr_offset(Elf64_Shdr *shdr, uint64_t offset, uint16_t shnum, uint64_t padding )
{
	for( int i = 0; i < shnum; ++i )
	{
		if (shdr[i].sh_offset > offset) {
			shdr[i].sh_offset += padding;
		}
	}
}

void	set_phdr_offset( Elf64_Phdr *phdr, uint64_t offset, uint16_t phnum, uint64_t padding )
{
	for( int i = 0; i < phnum; ++i )
	{
		if (phdr[i].p_offset + phdr[i].p_filesz > offset) {
			phdr[i].p_offset += padding;
		}
	}
}

void
SYFER_set_sub( uint8_t *stub, size_t size_stub, const uint8_t *data, int size_data ) {
	uint8_t 	m[] = "\xf9\xf9\xf9\xf9\xf9\xf9\xf9";

	int i;
	for ( i = 0X00; i < size_stub; i++ )
	{
		if ( memcmp( &stub[i], m, 7 ) == 0X00 )
		{
			printf("l: %x\n", stub[i+0]);
			printf("l: %x\n", stub[i+1]);
			printf("l: %x\n", stub[i+2]);
			printf("l: %x\n", stub[i+3]);
			printf("l: %x\n", stub[i+4]);
			memmove( &stub[i], data, size_data );
			break;
		}
	}
}

void
SYFER_set_mov( uint8_t *stub, size_t size_stub, const uint8_t *data, const size_t size_data ) {
	uint8_t 	m[] = "\xfc\xfc\xfc\xfc\xfc";

	int i;
	for ( i = 0X00; i < size_stub; i++ )
	{
		if ( memcmp( &stub[i], m, 5 ) == 0X00 )
		{
			printf("l: %x\n", stub[i+0]);
			printf("l: %x\n", stub[i+1]);
			printf("l: %x\n", stub[i+2]);
			printf("l: %x\n", stub[i+3]);
			printf("l: %x\n", stub[i+4]);
			memmove( &stub[i], data, size_data );
			break;
		}
	}
}

void
SYFER_set_jmp( uint8_t *stub, const int *addr, const size_t size ) {
	uint8_t 	m[] = "\x90\x90\x90\x90\x90";

	int i;
	for ( i = 0X00; i < size; i++ )
	{
		if ( memcmp( &stub[i], m, 5 ) == 0X00 )
		{
			printf("%x\n", stub[i+0]);
			printf("%x\n", stub[i+1]);
			printf("%x\n", stub[i+2]);
			printf("%x\n", stub[i+3]);
			printf("%x\n", stub[i+4]);
			m[ 0X00 ] = 0XE9;
			memmove(m+1, addr, sizeof( int ) );
			memmove( &stub[i], m, 5 );
			break;
		}
	}
}


uint8_t
set_payload_for_to_get_the_address( uint8_t *stub, const size_t size, uint32_t *value ) {
	assert( stub != NULL );
	assert( value != NULL );

	int size_data;
	uint8_t res = 0X01;
	uint8_t *data = __mh_sub_regx64_imm32( NDR_RDI, *value, &size_data );
	if ( data == NULL )
		return ( res );

	for ( size_t i = 0X00; i < size; ++i ) {
		if ( memcmp( &stub[i], "\x90\x90\x90\x90\x90\x90\x90", 0X07 ) == 0X00 ) {
			memmove( &stub[ i ], data, size_data );
			res = 0X00;		
			goto L1;
		}
	}
L1:
	free( data );
	return ( res );
}

uint8_t
set_the_size_of_the_text_section_in_the_payload( uint8_t *stub, const size_t size, uint32_t value ) {
	assert( stub != NULL );
	
	int size_data;
	uint8_t res = 0X01;
	uint8_t *data = __mh_mov_regx32_imm32( NDR_RSI, value, &size_data );
	if ( data == NULL )
		return ( res );

	for ( size_t i = 0X00; i < size; ++i ) {
		if ( memcmp( &stub[i], "\x90\x90\x90\x90\x90", 0X05 ) == 0X00 ) {
			memmove( &stub[ i ], data, size_data );
			res = 0X00;		
			goto L1;
		}
	}
L1:
	free( data );
	return ( res );

}

uint8_t
set_the_payload_to_enable_memory_writing( uint8_t *stub, const size_t size, uint32_t value ) {
	assert( stub != NULL );

	int size_data;
	uint8_t res = 0X01;
	uint8_t *data = __mh_mov_regx32_imm32( NDR_RSI, value, &size_data );
	if ( data == NULL )
		return ( res );

	while ( ++value % 16 != 0X00 )
		;
	for ( size_t i = 0X00; i < size; ++i ) {
		if ( memcmp( &stub[i], "\x90\x90\x90\x90\x90", 0X05 ) == 0X00 ) {
			memmove( &stub[ i ], data, size_data );
			res = 0X00;		
			goto L1;
		}
	}
L1:
	free( data );
	return ( res );
}

uint8_t
__sy_set_byte( uint8_t *stub, const size_t size, uint8_t byte ) {
	
	uint8_t res = 0X01;
	for ( size_t i = 0X00; i < size; ++i ) {
		if ( memcmp( &stub[i], "\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe", 0X08 ) == 0X00 ) {
			stub[ i + 0X09 ] = byte;	
			res = 0X00;		
			goto L1;
		}
	}
L1:
	return ( res );

}

uint8_t
__sy_set_encoder( uint8_t *stub, const size_t size, char *enc, uint8_t size_encoder ) {
	
	uint8_t res = 0X01;
	for ( size_t i = 0X00; i < size; ++i ) {
		if ( memcmp( &stub[i], "\xfe\xfe\xfe\xfe\xfe\xfe\xfe\xfe", 0X08 ) == 0X00 ) {
			memmove( &stub[ i ], enc, size_encoder );
			res = 0X00;		
			goto L1;
		}
	}
L1:
	return ( res );

}

Elf64_Phdr	*get_pload_EXEC( char *ptr, Elf64_Ehdr *hdr)
{
	Elf64_Phdr	*phdr_EXEC = ((void *)ptr + hdr->e_phoff) ;

	for(uint16_t i = 0 ; i < hdr->e_phnum ; i++, phdr_EXEC++)
		if (phdr_EXEC->p_type == PT_LOAD && phdr_EXEC->p_flags & PF_X)
			return (phdr_EXEC) ;
	return (NULL);	
}


void modify_stub_to_apply_internal_encryption( uint8_t *stub, size_t *size_stub,  Elf64_Phdr *OLD_exec_seg, size_t *stub_size_whitout_data ) {

	int	size_data = 0X00;
	uint8_t *data = __mh_mov_regx32_imm32( NDR_RSI, OLD_exec_seg->p_offset +OLD_exec_seg->p_filesz+*stub_size_whitout_data, &size_data );
	assert( data != NULL );
	SYFER_set_mov( stub, *size_stub, data, size_data );
	free( data );
	
	size_data = 0X00;
	size_t stub_size_data = ( *size_stub - *stub_size_whitout_data );
	data = __mh_mov_regx32_imm32( NDR_RSI, stub_size_data, &size_data );
	assert( data != NULL );
	SYFER_set_mov( stub, *size_stub, data, size_data );
	free( data );

	size_data = 0X00;
	data = __mh_mov_regx32_imm32( NDR_RDX, stub_size_data, &size_data );
	assert( data != NULL );
	SYFER_set_mov( stub, *size_stub, data, size_data );
	free( data );
}

int
syfer_silvio_cesare_text_infection( t_elf *elf, size_t *size_stub, size_t *stub_size_whitout_data ) {
	Elf64_Ehdr	*hdr = ( Elf64_Ehdr *)elf->ptr;
	if ( hdr->e_phnum == 1 )
		return ( 1 );
	printf("elf->text->sh_offset toto: %ld\n", elf->text->sh_addr);
	Elf64_Phdr	*phdr_EXEC = get_pload_EXEC(elf->ptr, hdr);
	assert( phdr_EXEC != NULL );
	Elf64_Phdr	*phdr_NOT_EXEC = ( phdr_EXEC+1 );
	assert( phdr_NOT_EXEC != NULL );

	uint32_t off = (phdr_EXEC->p_offset + phdr_EXEC->p_filesz) - elf->text->sh_offset;
	if ( set_payload_for_to_get_the_address( elf->stub, *stub_size_whitout_data, &off ) )
		return ( 0X01 );
	if ( set_the_payload_to_enable_memory_writing( elf->stub, *stub_size_whitout_data, phdr_EXEC->p_memsz ) )
		return ( 0X01 );


	uint8_t	key[ 16 ] = { 0X00 };
	if ( syscall(SYS_getrandom, key, 0X08, 0) == -1 )
		return fprintf( stderr, "%s[+] Key generation failed.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
	size_t ite = 0X00;
	while ( ite < *size_stub )
	{
		if ( memcmp( &elf->stub[ ite ], "\xff\xff\xff\xff\xff\xff\xff\xff", 0X08) == 0X00 ) {
			memmove( &elf->stub[ ite ], key, 0X08 );
			break;
		}
		ite = ( ite + 1 );
	}

	fprintf( stderr, "%s[+] Successful key generation.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);

	uint8_t	*ptr = (uint8_t *)elf->ptr+elf->text->sh_offset;
	uint32_t	size = elf->text->sh_size;
	SY_xor( ptr, elf->text->sh_size, key );
	fprintf( stderr, "%s[+] Global encryption applied with the key ", ANSI_COLOR_GREEN);
	for( uint8_t j = 0X00; j < 0X08; ++j )
		fprintf( stderr, "0X%.2X ", key[ j ]);
	fprintf( stderr, "%s\n", ANSI_COLOR_RESET);
	fprintf( stderr, "%s\t[*] From %s%p %sto %s%p%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_BLUE, ptr, ANSI_COLOR_GREEN,  ANSI_COLOR_BLUE, ptr+elf->text->sh_size, ANSI_COLOR_RESET);
	fprintf( stderr, "%s\t[*] Total number of encrypted bytes: %u %s\n", ANSI_COLOR_GREEN, size, ANSI_COLOR_RESET);

	if ( set_the_size_of_the_text_section_in_the_payload( elf->stub, *stub_size_whitout_data,  size ) )
		return ( 0X01 );


	uint64_t	padding = __ALIGN_MASK( getpagesize(), *size_stub );
	Elf64_Phdr	OLD_exec_seg = { 0X00 }, OLD_next_seg = { 0X00 };
	Elf64_Ehdr	header = { 0X00 };
	memmove( &OLD_exec_seg, phdr_EXEC, sizeof( Elf64_Phdr ));
	memmove( &OLD_next_seg, phdr_NOT_EXEC, sizeof( Elf64_Phdr));
	memmove( &header, hdr, sizeof( Elf64_Ehdr));

	int fd = open("woody", O_CREAT | O_RDWR | O_TRUNC, 0755);
	if ( fd == -1 )
		return fprintf( stderr, "%s [-] Unable to create the temporary file \"woody\".%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);

	set_phdr_offset((void *)(elf->ptr + hdr->e_phoff), phdr_EXEC->p_offset + phdr_EXEC->p_filesz,hdr->e_phnum, padding);
	set_shdr_offset((void *)(elf->ptr + hdr->e_shoff), phdr_EXEC->p_offset + phdr_EXEC->p_filesz,hdr->e_shnum, padding);
	hdr->e_shoff += padding;
	phdr_EXEC->p_memsz += *size_stub;
	phdr_EXEC->p_filesz += *size_stub;
	elf->text->sh_size += *size_stub;

	hdr->e_entry = ( OLD_exec_seg.p_vaddr + OLD_exec_seg.p_filesz );
		
	write( fd, elf->ptr, OLD_next_seg.p_offset );
	uint8_t	pad[0X1000] = {0} ;
	for ( int i = 0X00; i < padding; i+= 0X1000 )
		write( fd, pad, 0X1000 );
	write( fd, elf->ptr + OLD_next_seg.p_offset, elf->filesize - OLD_exec_seg.p_offset );

	if ( elf->symtab )
		( void )modify_stub_to_apply_internal_encryption( elf->stub, size_stub, &OLD_exec_seg, stub_size_whitout_data );
				
	int addr_jmp = header.e_entry - (hdr->e_entry + *stub_size_whitout_data);
	SYFER_set_jmp( elf->stub, &addr_jmp, *size_stub );
	lseek(fd, OLD_exec_seg.p_offset + OLD_exec_seg.p_filesz, SEEK_SET);

	write(fd, elf->stub, *size_stub);
	close(fd);
	return ( 0 );
}



Elf64_Shdr	*__GET_shdr( void *ptr, Elf64_Ehdr *hdr, const char *sect_name )
{
	if ( hdr->e_shoff == 0X00 )
		return ( NULL );
	Elf64_Shdr	*shdr = (Elf64_Shdr *)((void *)ptr + hdr->e_shoff);
	if ( hdr->e_shstrndx == SHN_UNDEF )
		return ( NULL );
	Elf64_Shdr	*sect_strtab = shdr + hdr->e_shstrndx;
	char		*str = (char *)((void *)ptr + sect_strtab->sh_offset);

	for(uint16_t i = 0; i < hdr->e_shnum; i++, shdr++) {
		if ( ! memcmp(str + shdr->sh_name, sect_name, strlen( sect_name )))
			return (shdr);
	}
	return (NULL);
}

static uint8_t	__GET_sect( t_elf *elf )
{
	Elf64_Ehdr	*header = (Elf64_Ehdr *)elf->ptr;
	elf->strtab = __GET_shdr( elf->ptr, header, ".strtab" );
	if ( elf->strtab == NULL )
		fprintf( stderr, "%s[*] The .strtab section was not found - (Binary is stripped)\n%s", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET );
	else
		fprintf( stderr, "%s[*] The .strtab section was found at %s[%p]%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_GREEN, elf->ptr+elf->strtab->sh_offset, ANSI_COLOR_RESET);

	elf->symtab = __GET_shdr( elf->ptr, header, ".symtab" );
	if ( elf->symtab == NULL )
		fprintf( stderr, "%s[*] The .symtab section was not found - (Binary is stripped)\n%s", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET );
	else
		fprintf( stderr, "%s[*] The .symtab section was found at %s[%p]%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_GREEN, elf->ptr+elf->symtab->sh_offset, ANSI_COLOR_RESET);
			
	elf->text = __GET_shdr( elf->ptr, header, ".text" );
	if ( elf->text == NULL )
		return fprintf( stderr, "%s[*] The .text section was not found\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET );
	else {
		fprintf( stderr, "%s[*] The .text section was found at %s[%p]%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_BLUE, elf->ptr+elf->text->sh_offset, ANSI_COLOR_RESET);
		fprintf( stderr, "\t%s[*] Size of the .text section: %ld bytes %s\n", ANSI_COLOR_GREEN, elf->text->sh_size, ANSI_COLOR_RESET);
	}
	return ( 0X00 );
}	

static uint8_t
__SY_copy_mem( char *filename, char *mem, ssize_t size ) {

    uint8_t res = 0X01;
    int fd = open( filename, O_RDONLY );
    if ( fd == -1 )
        return fprintf( stderr, "%s[-] The opening of the %s file in read mode has failed. Errno: %s%s\n", ANSI_COLOR_RED, filename, strerror(errno), ANSI_COLOR_RESET);
    fprintf( stderr, "%s[+] Successful opened file %s in read mode%s\n", ANSI_COLOR_GREEN, filename, ANSI_COLOR_RESET);

    if ( read( fd, mem, size ) != size ) {
        fprintf( stderr, "%s[-] Failed to read %s file.%s\n", ANSI_COLOR_RED, filename, ANSI_COLOR_RESET);
        goto end;
    }
    fprintf( stderr, "%s[+] Successful reading of %s file.%s\n", ANSI_COLOR_GREEN, filename, ANSI_COLOR_RESET);
    fprintf( stderr, "%s[+] Closing the %s file.%s\n", ANSI_COLOR_GREEN, filename, ANSI_COLOR_RESET);
    res = 0x00;
end:
    (fd != -1 ) ? close ( fd ) : 0x00;
    return ( res );
}

static void
__sy_set_payload( uint8_t *stub, uint64_t *size, uint8_t type )
{
	switch( type )
	{
		case 0:
			memcpy( stub, handler_x64, *size );
			break;
		case 1:
			memcpy( stub, handler_x64_2, *size );
			break;
	}
}

/*
 * \fn static int _check_header_ELFx64( const void *)
 * \brief [ Check some information in the ELF header. ]
 * 	  [ If any of the information below is not correct, the binary is not packed. ]
 * 	    List of informations:
 * 	  	* E_ENTRY
 * 	  	* E_PHOFF
 * 	  	* E_PHNUM
 */
static int
_check_header_ELFx64( const void *ptr )
{
	Elf64_Ehdr	*hdr = (Elf64_Ehdr *)ptr;
	if ( hdr->e_entry == 0X00 ) { fprintf( stderr, "%s[-] No entry point.\n%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET ); return ( 0X01 ); }
	fprintf( stderr, "%s[+] Entry point found 0x%lx%s\n", ANSI_COLOR_GREEN, hdr->e_entry, ANSI_COLOR_RESET);
	
	if ( hdr->e_phoff == 0X00 ) { fprintf( stderr, "%s[-] No programm header.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET ); return ( 0X01 ); }
	fprintf( stderr, "%s[+] Program header found.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
	
	if ( hdr->e_phnum == 0X00 ) { fprintf( stderr, "\t%s[-] Number of invalid entries in the program header table.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET ); return ( 0X01 ); }
	fprintf( stderr, "\t%s[+] Number of program headers: %hu\n%s", ANSI_COLOR_GREEN, hdr->e_phnum, ANSI_COLOR_RESET);
	return ( 0X00 );
}


static uint8_t
__sy_get_phdr( t_elf *elf )
{
	elf->phdr_EXEC = (Elf64_Phdr **)malloc( elf->hdr.e_phnum * sizeof( Elf64_Phdr * ) );
	if ( elf->phdr_EXEC == NULL )
		return ( 0X01 );

	Elf64_Phdr	*tmp = ( Elf64_Phdr *)( elf->ptr+elf->hdr.e_phoff );
	for ( uint16_t i = 0X00; i < elf->hdr.e_phnum; i++, ++tmp )
	{
		elf->phdr_EXEC[ i ] = malloc( sizeof( Elf64_Phdr ));
		if ( elf->phdr_EXEC[ i ] == NULL )
			return ( 0X01 );
		memmove( elf->phdr_EXEC[ i ], tmp, sizeof(Elf64_Phdr ));
		if ( elf->phdr_EXEC[ i ]->p_flags & PF_X && ( elf->text->sh_addr >= elf->phdr_EXEC[ i ]->p_offset && elf->text->sh_addr < elf->phdr_EXEC[ i ]->p_offset + elf->phdr_EXEC[ i ]->p_memsz ) )
			elf->index = ( i );
	}
	return ( elf->index == 0 ? 0X01 : 0X00 );
}

static int
__SY_analyze( t_elf *elf, t__sy_binary *data )
{

	int	size_stub = 0X00;
	
	elf->stub = malloc( __ALIGN_MASK(getpagesize(), sizeof( handler_x64 ) ) * 32 );
	if ( elf->stub == NULL )
		return fprintf(stderr, "%s[-] Memory allocation error.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);

	if ( ! memcmp( elf->ptr, ELFMAG, SELFMAG ) ) {
		char    *ptr = elf->ptr;
		fprintf( stderr, "%s[+] The file type is supported. - (%s) %s\n", ANSI_COLOR_GREEN, ptr, ANSI_COLOR_RESET);
		switch( ptr[EI_CLASS] )
		{
			case ELFCLASS32:
				fprintf( stderr, "%s[+] The %s binary architecture is supported. - (%s) %s\n", ANSI_COLOR_GREEN, elf->filename, "Intel 80386", ANSI_COLOR_RESET);
				return ( 0X00 );
			case ELFCLASS64:
				fprintf( stderr, "%s[+] The %s binary architecture is supported. - (%s) %s\n", ANSI_COLOR_GREEN, elf->filename, "x86-64", ANSI_COLOR_RESET);
				
				if ( _check_header_ELFx64( elf->ptr ) )
					return ( 0X01 );

				/* ** Save header ELF ** */
				memmove( &elf->hdr, ptr, sizeof( Elf64_Ehdr ) );
				
				/* ** Get the .text, .symtab and .strtab sections ** */
				/* ** /!\ If the .text section cannot be obtained, we give up. ** */
				if ( __GET_sect( elf ) != 0X00 ) {
					return ( 0X01 );
				}

				/* ** Save phdr headers ** */
				if ( __sy_get_phdr( elf ) ) 
					return ( 0X01 );
			

				size_t	size = 0X00, size_stub_without_data = 0X00;

				if ( data->opts & 0X80 ) // Apply-inner-encryption option enabled
				{
					if ( elf->symtab == NULL )
					{
						fprintf( stderr, "%s[*] Internal encryption cannot be applied. Symbols are not available\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
						goto L1;
					}
					size = 0X3CC;
					size_stub_without_data = size;
					elf->size_stub = size;
					__sy_set_payload( elf->stub, &size, 0X00 );
					( void )apply_inner_encryption( elf, data->bypass_fcts );
					size = elf->size_stub;
				}
				else	// Apply-inner-encryption option disabled
				{
					L1:
					size = 351;
					memcpy( elf->stub, handler_x64_2, size );
					elf->size_stub = size;
					size_stub_without_data = size;	
				}

				if ( syfer_silvio_cesare_text_infection( elf, &size, &size_stub_without_data ) )
					return fprintf( stderr, "%s[-] An error occurred, syfer can't wrap the binary.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				__sy_create_file( elf->ptr, elf->sy_binary->out_binary_name, &size );
				return ( 0X00 );
			default:
				fprintf( stderr, "%s[-] The %s binary architecture is not supported%s\n", ANSI_COLOR_RED, elf->filename, ANSI_COLOR_RESET);
				break;
		}
	}
	return fprintf( stderr, "%s[-] The file type is not supported.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
}

int
syfer( t__sy_binary *data ) {

    /*
     ** Verification that the file has read rights.
     */
    if ( access( data->binary_name, R_OK ) != 0X00 )
        return fprintf( stderr, "%s[-] %s: Permission denied.%s\n", ANSI_COLOR_RED, data->binary_name, ANSI_COLOR_RESET);

    /*
     ** Get the binary size.
     */
    struct stat sb = {0x00};
    if ( lstat( data->binary_name, &sb ) == -1)
        fprintf( stderr, "%s lstat: %s%s", ANSI_COLOR_RED,  strerror(errno), ANSI_COLOR_RESET);

    /*
     ** Memory allocation of the elf structure.
     */
    t_elf *elf = calloc( sizeof( char ), sizeof( *elf ) );
    if ( elf == NULL )
        return fprintf(stderr, "%s[-] A memory allocation error occurred during the memory allocation of the \"t_elf\" structure.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    fprintf(stderr, "\n%s[+] Successful memory allocation of the \"t_elf\" structure.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);

    /*
     ** Allocation of a memory page that will contain the binary.
     */
    elf->ptr = mmap( NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0 );
    if ( elf->ptr == MAP_FAILED ) {
        free( elf );
        return fprintf( stderr, "%s[-] The allocation of the memory page has failed. Errno: %s%s\n", ANSI_COLOR_RED, strerror(errno), ANSI_COLOR_RESET);
    }
    fprintf( stderr, "%s[+] Successful allocation of a %ld bytes a memory page.%s\n", ANSI_COLOR_GREEN, sb.st_size, ANSI_COLOR_RESET);

    /*
     ** Copy the data from the bynary into a memory page.
     */
    if ( __SY_copy_mem(data->binary_name, elf->ptr, sb.st_size ) ) {
        munmap( elf->ptr, elf->filesize );
        free( elf );
        return ( 0x01 );
    }
    elf->filesize = sb.st_size;
    elf->filename = data->binary_name;
    elf->sy_binary = data;

    /*
     ** Checking the file type.
     ** Check if the file is an ELF Format.
     */
    if ( __SY_analyze( elf, data ) == 0X00 ) {
    
    }

    munmap( elf->ptr, elf->filesize );
    free( elf->stub );
    free( elf );
    return ( 0x00 );
}
