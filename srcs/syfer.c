#include "../include/main.h"

const uint8_t m[] = { 0xe8, 0x0c, 0x00, 0x00, 0x00, 0x2e, 0x2e, 0x2e, 0x53, 0x59, 0x46, 0x45, 0x52, 0x2e, 0x2e, 0x2e, 0x0a };

uint8_t payloads[] = {
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90, 0X90,
  0x57, 0x56, 0x52, 0x51, 0x50, 0x53, 0xe8, 0x0d, 0x00, 0x00, 0x00, 0x2e,
  0x2e, 0x2e, 0x50, 0x45, 0x47, 0x41, 0x53, 0x59, 0x2e, 0x2e, 0x2e, 0x0a,
  0xbf, 0x01, 0x00, 0x00, 0x00, 0x5e, 0xba, 0x0d, 0x00, 0x00, 0x00, 0xb8,
  0x01, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x5b, 0x58, 0x59, 0x5a, 0x5e, 0x5f,
  0xe9, 0x90, 0x90, 0x90, 0x90
};

unsigned char mprotects[] = {
  0xe8, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x24, 0xb9, 0x00, 0x10,
  0x00, 0x00, 0xba, 0x00, 0x00, 0x00, 0x00, 0x48, 0xf7, 0xf1, 0x48, 0x89,
  0xd0, 0x48, 0xf7, 0xd8, 0x48, 0x01, 0x04, 0x24, 0x5f, 0xbe, 0x00, 0x10,
  0x00, 0x00, 0xba, 0x07, 0x00, 0x00, 0x00, 0xb8, 0x0a, 0x00, 0x00, 0x00,
  0x0f, 0x05, 0xe9, 0x90, 0x90, 0x90, 0x90
};
unsigned char stub[] = {
  0x4c, 0x8d, 0x3d, 0x0c, 0x00, 0x00, 0x00, 0x4c, 0x8d, 0x35, 0x7f, 0x00,
  0x00, 0x00, 0xe9, 0xab, 0x00, 0x00, 0x00, 0x48, 0x89, 0xe7, 0x48, 0x81,
  0xc7, 0xb0, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3f, 0x57, 0x41, 0xba, 0x07,
  0x00, 0x00, 0x00, 0xe8, 0x25, 0x00, 0x00, 0x00, 0x5f, 0x48, 0x89, 0xe7,
  0x48, 0x81, 0xc7, 0xb0, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3f, 0x48, 0x83,
  0xef, 0x01, 0xc6, 0x07, 0x55, 0x48, 0x89, 0xbc, 0x24, 0xb0, 0x00, 0x00,
  0x00, 0xeb, 0x00, 0xe8, 0x44, 0x00, 0x00, 0x00, 0xc3, 0x55, 0x48, 0x89,
  0xe5, 0x48, 0x83, 0xec, 0x10, 0x48, 0x89, 0xf8, 0x48, 0x89, 0x45, 0xf0,
  0xba, 0x00, 0x10, 0x00, 0x00, 0x48, 0x63, 0xca, 0x48, 0x31, 0xd2, 0x48,
  0xf7, 0xf1, 0x48, 0x89, 0xd0, 0x48, 0xf7, 0xd8, 0x48, 0x01, 0x45, 0xf0,
  0x48, 0x8b, 0x7d, 0xf0, 0xbe, 0x00, 0x10, 0x00, 0x00, 0x4c, 0x89, 0xd2,
  0xb8, 0x0a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc9, 0xc3, 0xb8, 0x0f, 0x00,
  0x00, 0x00, 0x0f, 0x05, 0xe8, 0x12, 0x00, 0x00, 0x00, 0x2e, 0x2e, 0x2e,
  0x45, 0x6e, 0x64, 0x20, 0x68, 0x61, 0x6e, 0x64, 0x6c, 0x65, 0x72, 0x2e,
  0x2e, 0x2e, 0x0a, 0xbf, 0x01, 0x00, 0x00, 0x00, 0x5e, 0xba, 0x12, 0x00,
  0x00, 0x00, 0xb8, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc3, 0x50, 0x51,
  0x53, 0x52, 0x57, 0x56, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x81, 0xec, 0x00,
  0x02, 0x00, 0x00, 0x4c, 0x89, 0x3c, 0x24, 0x48, 0xc7, 0x44, 0x24, 0x08,
  0x00, 0x00, 0x00, 0x04, 0x4c, 0x89, 0x74, 0x24, 0x10, 0xb8, 0x0d, 0x00,
  0x00, 0x00, 0xbf, 0x05, 0x00, 0x00, 0x00, 0x48, 0x89, 0xe6, 0x48, 0x31,
  0xd2, 0x41, 0xba, 0x08, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc9, 0x5e, 0x5f,
  0x5a, 0x5b, 0x59, 0x58, 0xeb, 0x04, 0xff, 0xff, 0xff, 0xff, 0x90, 0x90,
  0x90, 0x90, 0x90
};



static void		inject_symbols_informations( t_elf *elf, t_list *lst_symbol, uint32_t *nb ) {
	
	assert( elf != NULL && elf->stub != NULL );

	memcpy( elf->stub, stub, sizeof( stub ) );

	struct __symbol *sym = NULL;
	struct __functions *f = NULL;
	t_list	*lst = lst_symbol;
	uint32_t i = sizeof(stub);

	while( lst->next )
		lst = lst->next;
	
	while ( lst ) {
		f = (struct __functions *)lst->content;
		sym = ( struct __symbol *)&f->sym;
		memmove( &elf->stub[ i ], sym, sizeof( struct __symbol ));
		i += sizeof( struct __symbol );
		lst = lst->prev;
	}
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
		fprintf( stderr, "%s[*] The .strtab section was not found - (Binary is stripped)\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET );
	else
		fprintf( stderr, "%s[*] The .strtab section was found at %s[%p]%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_YELLOW, elf->ptr+elf->strtab->sh_offset, ANSI_COLOR_RESET);

	elf->symtab = __GET_shdr( elf->ptr, header, ".symtab" );
	if ( elf->symtab == NULL )
		fprintf( stderr, "%s[*] The .symtab section was not found - (Binary is stripped)\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET );
	else
		fprintf( stderr, "%s[*] The .symtab section was found at %s[%p]%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_YELLOW, elf->ptr+elf->symtab->sh_offset, ANSI_COLOR_RESET);
			
	elf->text = __GET_shdr( elf->ptr, header, ".text" );
	if ( elf->text == NULL )
		return fprintf( stderr, "%s[*] The .text section was not found\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET );
	else
		fprintf( stderr, "%s[*] The .text section was found at %s[%p]%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_YELLOW, elf->ptr+elf->text->sh_offset, ANSI_COLOR_RESET);
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

static int
__SY_analyze( t_elf *elf ) {
	
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
				/* ** Get the .text, .symtab and .strtab sections ** */
				/* ** /!\ If the .text section cannot be obtained, we give up. ** */
				if ( __GET_sect( elf ) != 0X00 )
					return ( 0X01 );
				Elf64_Shdr	*symtab = (Elf64_Shdr *)elf->symtab;
				if ( symtab == NULL )
					fprintf( stderr, "%s[*] Internal encryption cannot be applied.\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				else
					( void )apply_inner_encryption( elf );

				elf->stub = malloc( __ALIGN_MASK(getpagesize(), sizeof( stub ) ));
				if ( elf->stub == NULL )
					return fprintf(stderr, "%s[-] Memory allocation error.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);

				printf("size: %ld %ld\n", elf->text->sh_size, sizeof( stub ));
				memcpy( elf->stub, stub, sizeof( stub ) );
				elf->size_stub = sizeof( stub );

				modify_segments( elf );
				modify_sections( elf );
				modify_header( elf );
				create_infected( elf );
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
    if ( __SY_analyze( elf ) == 0X00 ) {
    
    }

    munmap( elf->ptr, elf->filesize );
    free( elf->stub );
    free( elf );
    return ( 0x00 );
}
