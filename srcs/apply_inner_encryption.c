#include "../include/main.h"
#define DYN_PROG_BASE_ADDR 0x800000000ULL
uint8_t opcode[] = { 0X55, 0X48, 0X89 };
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
		if ( ELF64_ST_TYPE( __cursor->st_info) == STT_FUNC && ELF_sym_in_text( elf, __cursor) )
				++count;
	}
	return ( count );
}

void SY_xor(uint8_t *str_in, uint32_t length, uint8_t *key ) {

	for( uint32_t i = 0X00; i < length; i++ )
	{
		str_in[i] = ( str_in[i] ^ key[ i % (sizeof( key )/ sizeof( char )) ] );
	}
}

void
___MH_debug_st( INSTRUX ix ) {
        char    instruction[ND_MIN_BUF_SIZE];
        NdToText(&ix, 0, ND_MIN_BUF_SIZE, instruction);
        fprintf(stderr, "%s\n", instruction);
}

uint8_t		cmp_fcts( const char *fct, char **lst_fcts )
{
	int i = -1;
	while ( lst_fcts[ ++i ] != NULL ) {
		if ( strcmp( lst_fcts[ i ], fct ) == 0X00 ) {
			sleep(1);
			return ( 0X01 );
		}
	}
	return ( 0X00 );
}


void	apply_inner_encryption( t_elf *elf, char **fcts ) {
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
	fprintf( stderr, "\t%s* THIS FEATURE ENCRYPT AND DECRYPT THE SYMBOLS IN MEMORY AND ENCRYPT THEM AGAIN AT THE END OF THE FUNCTION.\n\t* THIS SLOWS DOWN THE EXECUTION TIME CONSIDERABLY, BUT THIS ALLOWS YOU TO HAVE VERY FEW PLAINTEXT FUNCTIONS IN MEMORY AT THE SAME TIME.\n\t* IF ONE OF YOUR SYMBOLS IS A RECURSIVE FUNCTION, THE BEHAVIOR IS UNDEFINED.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
	for ( Elf64_Sym *__cursor = (Elf64_Sym *)( elf->ptr + symtab->sh_offset); (void *)__cursor < (void *)elf->ptr + symtab->sh_offset + elf->symtab->sh_size; __cursor++ )
	{
		if (  ELF_sym_in_text( elf, __cursor ) )
		{
			struct __symbol sym = { 0X00 };
			uint8_t *addr = ELF_get_sym_location( elf, __cursor );
			if ( addr == NULL || memcmp( addr, opcode, 0X03 ) != 0X00 || *(addr+__cursor->st_size-1) != 0XC3 )
				continue;
			if ( cmp_fcts( ELF_get_sym_name( elf, __cursor ), fcts ) )
				continue;
			
			*addr = INT3;
			
			sym.st_size = (__cursor->st_size-3);
			sym.id = position;
			do { }while(syscall( SYS_getrandom, sym.key, 0X08, GRND_NONBLOCK )  == -1 );

		
			SY_xor( (addr+3),  (__cursor->st_size - 4), sym.key );

			memcpy( &elf->stub[  elf->size_stub ], &sym, sizeof( struct __symbol ));

			elf->size_stub += sizeof( struct __symbol );
			memmove( addr + 0X01, &position, sizeof( uint16_t ));
			position = (position + 1);

			fprintf( stderr, "\t%s[*] encrypting function %s with key ", ANSI_COLOR_GREEN, ELF_get_sym_name( elf, __cursor));
			for( uint8_t j = 0X00; j < 0X08; ++j)
				fprintf( stderr, "0X%.2X ", sym.key[ j ]);
			fprintf( stderr, "%s\n", ANSI_COLOR_RESET);
		}
	}
}
