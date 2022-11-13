#include "../include/main.h"


static void	__db_opcode( t_str *opcode )
{
	INSTRUX	ix = {0};
	NdDecodeEx( &ix, opcode->data, opcode->size, ND_CODE_64, ND_DATA_64);
	char	in[ ND_MIN_BUF_SIZE ] = { 0X00 };
	NdToText( &ix, 0, ND_MIN_BUF_SIZE, in );
	fprintf( stderr, "%s\n", in );
}

static void	__sy_debug_llist( t_list *llist )
{
	while ( llist )
	{
		t_str	*ass = llist->content;
		__db_opcode( ass );
		llist = llist->next;
	}
}

static void	__generate_push( t_list **lst )
{
	t_list	*list = *lst;
	while( list )
	{
		t_str *assembly = (t_str *)list->content;
		//__db_opcode( assembly );
		
		uint8_t	size = 0X00;
		uint8_t	*data = __mh_push_regX64( assembly->reg, &size );
		t_str opcode_push = { 0X00 };
		memmove( opcode_push.data, data, size );
		opcode_push.size = size;
		opcode_push.reg = assembly->reg;
		free( data );
		t_list *new = ft_lstnew( &opcode_push, sizeof( t_str ) );
		if ( list->next )
		{
			list->next->prev = new;
			new->next = list->next;
		}
		new->prev = list;
		list->next = new;

		list = list->next->next;
	}
}

char		**__sy_strsplit ( char *ptr, int *nb, char *sep ) {
	assert( ptr != NULL && nb != NULL && sep != NULL );

	char	**arr = 0X00;
	char *tmp = strdup( ptr );
	if ( ! tmp )
		goto __sy_strsplit_end;
	*nb = strsplit( tmp, NULL, 0, sep );
	free( tmp );
	if ( *nb <= 0X00 )
		goto __sy_strsplit_end;
	arr = calloc(sizeof(char *), *nb + 0X01 );
	if ( ! arr )
		goto __sy_strsplit_end;
	strsplit( ptr, arr, *nb, sep);
__sy_strsplit_end:
		return ( arr );
		
}

static t_list	*__sy_get_assembly( uint8_t *p, struct stat *sb ) {
	t_list	*llist = NULL;

	INSTRUX	ix = { 0X00 };
	for( size_t i = 0X00 ; i < sb->st_size; i+= ix.Length )
	{
		NDSTATUS status = NdDecodeEx( &ix, &p[i], sb->st_size, ND_CODE_64, ND_DATA_64);
		if ( ! ND_SUCCESS( status ) )
		{
			fprintf(stderr, "%s[-] Decoding failed with error 0x%08x ! %s\n", ANSI_COLOR_RED, status, ANSI_COLOR_RESET );
			( void ) ft_lstdel( &llist, 0X00 );
			goto __sy_get_assembly_error;

		}
		t_str	assembly = { 0X00 };
		memmove( assembly.data, p+i, ix.Length );
		assembly.size = ix.Length;
		t_list *new = ft_lstnew( &assembly, sizeof( t_str ) );
		if ( new == NULL )
		{
			// ** /!\ Error Malloc ** //
			fprintf( stderr, "%s An error occurred. Errno: (%s)%s", ANSI_COLOR_RED, strerror( errno), ANSI_COLOR_RESET);
			( void ) ft_lstdel( &llist, 0X00 );
			goto __sy_get_assembly_error;
			
		}
		( void )ft_push_back( &llist, new );
	}
__sy_get_assembly_error:
	return ( llist );
}

/*
 * \fn static uint8_t __sy_generate_mov_shell_cmd( t_list ** )
 * \brief [...]
 */
static uint8_t		__sy_generate_mov_shell_cmd( t_list **alst )
{
	uint8_t	size = 0X00;
	uint8_t	*data = __mh_mov_regX64_regX64( NDR_RDI, NDR_RSP, &size );
	if ( ! data )
		goto __sy_generate_assembly_shell_command_error;

	t_str	opcode = { 0X00 };
	memmove( opcode.data, data, size );
	opcode.size = size;
	opcode.reg = NDR_RDI;
	t_list *new = ft_lstnew( &opcode, sizeof( t_str ) );
	if ( ! new )
		goto __sy_generate_assembly_shell_command_error;
	( void )ft_push_back( alst, new );
	free( data );
	return ( 0X00 );
__sy_generate_assembly_shell_command_error:
					( data != NULL ) ? free( data ) : 0X00;
					return ( 0X01 );
}

t_list		*__sy_generate_assembly_shell_command( const char *cmd, size_t len, int *except, uint8_t nb ) {
	assert( cmd != NULL );

	uint8_t *data = 0X00;
	t_list	*list = NULL;
	char *tmp = strdup( cmd );
	if ( ! tmp )
		goto __sy_set_cmd_end;
	
	int i = 0X00;
	char temp[ 0X08 ] = { 0X00 };
	while ( len )
	{ 
		size_t mod = ( len % 0X08 );
		uint8_t size = 0X00;
		if ( mod == 0X00 )
			mod = 0X08;
		memmove( temp, &tmp[ len - mod ], 0X08 );

		// ** Randomize Registry ** //
		uint8_t reg = _random_except( 15, 0, except, nb );
		sleep( 0X01 );
		
		data = __mh_movabs_str( reg, &size, temp );
		if ( ! data )
		{
			if ( list )
				( void )ft_lstdel( &list, 0X00 );
			goto __sy_set_cmd_end;
		}

		t_str	opcode = { 0X00 };
		memmove( opcode.data, data, size );
		opcode.size = size;
		opcode.reg = reg;

		t_list *new = ft_lstnew( &opcode, sizeof( t_str ) );
		if ( ! new )
		{
			free( data );
			( void )ft_lstdel( &list, 0X00 );
			goto __sy_set_cmd_end;
		}
		( void )ft_lstadd( &list, new );
		len -= ( mod );
		free( data );
	}
__sy_set_cmd_end:
		( tmp != NULL ) ? free( tmp ) : 0X00;
		return ( list );
}


/*
 * \fn static t_list	*__sy_read_payload( const char *, size_t * )
 * \brief [ ... ]
 */
static t_list	*__sy_read_payload( const char *filename_payload, size_t *size ) {

	struct stat	sb = {0X00};
	uint8_t	*data = __rc_read_file( filename_payload, &sb );
	if ( data == NULL )
		goto __sy_get_assembly_error;
	
	t_list *lst_opcode = __sy_get_assembly( data, &sb );
	if ( lst_opcode == NULL )
		goto __sy_get_assembly_error;

	free( data );
	return ( lst_opcode );
__sy_get_assembly_error:
		( data != 0X00 ) ? free( data ) : 0X00;
		return ( 0X00 );
}

static void	__sy_need_zero( t_list **alst )
{

}

static void	__sy_splice( t_list **alst, t_list *lst, uint8_t count )
{
	INSTRUX	ix = {0};

	uint8_t nb = 0X00;
	t_list	*tmp = *alst;
	while ( tmp )
	{
		t_str	*ass = ( t_str *)tmp->content;
		NDSTATUS status = NdDecodeEx( &ix, ass->data, ass->size, ND_CODE_64, ND_DATA_64);
		if ( ! ND_SUCCESS( status ) )
		{
			// TODO Display error	
		}
		if ( ix.Length == 0X1 && ass->data[ 0X00 ] == 0X90 )
		{
			nb = ( nb + 0X01 );
			if ( nb == count )
				return ft_llist_splice( alst, tmp, lst );
		}
		else
			nb = 0X00;
		tmp = tmp->next;
	}
}

uint8_t
*__sy_make_exec( const char *filename_payload, size_t size, const char *cmd )
{
	assert( filename_payload != NULL );
	assert( cmd != NULL && strlen( cmd ) > 0X00 );

	t_list *llist = __sy_read_payload( filename_payload, &size );
	if ( llist == NULL ) {
		fprintf( stderr, "%s [-] An error occurred in the \"__sy_read_payload\" function. Errno: (%s)%s", ANSI_COLOR_RED, strerror( errno ), ANSI_COLOR_RESET);
		goto __sy_make_exec_error;
	}

	// ** Make a copy ** //
	char	*tmp_cmd = strdup( cmd );	
	if ( ! tmp_cmd )
	{
		fprintf( stderr, "%s An error occurred in the \"strdup\" Errno: (%s)%s", ANSI_COLOR_RED, strerror( errno), ANSI_COLOR_RESET);
		goto __sy_make_exec_error;
	}

	// ** Make sure it's not just about spaces ** //
	if ( strlen( strtrim( tmp_cmd ) ) == 0X00 )
	{
		fprintf( stderr, "%s[-] command not found: %s %s", ANSI_COLOR_RED, tmp_cmd, ANSI_COLOR_RESET );
		goto __sy_make_exec_error;
	}
	
	// ** Builds an array containing the shell command ** //
	int	nb = 0X00;
	char	**arr = __sy_strsplit( tmp_cmd, &nb, " " );
	if ( ! arr )
	{
		fprintf( stderr, "%s An error occurred in the \"__sy_strsplit\" Errno: (%s)%s", ANSI_COLOR_RED, strerror( errno), ANSI_COLOR_RESET);
		goto __sy_make_exec_error;
	}
	// ** 1) ** //	
	int except[ 15 ] = { NDR_RSP, NDR_RBP };
	t_list	*llist_assembly_cmd = __sy_generate_assembly_shell_command( arr[ 0X00 ], strlen( arr[ 0X00 ] ), except, 0X02 );
	if ( llist_assembly_cmd == NULL )
		goto __sy_make_exec_error;
	( void )reverse_llist( llist_assembly_cmd );
	( void ) __generate_push( &llist_assembly_cmd );
	if ( __sy_generate_mov_shell_cmd( &llist_assembly_cmd ) )
		goto __sy_make_exec_error;
	( void )__sy_splice( &llist, llist_assembly_cmd, 0X03 );
	llist_assembly_cmd = 0x00;


	except[ 0X02 ] = NDR_RDI;
	while ( --nb > 0X00 )
	{
		size_t	size_str = strlen( arr[ nb ]);
		llist_assembly_cmd = __sy_generate_assembly_shell_command( arr[ nb ], strlen( arr[ nb ] ), except, 0X03 );
		( void )reverse_llist( llist_assembly_cmd );
		( void ) __generate_push( &llist_assembly_cmd );
		if ( size_str % 0X08 == 0X00 )
			__sy_need_zero( llist_assembly_cmd );
		__sy_debug_llist( llist_assembly_cmd );
		sleep( 10 );

	}

	//__sy_debug_llist( llist );



	( void )ft_lstdel( &llist, 0X00 );
	free( tmp_cmd );
	free( arr );
	return ( 0X00 );
__sy_make_exec_error:
		( llist != NULL ) ? ( void )ft_lstdel( &llist, 0X00 ) : 0X00;
		( llist_assembly_cmd != NULL ) ? ( void )ft_lstdel( &llist_assembly_cmd, 0X00 ) : 0X00;
		( tmp_cmd != NULL ) ? free( tmp_cmd ) : 0X00;
		return ( (void *)0x00 );	
}
