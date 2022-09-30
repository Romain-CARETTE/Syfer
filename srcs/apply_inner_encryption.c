#include "../include/main.h"
#define DYN_PROG_BASE_ADDR 0x800000000ULL
uint8_t firt_opcodes_symbol[] = { 0X55, 0X48, 0X89 };
/*
 * \fn const char *ELF_get_sym_name( t_elf *, const Elf64_Sym * )
 * \brief [ ... ]
 */
const char *ELF_get_sym_name( t_elf *elf, const Elf64_Sym *sym ) {
  return (const char *) (elf->ptr + elf->strtab->sh_offset + sym->st_name );
}

/*
 * \fn uint8_t	*ELF_get_sym_location( t_elf *, const Elf64_Sym * )
 * \brief [...]
 */
uint8_t	*ELF_get_sym_location( t_elf *elf, const Elf64_Sym *sym ) {
	
	Elf64_Ehdr	*header = (Elf64_Ehdr *)elf->ptr;
	Elf64_Phdr	*phdr = (Elf64_Phdr *)(elf->ptr+header->e_phoff);
	for( uint16_t i = 0X00; i < header->e_phnum; ++phdr, ++i )
	{
		if ( phdr->p_type != PT_LOAD )
			continue;
		if ( phdr->p_vaddr <= sym->st_value && (phdr->p_vaddr + phdr->p_memsz) > sym->st_value )
			return ( (void *) elf->ptr + ( phdr->p_offset + (sym->st_value - phdr->p_vaddr)));
	}
	return ( NULL );
}

/*
 * \fn ELF_sym_in_text( const t_elf *, const Elf64_Sym * )
 * \brief [...]
 */
int ELF_sym_in_text( const t_elf *elf, const Elf64_Sym *sym ) {
	return elf->text->sh_addr <= sym->st_value && (elf->text->sh_addr + elf->text->sh_size) > sym->st_value;
}

/*
 * \fn uint32_t	_count_symbols( t_elf * );
 * \brief [ ... ]
 */
uint32_t	_count_symbols( t_elf *elf ) {
	
	uint32_t	count = 0X00;
	Elf64_Shdr	*symtab = (Elf64_Shdr *)elf->symtab;
	for ( Elf64_Sym *__cursor = (Elf64_Sym *)( elf->ptr + symtab->sh_offset); (void *)__cursor < (void *)elf->ptr + symtab->sh_offset + elf->symtab->sh_size; __cursor++ ) {
		if ( ELF64_ST_TYPE( __cursor->st_info) == STT_FUNC )
			if ( ELF_sym_in_text( elf, __cursor) )
				++count;
	}
	return ( count );
}

void SY_xor(uint8_t *str_in, uint32_t length, uint8_t *key ) {

	for( uint32_t i = 0X00; i < length; i++ ) {
		str_in[i] = ( str_in[i] ^ key[ i % (sizeof( key )/ sizeof( char )) ] );
	}
}

void
___MH_debug_st( INSTRUX ix ) {
        char    instruction[ND_MIN_BUF_SIZE];
        NdToText(&ix, 0, ND_MIN_BUF_SIZE, instruction);
        fprintf(stderr, "%s\n", instruction);
}

uint8_t	_find_RET( uint8_t *addr, size_t size ) {

	return ( 0X01 );
}

size_t	_search_position( uint8_t *addr, size_t size ) {

	INSTRUX	ix = { 0X00 };
	for( size_t i = 0X00; i < size; i+= ix.Length) {
		NDSTATUS status = NdDecodeEx( &ix, addr+i, size, ND_CODE_64, ND_DATA_64);
		if ( ! ND_SUCCESS(status) )
			return ( -1 );
		if ( i + ix.Length >= size-3 ) {
			//___MH_debug_st( ix );

			if ( _find_RET( addr, size ) )
				return ( -1 );
			return ( i );
		}
	}
end:
	return ( -1 );
}



void modify_stub_to_apply_internal_encryption( t_elf *elf, size_t *size_stub_without_data ) {

}

void	apply_inner_encryption( t_elf *elf ) {
	assert( elf !=  NULL );

	uint32_t	count = _count_symbols( elf );
	if ( count == 0X00 )
		return ;
	
	fprintf( stderr, "%s[*] Application of internal encryption on symbols.%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
	fprintf( stderr, "%s[*] Number of symbols: %u%s\n", ANSI_COLOR_BLUE, count, ANSI_COLOR_RESET);

	Elf64_Shdr	*symtab = (Elf64_Shdr *)elf->symtab;

	elf->stub = realloc( elf->stub, __ALIGN_MASK(getpagesize(), elf->size_stub ) + ( count * sizeof( struct __symbol )) );
	assert( elf->stub != NULL );

	uint16_t	position = 0X00;
	for ( Elf64_Sym *__cursor = (Elf64_Sym *)( elf->ptr + symtab->sh_offset); (void *)__cursor < (void *)elf->ptr + symtab->sh_offset + elf->symtab->sh_size; __cursor++ ) {
		if ( ELF64_ST_TYPE( __cursor->st_info) == STT_FUNC )
		{
			if ( ELF_sym_in_text( elf, __cursor) )
			{
				struct __symbol sym = { 0X00 };
				uint8_t *addr = ELF_get_sym_location( elf, __cursor );
				if ( addr == NULL || memcmp( addr, firt_opcodes_symbol, 0X03 ) != 0X00 )
					continue;
				
				printf("%x --- %s --- Position: %.2x ---- %.2x\n", __cursor->st_size-3, ELF_get_sym_name( elf, __cursor ), position, *addr );				
				*addr = INT3;

				sym.st_size = (__cursor->st_size-3);
				sym.id = position;
				do { }while(syscall( SYS_getrandom, sym.key, 0X08, GRND_NONBLOCK )  == -1 );
				for( int i = 0X00; i < 8; i++)
						printf("%.2x ", sym.key[ i ]);
				printf("\n");
		
				SY_xor( (addr+3),  (__cursor->st_size - 3), sym.key );

				memcpy( &elf->stub[  elf->size_stub ], &sym, sizeof( struct __symbol ));

				elf->size_stub += sizeof( struct __symbol );
				memmove( addr + 0X01, &position, sizeof( uint16_t ));
				printf("Position: %d\n", position);	
				position = (position + 1);
			}
		}
	}
}
