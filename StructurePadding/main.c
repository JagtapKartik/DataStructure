/*
 * main.c
 *
 *  Created on: 22-Oct-2021
 *      Author: Kartik
 */


#include <stdio.h>

typedef struct
{
		int temp2;
		int temp3;
		double temp;
		char temp4;
		int temp5;
}size;

int main( void )
{
	printf("[%d]\n",sizeof(size));
	return 0;
}

