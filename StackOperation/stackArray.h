/*
 * stackArray.h
 *
 *  Created on: 02-Jul-2021
 *      Author: Kartik
 */

#ifndef STACKARRAY_H_
#define STACKARRAY_H_

#include"statckOperation.h"

class stackArray: public statckOperation {
private:
	int top_ptr;
	int stack[STACK_SIZE];
public:
	stackArray();
	virtual ~stackArray();
	bool is_stack_full( void );
	bool is_stack_empty( void );
	bool pop( void );
	bool push( int data );
	int peek( int index );
	int stack_top( void );
	void display_array( void);
};

#endif /* STACKARRAY_H_ */
