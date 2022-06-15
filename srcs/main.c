#include "../include/main.h"

void
__attribute__((constructor)) __pg_start(){
	char const *version = "1.0";
	char const *program_name = "Syfer";
	char const *author = "rcarette";
	fprintf( stderr, "%sAuthor: %s\nProgram name: %s\nVersion: %s\n%s", ANSI_COLOR_GREEN, author, program_name, version, ANSI_COLOR_RESET );

	struct winsize	win = {0};

	ioctl( STDOUT_FILENO, TIOCGWINSZ, &win );
	for( int i = 0x00; i < win.ws_col; ++i )
		fprintf(stderr, "-");
	fprintf(stderr, "%s\n", ANSI_COLOR_RESET);

	// -- ** Initialize random ** -- //
    	srand(time(NULL));
}

int
main(int __attribute__((unused))ac, char __attribute__((unused))**av, char __attribute__((unused))**ev )
{
	analyze_parameter( ac, av );
	return ( 0x00 );
}

void	__attribute__((destructor)) __pg_end() {

}
