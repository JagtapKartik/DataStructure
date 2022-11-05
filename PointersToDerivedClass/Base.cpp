/*
 * Base.cpp
 *
 *  Created on: 01-Nov-2021
 *      Author: Kartik
 */

#include "Base.h"

Base::Base() {
	// TODO Auto-generated constructor stub
	i=0;
}

Base::~Base() {
	// TODO Auto-generated destructor stub
}

void Base::set_i( int num )
{
	i = num;
}

int Base::get_i( )
{
	return i;
}
