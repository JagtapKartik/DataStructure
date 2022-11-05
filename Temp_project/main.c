
#include <stdio.h>

static int variable = 0;

void function( int variable1 )
{
	variable = variable1;
}

void print()
{
	printf( "[%d]\n", variable );
}



