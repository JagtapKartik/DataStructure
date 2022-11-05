/*
 * main.c
 *
 *  Created on: 02-Nov-2021
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdint.h>

int main( void )
{
	int i=4096;
	uint32_t temp = ( 1 << 31 );
	printf("[");
	while( temp )
	{
		printf("%d", ( ( i & temp ) > 0 ) ? 1 : 0 );
		temp = ( temp >> 1 );
	}printf("]\n");
	return 0;
}


