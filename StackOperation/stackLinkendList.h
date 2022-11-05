/*
 * stackLinkendList.h
 *
 *  Created on: 03-Jul-2021
 *      Author: Kartik
 */

#ifndef STACKLINKENDLIST_H_
#define STACKLINKENDLIST_H_

#include "statckOperation.h"

typedef struct node
{
	int data;
	node *next;
}node_t;

class stackLinkendList:public statckOperation {
private:
	int top_ptr;
	node_t *head;
public:
	stackLinkendList();
	virtual ~stackLinkendList();
	node_t* create_node( int data );
	void add_node( int data	 );
	void delete_node( void );
	int count_node( void );
	void display_list( void );
	bool is_stack_full( void );
	bool is_stack_empty( void );
	bool pop( void );
	bool push( int data );
	int peek( int index );
	int stack_top( void );
};

#endif /* STACKLINKENDLIST_H_ */
