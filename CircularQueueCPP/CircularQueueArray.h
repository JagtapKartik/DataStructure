/*
 * CircularQueueArray.h
 *
 *  Created on: 13-Jul-2021
 *      Author: Kartik
 */

#ifndef CIRCULARQUEUEARRAY_H_
#define CIRCULARQUEUEARRAY_H_

#include "CircularQueue.h"

#define SIZE    ( 10 )

class CircularQueueArray : public CircularQueue  {
private:
	int front;
	int rear;
	int Queue[SIZE];
public:
	CircularQueueArray();
	virtual ~CircularQueueArray();
	void enque( int data );
	void dequeue( void );
	void display( void );
};

#endif /* CIRCULARQUEUEARRAY_H_ */
