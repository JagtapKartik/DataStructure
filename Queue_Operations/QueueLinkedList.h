/*
 * QueueLinkedList.h
 *
 *  Created on: 14-Jul-2021
 *      Author: Kartik
 */

#ifndef QUEUELINKEDLIST_H_
#define QUEUELINKEDLIST_H_

#include "QueueOpertaions.h"

typedef struct node
{
	int data;
	node *next;
}node_t;

class QueueLinkedList: public QueueOpertaions {
private :
	node_t *front;
	node_t *rear;
public:
	QueueLinkedList();
	virtual ~QueueLinkedList();
	node_t* create_node( int data );
	void add_data( int data );
	void delete_data( void );
	void display_data( void );
};

#endif /* QUEUELINKEDLIST_H_ */
