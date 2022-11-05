/*
 * main.c
 *
 *  Created on: 09-Nov-2021
 *      Author: Kartik
 */
#include<stdio.h>
#include<stdint.h>

uint32_t get_mask( int count )
{
	uint32_t mask = 0;
	for( int i=0;i<count;i++)
	{
		mask |= ( 1 << i );
	}
	return mask;
}

void sort_array( int *arr, int size )
{
	int temp = 0;
	for( int i=0;i<size;i++)
	{
		if( arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			i = 0;
		}
	}
}

int main( void )
{
	uint8_t startbit = 8;
	uint8_t count = 4;
	int var = 0xABCDEF12;
//	var  = ( ( var >> 8 ) & 0xFF ) | ( ( var << 8 ) & 0xFF00 ) | ( var & 0xFFFF0000 );
//	printf("[%x]\n", var);
	uint32_t mask = get_mask( count );
	uint32_t extracted_bit = ( var >> startbit ) & mask;
//	printf("[%x]\n", extracted_bit);
	int arr[10] = {1,3,2,5,4,7,8,6,9,0};
	sort_array(arr, 10);
	for( int i=0;i<10;i++)
	{
		printf("%d", arr[i] );
	}
	return 0;
}



