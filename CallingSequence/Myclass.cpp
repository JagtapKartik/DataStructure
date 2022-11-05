/*
 * Myclass.cpp
 *
 *  Created on: 26-Oct-2021
 *      Author: Kartik
 */

#include "Myclass.h"
#include <iostream>

using namespace std;

class Myclass {
private:
	int temp;
public:
	Myclass(int i);
	virtual ~Myclass();
}global_ibj(1), global_obj(2);

Myclass::Myclass(int i) {
	cout<<"Constructor "<< i <<"Called"<<endl;
	temp = i;
}

Myclass::~Myclass() {
	cout<<"De structor "<< temp <<"Called"<<endl;
}


void number_palindrome( int num )
{
	char *palindrome_holder =  (char *)malloc( 32 );
	int i=32-1;
	while( num )
	{
		printf("[%d]", num & 1);
		palindrome_holder[i--] = num & 1;
		num = num >> 1;
	}
	for( int i=0;i<32;i++)
	{
		printf("[%d]", palindrome_holder[i]);
	}printf("\n");
}

//ABCDEF12

void byte_shift( int i )
{
	i |=  ( ( i & 0xFF00) >> 8 ) | ( ( i & 0xFF) << 8 );
//				EF						1200
	printf("[%x]\n", i);
}

int main( void )
{
//	Myclass local_obj(3);

	int a = 0xABCDEF12;
//	int count =0;
//	while( a )
//	{
//		if( a & 1 )
//		{
//			count++;
//		}
//		a = a>>1;
//	}
//	cout<<count<<endl;

//	number_palindrome(a);
	byte_shift(a);
	return 0;
}
