/*
 * slinglylinkedlist.h
 *
 *  Created on: 15-Aug-2020
 *      Author: Kartik
 */

#ifndef SLINGLYLINKEDLIST_H_
#define SLINGLYLINKEDLIST_H_

#include "mainmenu.h"

typedef struct snode
{
	int data;
	struct snode *next;
}snode_t;

class singly_linked_list : public main_menu{
private:
	snode_t *head;
public:
	singly_linked_list();
	virtual ~singly_linked_list();
	snode_t *create_node(int data);
	TLLret add_node_to_first_location(int data);
	TLLret add_node_to_last_location(int data);
	TLLret add_node_to_specific_location(int location,int data);
	TLLret delete_node_from_first_location(void);
	TLLret delete_node_from_last_location(void);
	TLLret delete_node_from_specific_location(int location);
	uint32_t count_node();
	TLLret display_list();
	void main_menu_list();
	void add_list_menu();
	void delete_node_menu();
};

#endif /* SLINGLYLINKEDLIST_H_ */
