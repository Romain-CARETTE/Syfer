#include "../include/main.h"
#include <elf.h>
#include <sys/mman.h>



int	INLINE sys_socket(  VOID int domain, VOID int type, VOID int protocol ) {
	wrap_syscall(SYS_SOCKET);
	return ( 0X00 );
}

int	__attribute__((always_inline)) sys_connect( VOID int sockfd, VOID struct sockaddr *addr, VOID socklen_t addrlen ) {
	wrap_syscall(SYS_CONNECT);
	return ( 0X00 );
}

int	__attribute__((always_inline)) sys_sendto( VOID int sockfd, VOID void *buf, VOID size_t len, VOID int flags, VOID struct sockaddr *dest_addr, VOID socklen_t addrlen ) {
	wrap_syscall(SYS_SENDTO);
	return ( 0X00 );
}

int	__attribute__((always_inline)) sys_recvfrom( VOID int sockfd, VOID void *buf, VOID size_t len, VOID int flags, VOID struct sockaddr *dest_addr, VOID socklen_t *addrlen )
{
	wrap_syscall(SYS_RECVFROM);
    return ( 0X00 );
}


int	__attribute__((always_inline)) sys_setsockopt( VOID int sockfd, VOID int level, VOID int optname, VOID char *optval,  VOID int optlen )
{
	wrap_syscall(SYS_SETSOCKOPT);
    return ( 0X00 );
}

int	__attribute__((always_inline)) sys_gettimeofday( VOID struct timeval *tv, VOID struct timezone *tz ) {
	wrap_syscall(SYS_GETTIMEOFDAY);
	return ( 0X00 );
}

int	__attribute__((always_inline)) sys_nanosleep( VOID struct timespec *req, VOID struct timespec *rem )
{
	wrap_syscall(SYS_NANOSLEEP);
	return ( 0X00 );
}

int	__attribute__((always_inline)) sys_close( VOID int fd )
{
	wrap_syscall(SYS_CLOSE);
	return ( 0X00 );
}

void __attribute__((always_inline)) *sys_mmap( VOID void *addr, VOID size_t length, VOID int prot,  VOID int flags, VOID int fd, VOID off_t offset )
{
	wrap_syscall(SYS_MMAP);
    return ( 0X00 );
}

int	__attribute__((always_inline)) sys_mprotect( VOID void *addr, VOID size_t len, VOID int prot )
{
	wrap_syscall(SYS_MPROTEC);
    return ( 0X00 );
}

int	__attribute__((always_inline)) sys_munmap( VOID void *addr, VOID size_t length)
{
	wrap_syscall(SYS_MUNMAP);
    return ( 0X00 );
}

ssize_t	sys_write( int fd, const void *buf, size_t count)
{
	wrap_syscall(SYS_WRITE);
	return ( 0X00 );
}


void __attribute__((always_inline)) *__SY_memmove ( void *dest, const void *src, size_t len )
{
  char *d = dest;
  const char *s = src;
  if (d < s) {
    while (len--)
      *d++ = *s++;
  }
  else {
      const char *lasts = s + (len-1);
      char *lastd = d + (len-1);
      while (len--)
        *lastd-- = *lasts--;
  }
  return ( dest );
}


char __attribute__((always_inline)) __SY_isdigit( unsigned char c)
{
    if ( c >= '0' && c <= '9' )
        return ( 0X01 );
    return ( 0X00 );
}

int syys_rt_sigaction( int sig, const struct kernel_sigaction *act, const struct kernel_sigaction *oact ) {
	int ret = 0;
	size_t sigsetsize = sizeof(act->sa_mask);
	asm volatile (
			"mov $13, %%rax\n"
			"mov %1, %%edi\n"
			"mov %2, %%rsi\n"
			"mov %3, %%rdx\n"
			"mov %4, %%r10\n"
			"syscall\n"
			"mov %%eax, %0\n"
			:   "+rm" (ret)
			:   "rm" (sig), "rm" (act), "rm" (oact), "rm" (sigsetsize)
			:   "rax", "edi", "rsi", "rdx", "r10");
	return ret;
}
