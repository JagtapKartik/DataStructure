/*
 * Temp.cpp
 *
 *  Created on: 01-Nov-2021
 *      Author: Kartik
 */

#include "Temp.h"
#include <iostream>

using namespace std;

Temp::Temp( int i) {
	// TODO Auto-generated constructor stub
	one = i;
}

Temp::~Temp() {
	// TODO Auto-generated destructor stub
}


int Temp::double_val()
{
	return one + one;
}


int main( void )
{
	int Temp::*oneptr; // class data member pointer
	int ( Temp :: *function_ptr) ( ); //class function pointer

	Temp ob1(1), ob2(2);

	oneptr = &Temp::one;
	function_ptr = &Temp::double_val;

	cout<<"values" <<ob1.*oneptr<<" "<<ob2.*oneptr<< endl;
	cout<<"Double Values"<< ( ob1.*function_ptr ) ()  <<" "<<( ob2.*function_ptr ) ();

	return 0;
}
