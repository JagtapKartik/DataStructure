/*
 * main.cpp
 *
 *  Created on: 14-Sep-2020
 *      Author: Kartik
 */

#include <stdio.h>
#include <stdbool.h>

int num_count = 0;
bool temp_t = true;

bool check( int *b,int bcount, int tempCount )
{
    bool temp = true;
    int i = 0;
    while( temp )
    {
        if( tempCount >= b[bcount - 1] )
        {
            temp_t = false;
        }
        if( ( b[i] % tempCount == 0 ) )
        {
            i++;
            if( i == bcount )
            {
                if( tempCount == b[bcount] )
                {
                    temp = false;
                }
                return true;
            }
        }
        else
        {
            temp = false;
        }
    }
    return false;
}

int getTotalX(int a_count, int* a, int b_count, int* b) {
    int count = 0;
        int tempCount = 2;
    int i = 0;
    while( temp_t )
    {
        if( ( tempCount % a[i] == 0 ) )
        {
            i++;
            if( i == a_count ){
                if( check( b, b_count,tempCount ) ){
                    num_count++;
                    i=0;
                    tempCount++;
                }
            }
        }
        else
        {
            i = 0;
            tempCount++;
        }
    }
    return count = num_count;
}

int main(void)
{
	int a[2] = {3,4};
	int b[2] = {24,48};
//	printf("Ret %d\n",retx(2,a,2,b));

	printf("num_count[%d]\n",getTotalX(2,a,2,b));
	return 0;
}





