#include "../include/main.h"

/*** Needs to be defined for bddisasm ***/
int
nd_vsnprintf_s( char *buffer, size_t sizeOfBuffer, size_t count, const char *format, va_list argptr ) {
        return vsnprintf(buffer, sizeOfBuffer, format, argptr);
}

/*** Needs to be defined for bddisasm ***/
void*
nd_memset(void *s, int c, size_t n) {
        return memset(s, c, n);
}


uint8_t
*__MH_mov_reg32_imm32( unsigned char reg, int imm, int *size  ) {
        static unsigned char mov = 0XB8;

       	uint8_t     *data = (uint8_t *)malloc(sizeof(uint8_t)*ND_MAX_INSTRUCTION_LENGTH+1);
        if ( data == NULL )
		return ( NULL );

        if ( reg > 0X07 ) {
                reg -= NDR_R8D;
                *(data+0X00) = 0X41;
                *(data+0X01) = reg |= mov;
		memmove( &data[0x02], &imm, sizeof(int));
                *size = 0x2 + sizeof( int );
                return ( data );

        }
        reg |= mov;
        *(data+0X00) = reg |= mov;
	memmove( &data[0x01], &imm, sizeof(int));
	printf("%x\n", data[1]);
        *size = 0x01 + sizeof( int );
        return ( data );
}
