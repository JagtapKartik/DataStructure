/*
 * Base.h
 *
 *  Created on: 01-Nov-2021
 *      Author: Kartik
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>

using namespace std;

class Base {
	int i;
public:
	Base();
	void set_i( int num );
	int get_i( void );
	virtual ~Base();
};

#endif /* BASE_H_ */
