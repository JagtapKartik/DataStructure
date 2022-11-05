/*
 * CircularQueue.h
 *
 *  Created on: 13-Jul-2021
 *      Author: Kartik
 */

#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include<iostream>

using namespace std;

class CircularQueue {
public:
	CircularQueue();
	virtual ~CircularQueue();
	virtual void enque( int data ) = 0;
	virtual void dequeue( void ) = 0;
	virtual void display( void ) = 0;
};

#endif /* CIRCULARQUEUE_H_ */
