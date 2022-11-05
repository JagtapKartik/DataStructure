/*
 * QueueOpertaions.h
 *
 *  Created on: 09-Jul-2021
 *      Author: Kartik
 */

#ifndef QUEUEOPERTAIONS_H_
#define QUEUEOPERTAIONS_H_

#include <iostream>
using namespace std;

class QueueOpertaions {
public:

	QueueOpertaions();
	virtual ~QueueOpertaions();
	virtual void add_data( int data ) = 0;
	virtual void delete_data( void ) = 0;
	virtual void display_data( void ) = 0;
};

#endif /* QUEUEOPERTAIONS_H_ */
