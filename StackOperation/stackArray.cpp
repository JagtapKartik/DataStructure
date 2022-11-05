/*
 * stackArray.cpp
 *
 *  Created on: 02-Jul-2021
 *      Author: Kartik
 */

#include "stackArray.h"

stackArray::stackArray() {
	// TODO Auto-generated constructor stub
	top_ptr = 0;
	stack[0] = 0;
}

stackArray::~stackArray() {
	// TODO Auto-generated destructor stub
}

bool stackArray::is_stack_full( void )
{
	bool ret = true;
	if( STACK_SIZE == top_ptr)
	{
		/*Do Nothing*/
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool stackArray::is_stack_empty( void )
{
	bool ret = true;
	if( 0 == top_ptr )
	{
		/*Do Nothing*/
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool stackArray::pop( void )
{
	bool ret = true;
	if( true == is_stack_empty() )
	{
		cout<<"Stack is empty"<<endl;
		ret = false;
	}
	else
	{
		cout<<"Element ["<<stack[top_ptr - 1]<<"] pop"<<endl;
		stack[top_ptr - 1] = 0;
		top_ptr --;
	}
	return ret;
}

bool stackArray::push( int data )
{
	bool ret = true;
	if( true == is_stack_full() )
	{
		cout<<"Stack is full"<<endl;
		ret = false;
	}
	else
	{
		stack[top_ptr] = data;
//		cout<<"Element ["<<stack[top_ptr]<<"] push"<<endl;
		top_ptr++;
	}
	return ret;
}

int stackArray::peek( int index )
{
	if( index > STACK_SIZE )
	{
		return stack[top_ptr];
	}
	else if( index < 0 )
	{
		return stack[0];
	}
	return stack[index - 1];
}

int stackArray::stack_top( void )
{
	return stack[top_ptr- 1];
}

void stackArray::display_array( void )
{
	for( int i=0;i<STACK_SIZE;i++)
	{
		cout<<"["<<stack[i]<<"]";
	}cout<<endl;
}
