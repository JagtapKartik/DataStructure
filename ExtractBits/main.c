/*
 * main.c
 *
 *  Created on: 28-Oct-2021
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdint.h>

uint32_t getmask( uint32_t count )
{
	uint32_t mask_val = 0;
	for( int i=0;i<count;i++)
	{
		mask_val |= ( 1 << i);
	}
	return mask_val;
}

uint32_t extract_bit( uint32_t num, uint32_t start_bit, uint32_t count )
{
	uint32_t mask = getmask( count );
	num = ( num  & ( mask = ( mask << start_bit ) ) );
//	printf("[%x]\n", num );
	return ( num >> start_bit );
}

uint32_t extract_bit2( uint32_t num, uint32_t start_bit, uint32_t count  )
{
	uint32_t temp = 0;
	num = ( num >> start_bit );
	for( int i=0;i< count;i++)
	{
		temp |= ( num & ( 1 << i ));
	}
	return temp;
}

void array_sort( int *array, int count )
{
	int temp = 0;
	for( int i=0;i<count;i++)
	{
		if( array[i] > array[i+1] )
		{
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			i = -1;
		}
	}
}

int main( void )
{
	int num = 0xCD;
//	printf("1 [%x]\n",extract_bit( num, 3, 3 ));
//	printf("2 [%x]\n",extract_bit2( num, 3, 3 ));
	int array[10] = { 3,6,4,2,1,8,7,5,9,0};
	array_sort(array,10);
	for( int i=0;i<10;i++)
	{
		printf("[%d]",array[i]);
	}printf("\n");
	return 0;
}



