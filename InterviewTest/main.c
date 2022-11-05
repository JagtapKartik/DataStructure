#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define SET_BIT( VAR,POS )  VAR |= ( 1 << POS )
#define CLEAR_BIT( VAR, POS ) VAR &= ~( 1 << POS )
#define TOGGLE_BIT( VAR, POS ) VAR ^= ( 1 << POS)
#define TOGGLE_GROUP( VAR, MASK, POS ) VAR ^= ( MASK = MASK << POS )

void swap_byte( int num )
{
	printf("[%x]\n", num);
	//	num = ( ( num >> 8 ) & 0x00FF0000 ) | ( ( num << 8 ) & 0xFF000000 ) | ( num & 0xFFFF );
	num = ( ( num >> 8 ) & 0x0000FF00 ) | ( ( num << 8 ) & 0x00FF0000 ) | ( num & 0xFF0000FF );
	printf("[%x]\n", num);
}

char *string = "Kartik is going to qualcomm";

int find_substring( char *string, char *substring )
{
	if( string != NULL && substring != NULL )
	{
		int string_size = strlen( string );
		int substring_size = strlen( substring);
		int temp = 0;
		for( int i=0;i<string_size;i++)
		{
			if( string[i] == substring[temp] )
			{
				temp++;
			}
			else
			{
				/*Do Nothing*/
			}
		}
		if( temp == substring_size )
		{
			printf("Sub string Found\n");
			return 0;
		}
		else
		{
			printf("Sub string Not Found\n");
		}
	}
	else
	{
		/*Do Nothing*/
	}
	return 1;
}

void swap( int *var1, int *var2 )
{
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void sort_array( int *array, int size )
{
	for(int j=0;j<size;j++)
	{
		for( int i=0;i<size;i++)
		{
			if( array[j] < array[i] )
			{
				swap( array + j, array + i );
			}
		}
	}

	for(int j=0;j<size;j++)
	{
		printf("[%d]",array[j]);
	}printf("\n");
}

#define SIZE 10

int array[SIZE] = { 1,2,4,6,8,3,7,9,0};

int find_missing_element( int *array, int size )
{
	sort_array(array, size);
	for( int i=0;i<size;i++)
	{
		if( (array[i+1]-array[i] ) > 1 )
		{
			printf("Missing Element is [%d]", array[i] + 1);
		}
	}
	return 0;
}

uint32_t get_mask( uint32_t count )
{
	uint32_t mask = 0;
	for( int i=0;i<count;i++)
	{
		mask |= ( 1 << i);
	}
	return mask;
}

uint32_t extract( int num , int startnum, int count )
{
	int mask = get_mask( count );
	num = ( num & ( mask =  (mask << startnum ) ) );
	return ( num >> startnum );
}

int main( void )
{
	//		int var = 0;
	//		SET_BIT( var,  8);
	//		printf("[%x]\n", var);
	//		CLEAR_BIT( var, 8 );
	//		printf("[%x]\n", var);
	//		TOGGLE_BIT( var, 0 );
	//		printf("[%x]\n", var);
	//		int mask = 0xF;
	//		TOGGLE_GROUP( var, mask, 8 );
	//		printf("[%x]\n", var);
	//		int num = 0xABCDEF12;
	//		swap_byte(num);

	//	char *sub_string = "not";
	//	find_substring(string, sub_string);

//	find_missing_element(array, SIZE);
	int num = 0xAB;
	printf("[%x]\n", extract( num, 0, 3 ) );

	volatile uint32_t num2 = 10;
	return 0;
}




