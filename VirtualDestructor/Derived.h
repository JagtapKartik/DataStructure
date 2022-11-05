/*
 * Derived.h
 *
 *  Created on: 22-Oct-2021
 *      Author: Kartik
 */

#ifndef DERIVED_H_
#define DERIVED_H_

#include "Base.h"

class Derived: public Base {
private:
	int temp;
public:
	Derived(int temp);
	~Derived();
	Derived( const Derived &d );
};

#endif /* DERIVED_H_ */
