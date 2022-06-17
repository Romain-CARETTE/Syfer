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
)
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
        else if ( ! strcmp( av[*i], "-o")) {
            memcpy( data->out_binary_name, av[*i+1], strlen( av[*i+1]));
            ++(*i);
        }
        else
        {
            --(*i);
            break;
        }
    }
}


int
analyze_parameter( int ac, char **av )
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

            if ( *data->out_binary_name == 0x00 ) {
                char    *tmp = strrchr( data->binary_name, '/');
                if ( tmp == NULL )
                    tmp = data->out_binary_name;
                sprintf( data->out_binary_name, "Syfer_%s.out", ++tmp);
            }

            syfer_verbose( data );

            ( data->stub != NULL ) ? free( data->stub ) : 0X00;
            ( data->ip != NULL ) ? free( data->ip ) : 0X00;
            memset( data, 0X00, sizeof( t__sy_binary));
            printf("\n");
        }
	}
    free( data );
	return ( 0x00 );
}
