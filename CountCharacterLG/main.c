/*
 * main.c
 *
 *  Created on: 21-Nov-2021
 *      Author: Kartik
 */



#include <stdio.h>
#include <stdlib.h>

char *array = "aaabccddee";

void count_char( char *array, int size )
{
	char count  = 1;
	int idx = 0;
	char *temp = ( char *) malloc( size );
	for( int i = 0;i<size;i++)
	{
		if( array[i] == array[i+1])
		{
//			printf("[%c][%c]\n", array[i], array[i+1]);
			count++;
			temp[idx] = array[i];
//			temp[idx + 1] = ( char )count;
			sprintf( (temp  + (idx + 1)), "%d", count);
		}
		else
		{
//			printf("[%c][%c]\n", array[i], array[i+1]);
			idx += 2;
			count = 1;
			temp[idx] = array[i + 1];
//			temp[idx + 1] = count;
			sprintf( (temp  + (idx + 1)), "%d", count);
		}
	}

	for( int i=0;i<size;i++)
	{
		printf("[%c]", temp[i]);
	}printf("\n");

}

int main( void  )
{
	count_char( array, strlen( array ));
	return 0;
}
