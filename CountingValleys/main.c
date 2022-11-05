/*
 * main.c
 *
 *  Created on: 01-Jan-2021
 *      Author: Kartik
 */

#include <stdio.h>

//char string_t[8] = "UDDDUDUU";

int countingValleys( int steps, char *string )
{
	int upCount = 0, downCount = 0;
	int indexOfUpcount = 0, indexOfDowncount = 0;
	int valleyCount = 0;

	for(int i = 0;i<steps;i++)
	{
		if( string[i] == 'D')
		{
			downCount++;
			indexOfDowncount = i;
		}
		else if( string[i] == 'U')
		{
			upCount ++;
			indexOfUpcount = i;
		}

		if( indexOfUpcount > indexOfDowncount )
		{
			if( (upCount - downCount) == 0 )
			{
				valleyCount++;
			}
		}
		else
		{
			if( ( upCount - downCount ) == 0 )
			{
				upCount = 0;
				downCount = 0;
			}
		}
	}
	return valleyCount;
}

int main( void )
{
//	char string_t[8] = "UDDDUDUU";
	char string_t[8] = "DDUUUUDD";
	printf("Valley Count [%d]\n",countingValleys( 8, string_t ) );
	while(1);
	return 0;
}



