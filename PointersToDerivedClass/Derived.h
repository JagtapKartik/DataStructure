/*
 * Derived.h
 *
 *  Created on: 01-Nov-2021
 *      Author: Kartik
 */

#ifndef DERIVED_H_
#define DERIVED_H_

#include"Base.h"

class Derived: public Base {
private :
	int j;
public:
	Derived();
	void set_j( int num );
	int get_j( void );
	virtual ~Derived();
};

#endif /* DERIVED_H_ */
