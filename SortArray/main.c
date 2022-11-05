/*
 * main.c
 *
 *  Created on: 15-Nov-2021
 *      Author: Kartik
 */

#include <stdio.h>

int array[10] = { 5,2,4,5,1,2,2,3,1,5};

void shift_array( int *array,int size,  int index )
{
    for( int i=index;i< ( size - index) - 1  ;i++)
    {
        array[i] = array[i + 1];
    }
}

void sort_array( int *array, int size )
{
    int temp = 0;
    for( int i=0;i<size;i++)
    {
        if( array[i] > array[i+1])
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
            i = -1;
        }
    }
    for( int i=0;i<size;i++)
    {
    	if( array[i] ==  array[i+1] )
    	{
    		shift_array( array, 10, i);
    		i-=1;
    	}
    }
}

int main()
{
    printf("Hello World\n");
    sort_array( array, 10 );
    for( int i=0;i<10;i++)
    {
        printf("[%d]", array[i]);
    }

    return 0;
}


