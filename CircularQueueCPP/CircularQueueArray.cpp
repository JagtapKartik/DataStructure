/*
 * CircularQueueArray.cpp
 *
 *  Created on: 13-Jul-2021
 *      Author: Kartik
 */

#include "CircularQueueArray.h"
#include <stdlib.h>
#include <string.h>

CircularQueueArray::CircularQueueArray() {
	// TODO Auto-generated constructor stub
	front = 0;
	rear = 0;
	memset( Queue, 0, sizeof(Queue));
}

CircularQueueArray::~CircularQueueArray() {
	// TODO Auto-generated destructor stub
}

void CircularQueueArray::enque( int data )
{
	if( ( ( rear + 1 ) % SIZE)  == front )
	{
		cout<<"Queue is full"<<endl;
	}
	else
	{
		rear = ( rear + 1 ) % SIZE;
		Queue[rear] = data;
	}
}
void CircularQueueArray::dequeue( void )
{
	if( front == rear)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		front = ( front + 1 ) % SIZE;
		Queue[front] = 0;
	}
}

void CircularQueueArray::display( void )
{
	for( int i = 0; i < SIZE ;i++ )
	{
		cout<<"["<<Queue[i]<<"]";
	}cout<<endl;
}

int main( void )
{
	int data = 0;
	CircularQueueArray Q;
	while(1)
	{
		cout<<"Please select option"<<endl;
		cout<<"1.Add"<<endl;
		cout<<"2.Delete"<<endl;
		cin>>data;
		switch( data )
		{
		case 1:
		{
			cout<<"Please enter data"<<endl;
			cin>>data;
			Q.enque(data);
			Q.display();
		}
		break;

		case 2:
		{
			Q.dequeue();
			Q.display();
		}
		break;

		default:
		{

		}
		break;
		}
	}

}
