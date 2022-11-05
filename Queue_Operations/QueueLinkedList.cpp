/*
 * QueueLinkedList.cpp
 *
 *  Created on: 14-Jul-2021
 *      Author: Kartik
 */

#include "QueueLinkedList.h"

QueueLinkedList::QueueLinkedList() {
	// TODO Auto-generated constructor stub
	front = NULL;
	rear = NULL;
}

QueueLinkedList::~QueueLinkedList() {
	// TODO Auto-generated destructor stub
}

node_t *QueueLinkedList::create_node( int data )
{
	node_t *newnode = new ( node_t );
	if( newnode ==  NULL )
	{

	}
	else
	{
		newnode->data = data;
		newnode->next = NULL;
	}
	return newnode;
}

void QueueLinkedList::add_data( int data )
{
	node_t *newnode = create_node( data );

	if( rear == NULL )
	{
		rear = newnode;
		front = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = rear->next;
	}
}

void QueueLinkedList::delete_data( void )
{
	if( front == NULL )
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node_t *temp = front;
		front = front->next;
		delete( temp );
		temp = NULL;
	}
}

void QueueLinkedList::display_data( void )
{
	if( rear == NULL )
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		node_t *trav = front;
		while( trav != NULL )
		{
			cout<<"["<<trav->data<<"]";
			trav = trav->next;
		}cout<<endl;
	}
}
