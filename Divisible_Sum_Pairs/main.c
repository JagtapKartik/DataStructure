

#include <stdio.h>

int main( void )
{
	int count = 6;
	int arr[6] = {1,2,3,4,5,6};
	int k = 5, result = 0;
	for( int i=0;i<count;i++)
	{
		for( int j=i+1;j<count;j++)
		{
			int temp = arr[i] + arr[j];
			if( ( temp % k )  == 0)
			{
				result++;
			}
		}
	}
	printf( "result %d\n",result);
	return 0;
}




