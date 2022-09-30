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
        *size = 0x01 + sizeof( int );
        return ( data );
}

uint8_t
*__MH_sub_reg64_imm32( unsigned char reg, int imm, int *size  ) {

	uint8_t first = ( reg >= NDR_R8 ) ? 0X48 : 0X49;
	uint8_t	two = ( imm > 127 ) ? 0X81 : 0X83;

       	uint8_t     *data = (uint8_t *)malloc(sizeof(uint8_t)*ND_MAX_INSTRUCTION_LENGTH+1);
        if ( data == NULL )
		return ( NULL );

	printf("NDR_RDI: %d - NDR_R8: %d  reg: %d\n", NDR_RDI, NDR_R8, reg);
	printf("NDR_RDI: %d - NDR_R15: %d  reg: %d\n", NDR_RDI, NDR_R15, reg);
	*(data+0X00) = ( reg >= NDR_R8 ) ? 0X49 : 0X48;
	*(data+0X01) = ( imm > 127 ) ? 0X81 : 0X83;
	*(data+0X02) =  (0XE8 | reg);
	memmove( &data[0X03], &imm, sizeof( int ));
	if ( *(data+1) == 0X81 )
		*size = ( sizeof( int ) + 0X03);
	else
		*size = 0X04;
        return ( data );
}
