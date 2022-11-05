/*
 * TemplateClass.cpp
 *
 *  Created on: 13-Jul-2021
 *      Author: Kartik
 */

#include "TemplateClass.h"

template<class T>
TemplateClass<T>::TemplateClass( T a, T b ) {
	// TODO Auto-generated constructor stub
	first = a;
	second = b;
}

template<class T>
TemplateClass<T>::~TemplateClass() {
	// TODO Auto-generated destructor stub
}

template<class T>
T TemplateClass<T>::add( void )
{
	T result = first + second;
	return result;
}

template<class T>
T TemplateClass<T>::sub( void )
{
	T result = first - second;
	return result;
}

int main( void )
{
	TemplateClass<int> templateclass1( 10, 20 );
	cout<<"Add ["<<templateclass1.add()<<"]"<<endl;
	cout<<"Sub ["<<templateclass1.sub()<<"]"<<endl;

	TemplateClass<float> templateclass2( 10.5, 20.5 );
	cout<<"Add F ["<<templateclass2.add()<<"]"<<endl;
	cout<<"Sub F ["<<templateclass2.sub()<<"]"<<endl;



	return 0;
}
