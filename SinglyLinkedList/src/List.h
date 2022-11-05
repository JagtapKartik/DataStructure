/*
 * List.h
 *
 *  Created on: 08-Mar-2020
 *      Author: Kartik
 */

#include <iostream>

#ifndef LIST_H_
#define LIST_H_

typedef struct node{
	int data;
	struct node *next;
}node_t;


class List {
public:
	List();
	virtual ~List();
	virtual node_t *create_node(int data) = 0;
	virtual void add_node_to_the_last(int data) = 0;
	virtual void add_node_to_the_first(int data) = 0;
	virtual void add_node_to_the_specific_pos(int pos,int data) = 0;
	virtual void delete_node_to_the_last() = 0;
	virtual void delete_node_to_the_first() = 0;
	virtual void delete_node_to_the_specific_pos(int pos) = 0;
	virtual void reverse_list() = 0;
	virtual void display_list() = 0;
	virtual int count_node_in_list() = 0;
	virtual void add_list_menu() = 0;
	virtual void delete_list_menu() = 0;
	virtual void main_menu() = 0;
};

#endif /* LIST_H_ */
