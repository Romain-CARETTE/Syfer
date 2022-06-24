#include "../include/main.h"
#include <elf.h>
#include <sys/mman.h>

static uint8_t
__SY_copy_mem( char *filename, char *mem, size_t size ) {

    uint8_t res = 0X01;
    int fd = open( filename, O_RDONLY );
    if ( fd == -1 )
        return fprintf( stderr, "%s[-] The opening of the %s file in read mode has failed. Errno: %s%s\n", ANSI_COLOR_RED, filename, strerror(errno), ANSI_COLOR_RESET);
    fprintf( stderr, "%s[+] Successful opened file %s in read mode%s\n", ANSI_COLOR_GREEN, filename, ANSI_COLOR_RESET);

    if ( read( fd, mem, size ) != size ) {
        fprintf( stderr, "%s[-] Failed to read %s file.%s\n", ANSI_COLOR_RED, filename, ANSI_COLOR_RESET);
        goto end;
    }
    fprintf( stderr, "%s[+] Successful reading of %s file.%s\n", ANSI_COLOR_GREEN, filename, ANSI_COLOR_RESET);
    fprintf( stderr, "%s[+] Closing the %s file.%s\n", ANSI_COLOR_GREEN, filename, ANSI_COLOR_RESET);
    res = 0x00;
end:
    (fd != -1 ) ? close ( fd ) : 0x00;
    return ( res );
}

static int
__SY_analyze( t_elf *elf ) {

    if ( ! memcmp( elf->ptr, ELFMAG, SELFMAG) ) {

        char    *ptr = elf->ptr;
        fprintf( stderr, "%s[+] The file type is supported. - (%s) %s\n", ANSI_COLOR_GREEN, ptr, ANSI_COLOR_RESET);
        switch( ptr[EI_CLASS] )
        {
            case ELFCLASS32:
                fprintf( stderr, "%s[+] The %s binary architecture is supported. - (%s) %s\n", ANSI_COLOR_GREEN, elf->filename, "Intel 80386", ANSI_COLOR_RESET);
                break;
            case ELFCLASS64:
                fprintf( stderr, "%s[+] The %s binary architecture is supported. - (%s) %s\n", ANSI_COLOR_GREEN, elf->filename, "x86-64", ANSI_COLOR_RESET);
                break;
            default:
                fprintf( stderr, "%s[-] The %s binary architecture is not supported%s\n", ANSI_COLOR_RED, elf->filename, ANSI_COLOR_RESET);
                break;

        }
    }
    return fprintf( stderr, "%s[-] The file type is not supported.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
}

int
syfer( t__sy_binary *data ) {

    /*
     ** Verification that the file has read rights.
     */
    if ( access( data->binary_name, R_OK ) != 0X00 )
        return fprintf( stderr, "%s[-] %s: Permission denied.%s\n", ANSI_COLOR_RED, data->binary_name, ANSI_COLOR_RESET);

    /*
     ** Get the binary size.
     */
    struct stat sb = {0x00};
    if ( lstat( data->binary_name, &sb ) == -1)
        fprintf( stderr, "%s lstat: %s%s", ANSI_COLOR_RED,  strerror(errno), ANSI_COLOR_RESET);

    /*
     ** Memory allocation of the elf structure.
     */
    t_elf *elf = calloc( sizeof( char ), sizeof( *elf ) );
    if ( elf == NULL )
        return fprintf(stderr, "%s[-] A memory allocation error occurred during the memory allocation of the \"t_elf\" structure.%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
    fprintf(stderr, "\n%s[+] Successful memory allocation of the \"t_elf\" structure.%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);

    /*
     ** Allocation of a memory page that will contain the binary.
     */
    elf->ptr = mmap( NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0 );
    if ( elf->ptr == MAP_FAILED ) {
        free( elf );
        return fprintf( stderr, "%s[-] The allocation of the memory page has failed. Errno: %s%s\n", ANSI_COLOR_RED, strerror(errno), ANSI_COLOR_RESET);
    }
    fprintf( stderr, "%s[+] Successful allocation of a %ld bytes a memory page.%s\n", ANSI_COLOR_GREEN, sb.st_size, ANSI_COLOR_RESET);

    /*
     ** Copy the data from the bynary into a memory page.
     */
    if ( __SY_copy_mem(data->binary_name, elf->ptr, sb.st_size ) ) {
        munmap( elf->ptr, elf->filesize );
        free( elf );
        return ( 0x01 );
    }
    elf->filesize = sb.st_size;
    elf->filename = data->binary_name;

    /*
     ** Checking the file type.
     ** Check if the file is an ELF Format.
     */
    __SY_analyze( elf );

    munmap( elf->ptr, elf->filesize );
    free( elf );
    return ( 0x00 );
}
