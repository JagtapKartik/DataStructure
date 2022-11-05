/*
 * Base.cpp
 *
 *  Created on: 08-Nov-2021
 *      Author: Kartik
 */

#include "Base.h"
#include <iostream>

using namespace std;

Base::Base() {
	// TODO Auto-generated constructor stub

}

Base::~Base() {
	// TODO Auto-generated destructor stub
}

template <typename x> void Base::  testfunction( x data)
{
	cout<<"Test Function"<<endl;
}


int main( void )
{
	Base ob;
	int a = 0;
	ob.testfunction( a );
	return 0;
}
