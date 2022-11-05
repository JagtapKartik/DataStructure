/*
 * QueueArray.h
 *
 *  Created on: 09-Jul-2021
 *      Author: Kartik
 */


#ifndef QUEUEARRAY_H_
#define QUEUEARRAY_H_

#include "QueueOpertaions.h"

#define QUEUE_SIZE     ( 10 )

class QueueArray: public QueueOpertaions {
private:
	int queue_size;
	int queue[QUEUE_SIZE];
	int front;
	int rear;
public:
	QueueArray();
	virtual ~QueueArray();
	void add_data( int data );
	void delete_data( void );
	void display_data( void );
	void shift_data_after_delete( void );
};

#endif /* QUEUEARRAY_H_ */
