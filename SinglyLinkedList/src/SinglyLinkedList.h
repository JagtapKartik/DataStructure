/*
 * SinglyLinkedList.h
 *
 *  Created on: 08-Mar-2020
 *      Author: Kartik
 */

#include "List.h"

#ifndef SINGLYLINKEDLIST_H_
#define SINGLYLINKEDLIST_H_

typedef enum{
	ADD = 1,
	DELETE,
	DISPLAY
}LIST;

class SinglyLinkedList :public List {
private:
	node_t *create_node(int data);
	node_t *head;
	int data,position;
public:
	SinglyLinkedList();
	virtual ~SinglyLinkedList();
	void add_node_to_the_last(int data);
	void add_node_to_the_first(int data);
	void add_node_to_the_specific_pos(int pos,int data);
	void delete_node_to_the_last();
	void delete_node_to_the_first();
	void delete_node_to_the_specific_pos(int pos);
	void reverse_list();
	void display_list();
	int count_node_in_list();
	void add_list_menu();
	void delete_list_menu();
	void main_menu();
};

#endif /* SINGLYLINKEDLIST_H_ */
