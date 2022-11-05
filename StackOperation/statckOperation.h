/*
 * statckOperation.h
 *
 *  Created on: 02-Jul-2021
 *      Author: Kartik
 */

#ifndef STATCKOPERATION_H_
#define STATCKOPERATION_H_

#include <iostream>
using namespace std;

#define STACK_SIZE 			 ( 10 )

class statckOperation {

public:
	statckOperation();
	virtual ~statckOperation();
	virtual bool is_stack_full( void ) = 0;
	virtual bool is_stack_empty( void ) = 0;
	virtual bool pop( void ) = 0;
	virtual bool push( int data ) = 0;
	virtual int peek( int index ) = 0;
	virtual int stack_top( void ) = 0;
};

#endif /* STATCKOPERATION_H_ */
