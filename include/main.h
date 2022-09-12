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
#include <sys/syscall.h>
# include "../libft/libft.h"
//#include <curl/curl.h>
#include "../bddisasm/inc/bddisasm.h"
#include <openssl/md5.h>
#include <regex.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <openssl/sha.h>

#define SA_RESTORER	0x04000000
#define SIGTRAP                5
# define INT3			0xcc
# define _STUB			13

struct kernel_sigaction {
	void (*sa_handler)(int);
	unsigned long sa_flags;
	void (*sa_restorer)(void);
	unsigned long sa_mask;
};

void 	restorer();
void	sigtrap_handler( int );
void _signal_init();
void	_end_signal( void );
#define ANSI_COLOR_RED		"\x1b[31m"
#define ANSI_COLOR_GREEN	"\x1b[32m"
#define ANSI_COLOR_YELLOW	"\x1b[33m"
#define ANSI_COLOR_BLUE		"\x1b[34m"
#define ANSI_COLOR_RESET	"\x1b[0m"

#define __ALIGN_MASK(x,mask)    (((x)+(mask))&~(mask))
#define CHECK(x) \
    do { \
        if (!(x)) { \
            fprintf(stderr, "%s[-] %s:%d: ", ANSI_COLOR_RED, __func__, __LINE__); \
            perror(#x); \
            fprintf(stderr, "%s\n", ANSI_COLOR_RESET); \
            exit(-1); \
        } \
    } while (0) \

typedef struct stat	__sy_stat;
////////////////////////////////////////////////////////////////////////////////
/// DEFINES
////////////////////////////////////////////////////////////////////////////////
//
//

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


typedef struct		__attribute__((packed))__sy_binary
{
	int					opts;
	char					out_binary_name[PATH_MAX];
	char					*binary_name;
	struct stat				st;
	char                    		**stub;
	char					**ip;
}						t__sy_binary;

typedef struct	__attribute__((packed))	__symbol
{
	uint8_t				stat;
	uint16_t			id;
	size_t				size_symbol;
	uint8_t				_backup_sym[ 3 ], __backup_sym[ 3 ];
	uint8_t				key[ 16 ];
}					t_sym;

typedef struct	__attribute__((packed))	__functions
{
	const char			*function_name;
	struct __symbol			sym;
	
}					t_fct;

typedef struct __attribute__((packed))	s_elf {
	Elf64_Addr 			old_entrypoint;
	Elf64_Off 			segment_offset;
	Elf64_Addr 			segment_addr;
	Elf64_Xword 			segment_size;
	Elf64_Off 			section_offset;
	Elf64_Addr 			section_addr;
	Elf64_Xword 			section_size;
	Elf64_Shdr			*text, *strtab, *symtab;
	void 				*ptr;
	size_t 				filesize;
	char const 			*filename;
	t__sy_binary			*sy_binary;
	char				*stub;
	uint32_t			size_stub, n;	
} 					t_elf;

typedef struct		__attribute__((packed))__sy_stub
{
	struct stat				st;
	const char				filename[PATH_MAX];
	unsigned char				*stub;
}						t__sy_syfer;



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


void error(t_error const err, char const *filename, int line );

void modify_segments(t_elf *elf );
void modify_sections(t_elf *elf );
void modify_header(t_elf *elf );
void create_infected(t_elf const * );

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

// ELF
const char 	*ELF_get_sym_name( t_elf *, const Elf64_Sym * );
uint8_t		*ELF_get_sym_location( t_elf *, const Elf64_Sym * );

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
void 		__pg_AES_encrypt(char *key, char *value, size_t len );
t_list		*apply_inner_encryption( t_elf *, uint32_t * );




int	analyze_parameter( int, char **);
int syfer( t__sy_binary * );


// ** BACKDOOR ** //
uint8_t		__SY_backdoor( char ** );


// ** Function libc ** //
void *__SY_memmove ( void *, const void *, size_t );
char __SY_isdigit( unsigned char );


// ** UTILS.C ** //
void	delete_symbols( void *, size_t );


// ** METAMORPH.C ** //
uint8_t	*__MH_mov_reg32_imm32( unsigned char, int, int * );

// ** ASSEMBLY SYSCALL ** //
# define SYS_READ       	0X00
# define SYS_WRITE      	0X01
# define SYS_OPEN       	0X02
# define SYS_CLOSE      	0X03
# define SYS_STAT      		0X04
# define SYS_FSTAT      	    0X05
# define SYS_MMAP       	    0X09
# define SYS_MPROTEC    	    0X0A
# define SYS_MUNMAP     	    0X0B
# define SYS_ACCESS     	    0X15
# define SYS_NANOSLEEP		    0X23
# define SYS_GETPID		        0X27
# define SYS_GETPPID		    0X6E
# define SYS_SOCKET		        0X29
# define SYS_FORK		        0X39
# define SYS_CONNECT		    0X2A
# define SYS_SENDTO		        0X2C
# define SYS_RECVFROM		    0X2D
# define SYS_CHDIR		        0X50
# define SYS_CHMOD		        0X5A
# define SYS_EXIT		        0X3C
# define SYS_UNLINK		        0X57
# define SYS_KILL		        0X3E
# define SYS_GETTIMEOFDAY       0X60
# define SYS_PTRACE     	    0X65
# define SYS_GETDENTS64 	    0XD9
# define SYS_UTIME 		        0X84
# define SYS_TIMER_CREATE 	    0XDE
# define SYS_TIMER_SETTIME 	    0XDF
# define SYS_TIMER_DELETE 	    0XE2
# define SYS_OPENAT     	    0X101
# define SYS_INOTIFY_INIT       0XFD
# define SYS_INOTIFY_ADD_WATCH	0XFE
# define SYS_INOTIFY_RM_WATCH	0XFF
# define SYS_EXECVE		        0X3B
# define SYS_SETSOCKOPT         0X36

# define INLINE __attribute__((always_inline)) inline
# define wrap_syscall(x)	wrapper_syscall(x)

# define wrapper_syscall(x)	asm volatile (".intel_syntax;\n"        \
						"  mov r10, rcx\n"      \
						"  mov rax, " #x "\n"   \
						"  syscall\n"           \
						"  leave\n"             \
						"  ret\n");
int	    sys_socket( int, int, int );
int	    sys_connect( int, struct sockaddr *, socklen_t );
int	    sys_sendto( int,void *, size_t, int, struct sockaddr *,socklen_t );
int	    sys_recvfrom( int, void *, size_t, int, struct sockaddr *, socklen_t * );
int     sys_setsockopt( int, int, int, char *, int );
int	    sys_gettimeofday( struct timeval *, struct timezone * );
int	    sys_nanosleep( struct timespec *, struct timespec * );
int	    sys_close( int );
void    *sys_mmap( void *, size_t, int, int, int, off_t );
int	    sys_mprotect( void *, size_t, int );
int	    sys_munmap( void *, size_t );
ssize_t	sys_write( int, const void *, size_t );
int	sys_rt_sigaction( int, const struct kernel_sigaction *, const struct kernel_sigaction * );

#endif /* MAIN_H */
