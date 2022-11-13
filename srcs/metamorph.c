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
*__mh_mov_regx32_imm32( uint8_t reg, int imm, int *size  )
{

	*size = 0X00;
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
*__mh_sub_regx64_imm32( uint8_t reg, int imm, int *size  )
{

	*size = 0X00;
	uint8_t first = ( reg >= NDR_R8 ) ? 0X48 : 0X49;
	uint8_t	two = ( imm > 127 ) ? 0X81 : 0X83;

       	uint8_t     *data = (uint8_t *)malloc(sizeof(uint8_t)*ND_MAX_INSTRUCTION_LENGTH+1);
        if ( data == NULL )
		return ( NULL );

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

/*
 * \fn uint8_t	*__mh_push_regX64( register uint8_t, uint8_t * )
 * \brief [ ... ]
 */
uint8_t 	*__mh_push_regX64( register uint8_t reg, uint8_t *size )
{
	assert( size != NULL );
	*size = ( reg > NDR_RDI) ? 0X02 : 0X01;
	uint8_t	*data = calloc( sizeof(char), ND_MAX_INSTRUCTION_LENGTH );
	if ( ! data )
		goto __mh_push_regX64_end;
	if ( *size > 1 )
	{
		*(data+0x00) = 0x41;
		*(data+0x01) = ((reg - NDR_R8) | 0x50 );
		goto __mh_push_regX64_end;
	}
	*(data+0x00) = (reg | 0x50 );
__mh_push_regX64_end:
    		return (data);
}

/*
 * \fn uint8_t	*__mh_push_imm32( register uint8_t, int, uint8_t * )
 * \brief [ ... ]
 */
uint8_t 	*__mh_push_imm32( register uint8_t reg, const int imm, uint8_t *size )
{
	uint8_t	*data = calloc( sizeof(char), ND_MAX_INSTRUCTION_LENGTH );
	if ( ! data )
		goto __mh_push_imm32_end;
	data[ 0X00 ] = ( imm <= 127) ? 0X6A : 0X68;
	switch( data[ 0X00 ])
	{
		case 0X6A:
			data[ 0X01 ] = (uint8_t)imm;
			*size = 0X02;
			break;
		case 0X68:
			memmove( &data[ 0X01 ], &imm, sizeof( int ));
			*size = ( sizeof( int ) + 0X01 );
			break;
		default:
			break;
	}
__mh_push_imm32_end:
		return ( data );
}

/*
 * \fn uint8_t __mh_pop_regX64( register uint8_t, uint8_t * )
 * \brief [ ... ]
 */
uint8_t 	*__mh_pop_regX64( register uint8_t reg, uint8_t *size ) {
	assert( size != NULL );
	*size = ( reg > NDR_RDI) ? 2 : 1;
        uint8_t   *data = calloc( sizeof( char), ND_MAX_INSTRUCTION_LENGTH );
	if ( ! data)
		goto __mh_pop_regX64_end;

        if ( *size > 1 )
	{
                *(data+0x00) = 0x41;
                *(data+0x01) = (0x58 + (reg - NDR_R8) );
                goto __mh_pop_regX64_end;
        }
        *(data+0x00) = (0x58 + reg );
__mh_pop_regX64_end:
        	return ( data );
}

/* 
 * \fn uint8_t		*__mh_movabs_str( register uint8_t, uint8_t *, char *)
 * \brief [ ... ]
 */
uint8_t		*__mh_movabs_str( register uint8_t reg, uint8_t *size, char *value) {
       
	uint8_t   *data = calloc( sizeof( char), ND_MAX_INSTRUCTION_LENGTH );
	if ( ! data )
		goto __mh_movabs_str_end;
	data[ 0X00 ] = ( reg <= NDR_RDI ) ? 0X48 : 0X49;	
	data[ 0X01] = ( 0XB8 | reg );
	memcpy( &data[ 0X02 ], value, strlen( value ) );
	
	memcpy( &data[ 0X02 ], value, 0X08 );
	*size = 10;
__mh_movabs_str_end:
		return ( data );
		
}

/*
 * \fn uint8_t 	*__mh_mov_regX64_regX64( register uint8_t, register uint8_t, uint8_t *)
 * \brief [...]
 */
uint8_t 	*__mh_mov_regX64_regX64( register uint8_t dst, register uint8_t src, uint8_t *size ) {
    assert( size != NULL );

    uint8_t	*data = (unsigned char *)calloc( sizeof( char), ND_MAX_INSTRUCTION_LENGTH );
    if ( ! data )
	    goto __mh_mov_regX64_regX64_end;

    *(data+1) = 0X89;

    if (dst > NDR_RDI && src > NDR_RDI)
		*data = 0X4D;
    else if (dst < NDR_R8 && src > NDR_RDI)
		*data = 0X4C;
    else if (dst > NDR_RDI && src < NDR_R8)
		*data = 0X49;
    else if (dst < NDR_R8 && src < NDR_R8)
		*data = 0X48;
    dst -= ( dst > NDR_RDI ) ? NDR_R8D : 0x00;
    src -= ( src > NDR_RDI ) ? NDR_R8D : 0x00;
    *(data+2) = ((0XC0 + (src * 8)) | dst);
    *size = 0X03;
__mh_mov_regX64_regX64_end:
    		return ( data );
}

