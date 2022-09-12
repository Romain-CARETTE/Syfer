#include "../include/main.h"
#define DYN_PROG_BASE_ADDR 0x800000000ULL

unsigned char _stub_symbol[] = {
  0x41, 0x56, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xcc, 0x41, 0x5e, 0xeb,
  0xf3
};


int	get_position_nop( const uint8_t *stub ) {
	for( int i = 0; i < sizeof( _stub_symbol ); i++ )
		if ( stub[ i ] == 0X90 )
			return ( i );
	return ( -1 );
}

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
 * \fn uint32_t	_count_symbols( t_elf * );
 * \brief [ ... ]
 */
uint32_t	_count_symbols( t_elf *elf ) {
	
	uint32_t	count = 0X00;
	Elf64_Shdr	*symtab = (Elf64_Shdr *)elf->symtab;
	for ( Elf64_Sym *__cursor = (Elf64_Sym *)( elf->ptr + symtab->sh_offset); (void *)__cursor < (void *)elf->ptr + symtab->sh_offset + elf->symtab->sh_size; __cursor++ ) {
		if ( ELF64_ST_TYPE( __cursor->st_info) == STT_FUNC )
			if ( __cursor->st_size > sizeof(_stub_symbol )  )
				++count;
	}
	return ( count );
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

	printf("%ld\n", size);
	INSTRUX	ix = { 0X00 };
	for( size_t i = 0X00; i < size; i+= ix.Length) {
		NDSTATUS status = NdDecodeEx( &ix, addr+i, size, ND_CODE_64, ND_DATA_64);
		if ( ! ND_SUCCESS(status) )
			return ( -1 );
		if ( i + ix.Length >= size-3 ) {
			___MH_debug_st( ix );

			if ( _find_RET( addr, size ) )
				return ( -1 );
			return ( i );
		}
	}
end:
	return ( -1 );
}

t_list	*apply_inner_encryption( t_elf *elf, uint32_t *nb )
{
	assert( elf !=  NULL );

	uint32_t	count = _count_symbols( elf );
	if ( count == 0X00 )
		return ( NULL );
	uint32_t	byte = ( count * sizeof( struct __symbol ) );
	uint16_t	position = 0X00, ret = 0;

	Elf64_Shdr	*symtab = (Elf64_Shdr *)elf->symtab;

	t_list	*symbol_lst = NULL;
	for ( Elf64_Sym *__cursor = (Elf64_Sym *)( elf->ptr + symtab->sh_offset); (void *)__cursor < (void *)elf->ptr + symtab->sh_offset + elf->symtab->sh_size; __cursor++ ) {
		if ( ELF64_ST_TYPE( __cursor->st_info) == STT_FUNC )
		{
			t_list	*new = NULL;
			struct __functions	sys = { 0X00 }; 
			if ( __cursor->st_size >= sizeof( _stub_symbol )  )
			{
				(*nb) += sizeof( struct __symbol );
				sys.function_name = ELF_get_sym_name( elf, __cursor );
				
				uint8_t *addr = ELF_get_sym_location( elf, __cursor );
				size_t  pos = _search_position( addr, __cursor->st_size );
				if ( pos == -1 )
					continue;
				printf("%s\n", sys.function_name);
				*(addr+pos) = INT3;

				int ret = syscall( SYS_getrandom, sys.sym.key, 16, 0x0 );
				( void )_rc4( sys.sym.key, 16, (char *)addr, __cursor->st_size );
				
				memmove( sys.sym._backup_sym, addr, 3 );
				*addr = INT3;
				sys.sym.size_symbol = __cursor->st_size;
				memmove( addr+1, &position, sizeof( uint16_t ));
				sys.sym.id = position;
				position = (position + 1);
				
				t_list	*new = ft_lstnew( &sys, sizeof( struct __functions ) );
				( void )ft_lstadd( &symbol_lst, new );
			}
		}
	}
	return ( symbol_lst );
}
