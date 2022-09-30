#include "../include/main.h"
unsigned char stub[] = {
  0x4c, 0x8d, 0x3d, 0x0c, 0x00, 0x00, 0x00, 0x4c, 0x8d, 0x35, 0x23, 0x01,
  0x00, 0x00, 0xe9, 0x95, 0x01, 0x00, 0x00, 0x48, 0x89, 0xe7, 0x48, 0x81,
  0xc7, 0xb0, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3f, 0x57, 0x41, 0xba, 0x07,
  0x00, 0x00, 0x00, 0xe8, 0xc9, 0x00, 0x00, 0x00, 0x5f, 0x48, 0x89, 0xe7,
  0x48, 0x81, 0xc7, 0xb0, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x3f, 0x48, 0x31,
  0xd2, 0x48, 0x31, 0xc0, 0xb8, 0x1b, 0x00, 0x00, 0x00, 0x66, 0x8b, 0x17,
  0x48, 0xf7, 0xe2, 0x48, 0x8d, 0x35, 0x60, 0x02, 0x00, 0x00, 0x48, 0x8b,
  0x36, 0x48, 0x01, 0xc6, 0x48, 0x83, 0xc7, 0x02, 0x55, 0x48, 0x89, 0xe5,
  0x48, 0x83, 0xec, 0x70, 0x48, 0x89, 0xf0, 0x48, 0x31, 0xf6, 0x48, 0x8b,
  0x70, 0x03, 0x48, 0x89, 0xc2, 0x48, 0x83, 0xc2, 0x13, 0xe8, 0x24, 0x00,
  0x00, 0x00, 0x48, 0x83, 0xc4, 0x70, 0x5d, 0x48, 0x83, 0xef, 0x03, 0xc6,
  0x07, 0x55, 0xc6, 0x47, 0x01, 0x48, 0xc6, 0x47, 0x02, 0x89, 0x48, 0x89,
  0xbc, 0x24, 0xb0, 0x00, 0x00, 0x00, 0xeb, 0x00, 0xe8, 0x9b, 0x00, 0x00,
  0x00, 0xc3, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x89, 0x7d, 0xf8, 0x89, 0x75,
  0xf4, 0x48, 0x89, 0x55, 0xe8, 0xc7, 0x45, 0xe4, 0x00, 0x00, 0x00, 0x00,
  0x8b, 0x45, 0xe4, 0x3b, 0x45, 0xf4, 0x73, 0x37, 0x48, 0x8b, 0x45, 0xf8,
  0x8b, 0x4d, 0xe4, 0x89, 0xca, 0x0f, 0xb6, 0x0c, 0x10, 0x48, 0x8b, 0x45,
  0xe8, 0x8b, 0x75, 0xe4, 0x89, 0xf2, 0x48, 0x83, 0xe2, 0x07, 0x0f, 0xb6,
  0x34, 0x10, 0x31, 0xf1, 0x48, 0x8b, 0x45, 0xf8, 0x8b, 0x75, 0xe4, 0x89,
  0xf2, 0x88, 0x0c, 0x10, 0x8b, 0x45, 0xe4, 0x83, 0xc0, 0x01, 0x89, 0x45,
  0xe4, 0xeb, 0xc1, 0x5d, 0xc3, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec,
  0x10, 0x48, 0x89, 0xf8, 0x48, 0x89, 0x45, 0xf0, 0xba, 0x00, 0x20, 0x00,
  0x00, 0x48, 0x63, 0xca, 0x48, 0x31, 0xd2, 0x48, 0xf7, 0xf1, 0x48, 0x89,
  0xd0, 0x48, 0xf7, 0xd8, 0x48, 0x01, 0x45, 0xf0, 0x48, 0x8b, 0x7d, 0xf0,
  0xbe, 0x00, 0x20, 0x00, 0x00, 0x4c, 0x89, 0xd2, 0xb8, 0x0a, 0x00, 0x00,
  0x00, 0x0f, 0x05, 0xc9, 0xc3, 0xb8, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x05,
  0xe8, 0x12, 0x00, 0x00, 0x00, 0x2e, 0x2e, 0x2e, 0x45, 0x6e, 0x64, 0x20,
  0x68, 0x61, 0x6e, 0x64, 0x6c, 0x65, 0x72, 0x2e, 0x2e, 0x2e, 0x0a, 0xbf,
  0x01, 0x00, 0x00, 0x00, 0x5e, 0xba, 0x12, 0x00, 0x00, 0x00, 0xb8, 0x01,
  0x00, 0x00, 0x00, 0x0f, 0x05, 0xc3, 0xe8, 0x0c, 0x00, 0x00, 0x00, 0x2e,
  0x2e, 0x2e, 0x53, 0x79, 0x66, 0x65, 0x72, 0x2e, 0x2e, 0x2e, 0x0a, 0xbf,
  0x01, 0x00, 0x00, 0x00, 0x5e, 0xba, 0x0c, 0x00, 0x00, 0x00, 0xb8, 0x01,
  0x00, 0x00, 0x00, 0x0f, 0x05, 0xc3, 0x48, 0x8d, 0x3d, 0x73, 0xfe, 0xff,
  0xff, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
  0xf9, 0xf9, 0xf9, 0xba, 0x07, 0x00, 0x00, 0x00, 0xb8, 0x0a, 0x00, 0x00,
  0x00, 0x0f, 0x05, 0xc3, 0x50, 0x51, 0x53, 0x52, 0x57, 0x56, 0x48, 0x8b,
  0x7c, 0x24, 0x38, 0xbe, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x02, 0x00, 0x00,
  0x00, 0x0f, 0x05, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x83, 0xec, 0x10, 0x48,
  0x89, 0x04, 0x24, 0x48, 0x89, 0xc7, 0xb8, 0x08, 0x00, 0x00, 0x00, 0xfc,
  0xfc, 0xfc, 0xfc, 0xfc, 0xba, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xb8,
  0x09, 0x00, 0x00, 0x00, 0x48, 0x31, 0xff, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
  0xba, 0x03, 0x00, 0x00, 0x00, 0x41, 0xba, 0x22, 0x00, 0x00, 0x00, 0x49,
  0xc7, 0xc0, 0xff, 0xff, 0xff, 0xff, 0x4d, 0x31, 0xc9, 0x0f, 0x05, 0x48,
  0x89, 0x44, 0x24, 0x08, 0x48, 0x8b, 0x3c, 0x24, 0x48, 0x8b, 0x74, 0x24,
  0x08, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x0f,
  0x05, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x48, 0x8b, 0x04, 0x24, 0xb9, 0x00,
  0x20, 0x00, 0x00, 0xba, 0x00, 0x00, 0x00, 0x00, 0x48, 0xf7, 0xf1, 0x48,
  0x89, 0xd0, 0x48, 0xf7, 0xd8, 0x48, 0x01, 0x04, 0x24, 0x5f, 0xbe, 0x00,
  0x20, 0x00, 0x00, 0xba, 0x07, 0x00, 0x00, 0x00, 0xb8, 0x0a, 0x00, 0x00,
  0x00, 0x0f, 0x05, 0x48, 0x8d, 0x1d, 0x5c, 0x00, 0x00, 0x00, 0x48, 0x8b,
  0x54, 0x24, 0x08, 0x48, 0x89, 0x13, 0xba, 0x05, 0x00, 0x00, 0x00, 0xb8,
  0x0a, 0x00, 0x00, 0x00, 0x0f, 0x05, 0x48, 0x83, 0xc4, 0x10, 0x5d, 0xe8,
  0xee, 0xfe, 0xff, 0xff, 0x55, 0x48, 0x89, 0xe5, 0x48, 0x81, 0xec, 0x00,
  0x02, 0x00, 0x00, 0x4c, 0x89, 0x3c, 0x24, 0x48, 0xc7, 0x44, 0x24, 0x08,
  0x00, 0x00, 0x00, 0x04, 0x4c, 0x89, 0x74, 0x24, 0x10, 0xb8, 0x0d, 0x00,
  0x00, 0x00, 0xbf, 0x05, 0x00, 0x00, 0x00, 0x48, 0x89, 0xe6, 0x48, 0x31,
  0xd2, 0x41, 0xba, 0x08, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xc9, 0x5e, 0x5f,
  0x5a, 0x5b, 0x59, 0x58, 0xeb, 0x08, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0x90, 0x90, 0x90, 0x90, 0x90
};

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

	printf("%ld\n", size_data );
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
	uint8_t *data = __MH_mov_reg32_imm32( NDR_RSI, OLD_exec_seg->p_offset +OLD_exec_seg->p_filesz+*stub_size_whitout_data, &size_data );
	assert( data != NULL );
	SYFER_set_mov( stub, *size_stub, data, size_data );
	free( data );
	
	size_data = 0X00;
	size_t stub_size_data = ( *size_stub - *stub_size_whitout_data );
	data = __MH_mov_reg32_imm32( NDR_RSI, stub_size_data, &size_data );
	assert( data != NULL );
	SYFER_set_mov( stub, *size_stub, data, size_data );
	free( data );

	size_data = 0X00;
	data = __MH_mov_reg32_imm32( NDR_RDX, stub_size_data, &size_data );
	assert( data != NULL );
	SYFER_set_mov( stub, *size_stub, data, size_data );
	free( data );
}

int			syfer_silvio_cesare_text_infection( char *ptr, size_t filesize, uint8_t *st, size_t *size_stub, size_t *stub_size_whitout_data )
{
	Elf64_Ehdr	*hdr = ( Elf64_Ehdr *)ptr;
	Elf64_Phdr	*phdr_EXEC = get_pload_EXEC(ptr, hdr);
	Elf64_Phdr	*phdr_NOT_EXEC = ( phdr_EXEC+1 );

	uint64_t	padding = __ALIGN_MASK( getpagesize(), *size_stub );
	Elf64_Phdr	OLD_exec_seg = { 0X00 }, OLD_next_seg = { 0X00 };
	Elf64_Ehdr	header = { 0X00 };
	memmove( &OLD_exec_seg, phdr_EXEC, sizeof( Elf64_Phdr ));
	memmove( &OLD_next_seg, phdr_NOT_EXEC, sizeof( Elf64_Phdr));
	memmove( &header, hdr, sizeof( Elf64_Ehdr));

	int fd = open("woody", O_CREAT | O_RDWR | O_TRUNC, 0755);
	if ( fd == -1 )
		return ( 1 );
	
	set_phdr_offset((void *)(ptr + hdr->e_phoff), phdr_EXEC->p_offset + phdr_EXEC->p_filesz,hdr->e_phnum, padding);
	set_shdr_offset((void *)(ptr + hdr->e_shoff), phdr_EXEC->p_offset + phdr_EXEC->p_filesz,hdr->e_shnum, padding);
	hdr->e_shoff += padding;
	phdr_EXEC->p_memsz += *size_stub;
	phdr_EXEC->p_filesz += *size_stub;

	hdr->e_entry = ( OLD_exec_seg.p_vaddr + OLD_exec_seg.p_filesz );
				
	write( fd, ptr, OLD_next_seg.p_offset );
	uint8_t	pad[0X1000] = {0} ;
	for ( int i = 0X00; i < padding; i+= 0X1000 )
		write( fd, pad, 0X1000 );
	write( fd, ptr + OLD_next_seg.p_offset, filesize - OLD_exec_seg.p_offset );

	( void )modify_stub_to_apply_internal_encryption( st, size_stub, &OLD_exec_seg, stub_size_whitout_data );
				
	int addr_jmp = header.e_entry - (hdr->e_entry + *stub_size_whitout_data);
	SYFER_set_jmp( st, &addr_jmp, *size_stub );
	lseek(fd, OLD_exec_seg.p_offset + OLD_exec_seg.p_filesz, SEEK_SET);
	write(fd, st, *size_stub);
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

	int	size_stub = 0X00;
	
	elf->stub = malloc( __ALIGN_MASK(getpagesize(), sizeof( stub ) ) * 32 );
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
				
				elf->size_stub = 703;
				size_t size_stub_without_data = elf->size_stub;
				memcpy( elf->stub, stub, elf->size_stub );
				elf->tmp = elf->size_stub;

				/* ** Get the .text, .symtab and .strtab sections ** */
				/* ** /!\ If the .text section cannot be obtained, we give up. ** */
				if ( __GET_sect( elf ) != 0X00 )
					return ( 0X01 );
				Elf64_Shdr	*symtab = (Elf64_Shdr *)elf->symtab;
				if ( symtab == NULL )
					fprintf( stderr, "%s[*] Internal encryption cannot be applied.\n%s", ANSI_COLOR_RED, ANSI_COLOR_RESET);
				else
				{
					( void )apply_inner_encryption( elf );
				}

				( void )apply_global_encryption( elf );

				size_t	size = elf->size_stub;
				elf->text->sh_size += size;
				syfer_silvio_cesare_text_infection( elf->ptr, elf->filesize, elf->stub, &size, &size_stub_without_data );

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
