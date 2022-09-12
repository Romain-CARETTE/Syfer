#include "libft.h"

void	_time( char *str ) {
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(str, "[%d-%02d-%02d %02d:%02d:%02d]", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
