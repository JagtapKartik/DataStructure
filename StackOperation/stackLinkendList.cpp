/*
 * stackLinkendList.cpp
 *
 *  Created on: 03-Jul-2021
 *      Author: Kartik
 */

#include "stackLinkendList.h"

stackLinkendList::stackLinkendList() {
	// TODO Auto-generated constructor stub
	top_ptr = 0;
	head = NULL;
}

stackLinkendList::~stackLinkendList() {
	// TODO Auto-generated destructor stub
}

node_t* stackLinkendList::create_node( int data )
{
	node_t *temp = new (node_t);
	if( NULL == temp )
	{
		return 0;
	}
	else
	{
		temp->data = data;
		temp->next = NULL;
	}
	return temp;
}

void stackLinkendList::add_node( int data )
{
	node_t *node = create_node( data );
	if( node == NULL )
	{
		cout<<"No Memory in system"<<endl;
	}
	else
	{
		if( NULL == head )
		{
			head = node;
			top_ptr++;
		}
		else
		{
			node_t *trav = head;
			while( trav->next != NULL )
			{
				trav = trav->next;
			}
			trav->next = node;
			top_ptr++;
		}
	}
}

void stackLinkendList::delete_node( void )
{
	if( NULL == head )
	{
		cout<<"Stack is empty";
	}
	else if( NULL == head->next )
	{
		delete( head );
		head = NULL;
		top_ptr--;
	}
	else
	{
		node_t *trav = head;
		node_t *temp = NULL;
		while( trav->next->next != NULL )
		{
			trav = trav->next;
		}
		temp = trav->next;
		delete( temp );
		trav->next = NULL;
		top_ptr--;
		cout<<"top ptr"<<top_ptr<<endl;
	}
}

bool stackLinkendList::is_stack_full( void )
{
	bool ret = true;
	if( top_ptr == STACK_SIZE )
	{
		ret = false;
	}
	else
	{
		ret = true;
	}
	return ret;
}

bool stackLinkendList::is_stack_empty( void )
{
	bool ret = true;
	if( top_ptr == 0 )
	{
		ret = false;
	}
	else
	{
		ret = true;
	}
	return ret;
}

bool stackLinkendList::pop( void )
{
	bool ret = true;

	if( is_stack_empty( ) )
	{
		delete_node();
	}
	else
	{
		ret = false;
	}
	return ret;
}

bool stackLinkendList::push( int data )
{
	bool ret = true;
	if( is_stack_full() )
	{
		add_node( data );
	}
	else
	{
		ret = false;
	}
	return ret;
}

int stackLinkendList::count_node( void )
{
	int count  = 0;
	node_t *trav = head;
	while( trav != NULL )
	{
		trav = trav->next;
		count++;
	}
	return count;
}

int stackLinkendList::peek( int index )
{
	int count = count_node();
	cout<<"count ["<<count<<"]"<<endl;
	int data = 0;
	int tempCount = 0;
	if( index > count )
	{
		cout<<"Index not available"<<endl;
	}
	else
	{
		node_t *trav = head;
		while( trav != NULL )
		{
			tempCount++;
			if ( tempCount == index )
			{
				data = trav->data;
			}
			else
			{
				/*Do Nothing*/
			}
			trav = trav->next;
		}
	}
	return data;
}

int stackLinkendList::stack_top( void )
{
	node_t *trav = head;
	int data = 0;
	while( trav->next != NULL )
	{
		trav = trav->next;
	}
	data = trav->data;
	return data;
}

void stackLinkendList::display_list( void )
{
	node_t *trav = head;
	while( trav != NULL )
	{
		cout<<"["<<trav->data<<"]";
		trav = trav->next;
	}cout<<endl;
}
