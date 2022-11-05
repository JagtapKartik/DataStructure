/*
 * main.cpp
 *
 *  Created on: 03-May-2020
 *      Author: Kartik
 */

#include <iostream>

typedef struct node{
	int data;
	struct node *next;
}node_t,*head;

//node_t *head;

node_t *CreateNode(){
	node_t *newnode = new node_t;
	newnode->next = NULL;
	return newnode;
}

int main(void){
	return 0;
}


