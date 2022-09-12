#include "libft.h"

int
get_winsize( struct winsize *ws ) {
    return ioctl(STDIN_FILENO, TIOCGWINSZ, ws );
}
