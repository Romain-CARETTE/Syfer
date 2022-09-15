#include "../include/main.h"

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

static inline void set_payload(t_elf const *elf)
{
	Elf64_Addr const entry_point = elf->old_entrypoint - (elf->segment_addr + elf->segment_size) - elf->size_stub;

	elf->stub[ elf->size_stub - ( sizeof( int ) + 1) ] = 0XE9;
	memcpy(&elf->stub[elf->size_stub -  sizeof( int ) ], &entry_point, sizeof(int));
}

static void write_on_memory(t_elf const *elf, char *ptr)
{
	Elf64_Off const beg_encrypt = elf->section_offset + (elf->old_entrypoint - elf->section_addr);
	Elf64_Off const end_encrypt = elf->section_offset + elf->section_size;
	Elf64_Off const beg_payload = elf->segment_offset + elf->segment_size;
	Elf64_Off const end_payload = elf->segment_offset + elf->segment_size + __ALIGN_MASK( getpagesize(), elf->size_stub + elf->n );
	Elf64_Off const end_file = elf->filesize + __ALIGN_MASK( getpagesize(), elf->size_stub + elf->n  );

	size_t index = 0;
	char *dst = ptr;
	char *src = elf->ptr;

	while (index < beg_payload)
	{
		*dst++ = *src++;
		index++;
	}
	while (index < end_payload)
	{
		*dst++ = 0;
		index++;
	}
	while (index < end_file)
	{
		*dst++ = *src++;
		index++;
	}

	memcpy(ptr + beg_payload, elf->stub, elf->size_stub + elf->n);
	//_rc4(key, _strlen((char *)key), ptr + beg_encrypt, end_encrypt - beg_encrypt);
}

////////////////////////////////////////////////////////////////////////////////
/// PUBLIC FUNCTION
////////////////////////////////////////////////////////////////////////////////

void create_infected(t_elf const *elf ) {

	char *ptr = NULL;
	if ((ptr = mmap(NULL, elf->filesize + __ALIGN_MASK( getpagesize(), elf->size_stub + elf->n ), PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		error(MMAP_FAIL, NULL, __LINE__);

	set_payload( elf );
	write_on_memory( elf, ptr );
	
	char filename[ PATH_MAX ] = { 0x00 }, hash[ SHA256_DIGEST_LENGTH * 2 + 1 ] = { 0x00 };
	SY_sha256( ptr, elf->filesize + __ALIGN_MASK( getpagesize(), elf->size_stub+elf->n ), hash );
	sprintf( filename, "OUT_bin/%s.%s", elf->sy_binary->out_binary_name, hash );

	int fd = 0;
	if ((fd = open( filename, O_RDWR | O_CREAT | O_TRUNC, 0700 )) == -1)
		error(WRONG_FD, filename, __LINE__); 


	write( fd, ptr, elf->filesize + __ALIGN_MASK( getpagesize(), elf->size_stub + elf->n ) );

	munmap(ptr, elf->filesize + __ALIGN_MASK( getpagesize(), elf->size_stub+ elf->n ));
	close(fd);
}
