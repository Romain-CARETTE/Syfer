#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdio.h>
#include <time.h>
#include <publib.h>
#include <elf.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <errno.h>
#include <dirent.h>
#include <math.h>
#include <assert.h>
//#include <curl/curl.h>
#include <signal.h>
#include "../bddisasm/inc/bddisasm.h"
#include <openssl/md5.h>
#include <regex.h>
#include <stdint.h>

typedef struct stat	__sy_stat;
////////////////////////////////////////////////////////////////////////////////
/// DEFINES
////////////////////////////////////////////////////////////////////////////////
//
//

#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_RESET	"\x1b[0m"

#define VALID_AV_SIZE 2

#define ELF_MAGIC_SIZE 4
#define ELF_MAGIC_NUMBER 1179403647
#define PACK_MAGIC_NUMBER 0x15D25

#define X86_64 2

#define PAYLOAD_SIZE 63
#define PAGE_SIZE 4096

#define DEFAULT_SIZE 8

#define VOID __attribute__((unused))
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

////////////////////////////////////////////////////////////////////////////////
/// ENUM
////////////////////////////////////////////////////////////////////////////////



struct      __attribute__((packed))__stub
{
    char                            *stub;
    uint32_t                        num_of_encryption_rounds;
    uint8_t                         encryption_type;
};

typedef struct		__attribute__((packed))__sy_binary
{
	int					opts;
	char					out_binary_name[PATH_MAX];
	char					*binary_name;
	struct stat				st;
	char                    **stub;
    char					**ip;
}						t__sy_binary;

////////////////////////////////////////////////////////////////////////////////
/// PROTOTYPES;
////////////////////////////////////////////////////////////////////////////////

// ** [Parameter] ** //
int	analyze_parameter( int, char **);
#endif /* MAIN_H */
