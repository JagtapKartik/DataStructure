/*
 * Derived.cpp
 *
 *  Created on: 22-Oct-2021
 *      Author: Kartik
 */

#include "Derived.h"

using namespace std;


Derived::Derived(int temp) {
	// TODO Auto-generated constructor stub
	this->temp = temp;
	cout<<"Derived Constructor"<<this->temp<<endl;
}

Derived::~Derived() {
	// TODO Auto-generated destructor stub
	cout<<"Derived de structor"<<endl;
}

Derived::Derived(const Derived &d)
{
	this->temp = d.temp;
}

int main( void )
{
	int temp = 10;
	Derived d(temp);
	Derived cs(d);
//	Base *b = d;
//	delete(b);
	return 0;
}
