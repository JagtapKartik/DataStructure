/*
 * Derived.cpp
 *
 *  Created on: 01-Nov-2021
 *      Author: Kartik
 */

#include "Derived.h"

Derived::Derived() {
	// TODO Auto-generated constructor stub
	j=0;
}

Derived::~Derived() {
	// TODO Auto-generated destructor stub
}

void Derived::set_j( int num )
{
	j = num;
}

int Derived::get_j( )
{
	return j;
}


int main( void )
{
	Base *b;
	Derived d;
	b = &d;

	b->set_i(10);
	cout<<b->get_i()<<endl;

	return 0;
}
