/*
 * SinglyLinkedList.cpp
 *
 *  Created on: 08-Mar-2020
 *      Author: Kartik
 */

#include "SinglyLinkedList.h"

using namespace std;

#define DEMO

#ifdef DEMO
#define PRINT(TEXT)  printf(TEXT"\n")
#else
#define PRINT(TEXT)  printf(" ")
#endif



SinglyLinkedList::SinglyLinkedList() {
	// TODO Auto-generated constructor stub
	head = NULL;
	data = 0;
	position = 0;
}

SinglyLinkedList::~SinglyLinkedList() {
	// TODO Auto-generated destructor stub
}

node_t *SinglyLinkedList::create_node(int data){
	PRINT("Create Node START");
	node_t *newnode = new node_t;
	newnode->data = data;
	newnode->next = NULL;
	PRINT("Create Node END");
	return newnode;
}

void SinglyLinkedList::add_node_to_the_last(int data){
	PRINT("Add Node last START");
	node_t *newnode = create_node(data);
	if(head == NULL){
		head = newnode;
	}else{
		node_t *trav = head;
		while(trav->next != NULL){
			trav = trav->next;
		}
		trav->next = newnode;
	}
	PRINT("Add Node last END");
}

void SinglyLinkedList::add_node_to_the_first(int data){
	PRINT("Add Node first START");
	node_t *newnode = create_node(data);
	if(head == NULL){
		head = newnode;
	}else{
		newnode->next = head;
		head = newnode;
	}
	PRINT("Add Node first END");
}

void SinglyLinkedList::add_node_to_the_specific_pos(int pos,int data){
	PRINT("add_node_to_the_specific_pos START");
	if(pos == 1){
		add_node_to_the_first(data);
	}else if(pos == count_node_in_list() + 1 ){
		add_node_to_the_last(data);
	}else{
		node_t *trav = head;
		node_t *newnode = create_node(data);
		int count = 1;
		while(count < pos - 1){
			trav = trav->next;
			count ++;
		}
		newnode->next = trav->next;
		trav->next = newnode;
	}

	PRINT("add_node_to_the_specific_pos END");
}

void SinglyLinkedList::delete_node_to_the_last(){
	PRINT("delete_node_to_the_last START");
	if(head == NULL){
		delete(head);
		head = NULL;
	}else{
		node_t *trav = head;
		while(trav->next->next != NULL){
			trav = trav->next;
		}
	}
	PRINT("delete_node_to_the_last END");
}

void SinglyLinkedList::delete_node_to_the_first(){
	PRINT("delete_node_to_the_first START");
	if(head == NULL){
		delete(head);
		head = NULL;
	}else{
		node_t *temp = head;
		head = head->next;
		delete(temp);
	}
	PRINT("delete_node_to_the_first END");
}

void SinglyLinkedList::delete_node_to_the_specific_pos(int pos){

}

void SinglyLinkedList::reverse_list(){

}

void SinglyLinkedList::display_list(){
	PRINT("display_list START");
	node_t *trav = head;
	while(trav != NULL){
		printf(" %4d",trav->data);
		trav = trav->next;
	}printf("\n");
	PRINT("display_list  END");
}

int SinglyLinkedList::count_node_in_list(){
	PRINT("count_node_in_list START");
	int count = 0;
	node_t *trav = head;
	while(trav->next != NULL){
		trav = trav->next;
		count ++;
	}
	printf("count list %d\n",count);
	PRINT("count_node_in_list  END");
	return count;
}

void SinglyLinkedList::add_list_menu(){
	PRINT("Add_list_menu START");
	cout << "INSERT DATA " << endl;
	cin>>data;
	cout << "INSERT POSITION " << endl;
	cin>>position;
	add_node_to_the_specific_pos(position,data);
	PRINT("Add_list_menu  END");
}

void SinglyLinkedList::delete_list_menu(){
	PRINT("delete_list_menu START");
	cout << "INSERT POSITION " << endl;
	cin>>position;
	if(position){
		delete_node_to_the_first();
	}else if(position == count_node_in_list()){
		delete_node_to_the_last();
	}else{
		delete_node_to_the_specific_pos(position);
	}
	PRINT("delete_list_menu  END");
}

void SinglyLinkedList::main_menu(){
	cout << " LINKED LIST BY HARD CORE CODER" << endl;
	cout << "1. ADD NODE TO LIST " << endl;
	cout << "2. DELETE NODE FROM LIST " << endl;
	cout << "3. DISPLAY LIST " << endl;
}

SinglyLinkedList SLL;
int input;

int main(void){
	while(1){
		SLL.main_menu();
		cin>>input;
		switch(input){
		case DISPLAY:
			SLL.display_list();
			break;
		case ADD:
			SLL.add_list_menu();
			break;
		case DELETE:
			SLL.delete_list_menu();
			break;
		default:
			break;
		}
	}
	return 0;
}
