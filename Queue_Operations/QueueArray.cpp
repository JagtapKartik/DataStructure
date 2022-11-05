/*
 * QueueArray.cpp
 *
 *  Created on: 09-Jul-2021
 *      Author: Kartik
 */

#include "QueueArray.h"

QueueArray::QueueArray() {
	// TODO Auto-generated constructor stub
	queue_size = 0;
	front = -1;
	rear = -1;
}

QueueArray::~QueueArray() {
	// TODO Auto-generated destructor stub
}

void QueueArray::add_data( int data )
{
	if( ( QUEUE_SIZE - 1 ) == rear )
	{
		cout<<"Queue is full"<<endl;
	}
	else
	{
		rear++;
		queue[rear] = data;
	}
}

void QueueArray::delete_data( void )
{
	if( front == rear )
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		front++;
		queue[front] = 0;
	}
}

void QueueArray::display_data( void )
{
	if( front == rear )
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		for( int i = front+1;i<rear+1;i++)
		{
			cout<<"["<<queue[i]<<"]";
		}cout<<endl;
	}
}
