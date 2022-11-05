/*
 * main.c
 *
 *  Created on: 02-Jan-2021
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdlib.h>

int getMoneySpent(int keyboards_count, int* keyboards, int drives_count, int* drives, int b) {
    /*
     * Write your code here.
     */
	int result = 0, resultIndex = 0;
	int *resultArray = (int *) malloc( ( keyboards_count * drives_count) * sizeof( int ));
	for(int i = 0;i<keyboards_count;i++)
	{
		for(int j=0;j<drives_count;j++)
		{
			resultArray[resultIndex] = keyboards[i] + drives[j];
			resultIndex++;
		}
	}

	result = resultArray[0];
	for( int i = 0;i<( keyboards_count * drives_count);i++)
	{
		if( resultArray[i] > result  && resultArray[i] <= b)
		{
			result = resultArray[i];
		}
		else
		{
			result = -1;
		}
	}

	return result;
}

int main( void )
{
	int keyboardArray[1] = {1};
	int drives[1] = {5};
	int budget = 5;
	printf("Result[%d]\n",getMoneySpent(3,keyboardArray,3,drives,budget));
	return 0;
}

