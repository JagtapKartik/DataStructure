/*
 * TemplateClass.h
 *
 *  Created on: 13-Jul-2021
 *      Author: Kartik
 */

#ifndef TEMPLATECLASS_H_
#define TEMPLATECLASS_H_

#include <iostream>

using namespace std;

template<class T>
class TemplateClass {
	T first;
	T second;
public:
	TemplateClass(T a, T b);
	virtual ~TemplateClass();
	T add( void );
	T sub( void );
};

#endif /* TEMPLATECLASS_H_ */
