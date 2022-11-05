
#include<stdio.h>
#include<stdint.h>


int arr[] = { 10,20,30,40,50,60 };

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = ( l + r )  / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int finbonacci( int max )
{
	int ret = 0;

	int first = 0;
	int second = 1;
	int third = first + second;

	printf("1 [%d]\n", first);
	printf("2 [%d]\n", second);

	for( int i=3;i<=max;i++ )
	{
		printf("%d [%d]\n", i ,third);
		first = second;
		second = third;
		third = first + second;
	}
	return ret;
}

void recursiveFunction( int max )
{
	if( max <= 1 )
	{
		printf("[%d]", max - 1 );
	}
	else
	{
		printf("[%d]", max - 1 );
		recursiveFunction(max -1);
	}
}

int main( void )
{
//	int size = 6;
//	int x = 20;
//	int result = binarySearch(arr, 0, size - 1, x);
//	( result == -1 ) ? printf("Element not found\n"):printf("Element Found at[%d]\n", result);
//	finbonacci(10);
	recursiveFunction(10);
	while(1);
	return 0;
}



