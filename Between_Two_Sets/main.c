#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

uint32_t getMax( int *arr, int arr_count)
{
	uint32_t Max = 0;
	Max = arr[0];
	for( int i = 0;i<arr_count;i++)
	{
		if( arr[i] > Max )
		{
			Max = arr[i];
		}
	}
	return Max;
}

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

bool firstArrayResult( int num, int *arr, int count)
{
	for( int i=0;i<count;i++)
	{
		if( ( num % arr[i] ) == 0 )
		{
			if( i == ( count - 1 ))
			{
			return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool secondArrayResult( int num, int *arr, int count )
{
	for( int i=0;i<count;i++)
	{
		if( ( arr[i] % num ) == 0 )
		{
			if( i == ( count - 1 ))
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	return false;
}

int getTotalX(int a_count, int* a, int b_count, int* b) {
	uint32_t aMax = getMax(a, a_count);
	uint32_t bMax = getMax( b,  b_count);

	uint32_t Max = aMax > bMax ? aMax: bMax;
	uint32_t tempCount = 1;
	uint32_t resultCount = 0;

	while( tempCount <= Max )
	{
		if( firstArrayResult(tempCount, a, a_count ) == true )
		{
			if( secondArrayResult( tempCount, b, b_count) == true )
			{
				resultCount++;
			}
		}
		tempCount++;
	}

	return resultCount;
}

int main( void )
{
	int a_count =2;
	int b_count =2;

	int a[] = { 2 , 6 };
	int b[] = { 24, 36};

	int result = getTotalX( a_count, a, b_count, b );
	printf( "result %d", result);
	return 0;
}


