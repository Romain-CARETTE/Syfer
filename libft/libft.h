#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <sys/ioctl.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <assert.h>
# include <ncurses.h>
# include <stdlib.h>
# include <menu.h>
# include <sys/prctl.h>
# include <time.h>
# include <math.h>
# include <limits.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netinet/tcp.h>
# include <sys/mman.h>
# include <openssl/sha.h>

# define _unused	__attribute__((unused))
# define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))


# define ANSI_COLOR_RED		"\x1b[31m"
# define ANSI_COLOR_GREEN	"\x1b[32m"
# define ANSI_COLOR_YELLOW	"\x1b[33m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_RESET	"\x1b[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next, *prev;
}					t_list;


// DIFFIE HELLMAN
typedef struct			s_globalInfo {
	uint32_t		prime, generator;
}				t_globalInfo;
int		GeneratePrimitiveRoot( int );
int		GeneratePrime( void );
int		compute_exp_modulo( int a, int b, int p );
int		__exchange_key_srv( unsigned char *, int, int );
int		__exchange_key_clt( unsigned char *, int, int );
void		__print_k( unsigned char *, int );


t_list		*ft_lstnew( void const *, size_t );
void		ft_lstdelone( t_list **, void (*)(void *, size_t) );
void		ft_lstdel( t_list **, void (*)(void *, size_t) );
void		ft_lstadd( t_list **, t_list * );
t_list		*ft_lstiter( t_list *, uint8_t (*)(t_list *elem) );
uint8_t		detach_block( t_list **, t_list * );


int		get_winsize( struct winsize *ws );

char		*ft_itoa(int);
WINDOW		*ft_create_win( int, int, int, int );
void		_time( char * );
char		*make_rand_str( char *, int );
void		sha256( char *, size_t, unsigned char * );
char 		*get_ip( struct sockaddr_in * );
uint32_t	get_port ( struct sockaddr_in * );
unsigned short	__rc_checksum( void *, int );

#endif
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
