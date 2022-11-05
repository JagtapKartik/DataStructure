/*
 * OperatorClass.cpp
 *
 *  Created on: 02-Nov-2021
 *      Author: Kartik
 */

#include "OperatorClass.h"
#include <iostream>

using namespace std;

OperatorClass::OperatorClass( ) {

}

OperatorClass::OperatorClass( int lon, int lat ) {
	// TODO Auto-generated constructor stub
	longitude = lon;
	latitude = lat;
}

OperatorClass::~OperatorClass() {
	// TODO Auto-generated destructor stub
}

OperatorClass OperatorClass::operator +( OperatorClass obj )
{
	OperatorClass temp;
	temp.longitude = obj.longitude + longitude;
	temp.latitude = obj.latitude + latitude;
	return temp;
}

OperatorClass OperatorClass::operator -( OperatorClass obj )
{
	OperatorClass temp;
	temp.longitude = obj.longitude - longitude;
	temp.latitude = obj.latitude - latitude;
	return temp;
}

OperatorClass OperatorClass::operator *( OperatorClass obj )
{
	OperatorClass temp;
	temp.longitude = obj.longitude * longitude;
	temp.latitude = obj.latitude * latitude;
	return temp;
}

void OperatorClass::show( void )
{
	cout<< longitude<<" "<< latitude<<endl;
}

int main( void )
{
	OperatorClass obj1( 10,20 ), obj2( 80, 90 );
//	obj1 = obj1 + obj2;
//	obj1.show();
//	obj1 = obj1 - obj2;
//	obj1.show();
	obj1 = obj1 * obj2;
	obj1.show();
	return 0;
}
