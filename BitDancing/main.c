/*
 * main.c
 *
 *  Created on: 24-Sep-2021
 *      Author: Kartik
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BIT_SET( VAR, POS )  ( VAR |= ( 1 << POS ) )
#define BIT_CLEAR( VAR, POS ) ( VAR &= ~( 1<< POS ))
#define BIT_TOGGLE( VAR, POS )    ( VAR ^= ( 1 << POS ) )
#define BIT_MASK( VAR, POS, MASK ) ( VAR ^= (MASK << POS ) )
#define SQUARE( X ) ( X * X )

//2 + 3 * (2 + 3)

uint32_t data = 0x1122ABCD;

void checkZero( int data )
{
	int size = sizeof( data );
	int count  = 0;
	for( int i=0;i< 32;i++)
	{
		if( (  data  & ( 1 << i ) ) == 0 )
		{
			count++;
		}
	}
	printf("[%d]\n",count);
}


uint32_t swap_uint32( uint32_t val )
{
    val = ((val << 8) & 0xFF00FF00 ) | ((val >> 8) & 0xFF00FF );
    return (val << 16) | (val >> 16);
}
void swap_byte( uint32_t data )
{
	printf("[%x]\n",data);
//	data = ((( data << 8 ) & 0xFF00 ) | ( ( data >> 8 ) & 0x00FF) | (( data >> 8  ) & 0x00FF0000 ) | ( ( data << 8 ) & 0xFF000000) );
//	data = ((( data >> 8  ) & 0x00FF0000 ) | ( ( data << 8 ) & 0xFF000000)) | ( data & 0xFFFF);
//	data = ( ( data >> 8 ) & 0xFF ) | ( ( data << 8 ) & 0xFF00 ) | ( data & 0xFFFF0000);
	data = ( ( data >> 4 ) & 0xF ) | ( ( data << 4 ) & 0xF0) | ( data  & 0xFFFFFF00 );
	printf("[%x]\n",data);
}

void swap_nibble( uint32_t data )
{
	data = ( ( data >> 4) & 0x0F ) | ( (data << 4) & 0xF0);
	printf("[%x]\n",data);
}

int array[10] = {1,2,1,3,4,3,4,5,5,3};

void find_number( int *array )
{
    int num = array[0];
    for( int i=0;i<sizeof(array);i++)
    {
        if( num == array[i+1] )
        {
            /*Do Nothing*/
        }
        else
        {
            num = array[i];
        }
    }
    printf("[%d]\n", num );
}

void justUpdate(bool *temp1, uint8_t *temp2)
{
	*temp1 = true;
	(*temp2)++;
	printf("[%d]",*temp2);
}

int main( void )
{
#if 0
//	int var = 0x0;
////	BIT_SET(var, 4);
//	printf("[%x]\n",var);
////	BIT_CLEAR(var, 4);
////	printf("[%x]\n",var);
////	BIT_TOGGLE( var, 1 );
//	printf("[%x]\n",var);
//	BIT_MASK( var, 16, 0xf );
//	printf("[%x]\n",var);
	printf("[%d]\n",SQUARE(2 + 3));
//	checkZero(data);
	swap_byte(data);
	swap_nibble( data );
//	printf("val [%x]\n",data);
	find_number( array );
#endif
	bool temp1[100];
	uint8_t temp2[100];
	temp2[0] = 2;
	justUpdate(&temp1[0], &temp2[0]);
	printf("[%d][%d]",temp1[0],temp2[0]);
	return 0;
}



