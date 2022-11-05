/*
 * slinglylinkedlist.cpp
 *
 *  Created on: 15-Aug-2020
 *      Author: Kartik
 */

#include <iostream>
#include "slinglylinkedlist.h"

using namespace std;

#define LOG(data) printf(data"\n")



singly_linked_list::singly_linked_list() {
	// TODO Auto-generated constructor stub
	head = NULL;
}

singly_linked_list::~singly_linked_list() {
	// TODO Auto-generated destructor stub
}

snode_t* singly_linked_list::create_node(int data)
{
	snode_t *newnode = new snode_t;
	if(newnode == NULL)
	{
		cout<<" Insufficeint memory"<<endl;
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

TLLret singly_linked_list::add_node_to_first_location(int data)
{
	LOG("add_node_to_first_location start");
	TLLret status = eLL_SUCCESS;
	snode_t *newnode = create_node(data);
	if(newnode == NULL)
		status = eLL_FAILED;

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
	LOG("add_node_to_first_location end");
	return status;
}

TLLret singly_linked_list:: add_node_to_last_location(int data)
{
	LOG("add_node_to_last_location start");
	TLLret status = eLL_SUCCESS;
	snode_t *newnode = create_node(data);
	if(newnode == NULL)
		return eLL_FAILED;

	if(head == NULL)
	{
		head = newnode;
	}
	else
	{
		snode_t *trav = head;
		while( trav->next != NULL)
		{
			trav = trav->next;
		}
		trav->next = newnode;
	}
	LOG("add_node_to_last_location end");
	return status;
}

TLLret singly_linked_list::add_node_to_specific_location(int location,int data)
{
	LOG("add_node_to_specific_location start");
	TLLret status = eLL_SUCCESS;
	snode_t *trav = NULL;
	uint32_t count = 1;
	if(location == 1){
		add_node_to_first_location(data);
	}
	else if( (uint32_t) location == count_node() + 1){
		add_node_to_last_location(data);
	}
	else{
		trav = head;
		snode_t *newnode = create_node(data);
		while( count < ((uint32_t)location - 1))
		{
			trav = trav->next;
			count++;
		}
		newnode->next = trav->next;
		trav->next = newnode;
	}
	LOG("add_node_to_specific_location end");
	return status;
}

TLLret singly_linked_list::delete_node_from_first_location(void)
{
	LOG("delete_node_from_first_location start");
	TLLret status = eLL_SUCCESS;
	if(head->next == NULL)
	{
		head = NULL;
		delete(head);
	}
	else
	{
		snode_t *temp = head;
		head = temp->next;
		delete(temp);
	}
	LOG("delete_node_from_first_location end");
	return status;
}

TLLret singly_linked_list::delete_node_from_last_location(void)
{
	LOG("delete_node_from_last_location start");
	TLLret status = eLL_SUCCESS;
	if(head->next == NULL)
	{
		head = NULL;
		delete(head);
	}
	else
	{
		snode_t *tarv = head;
		snode_t *temp = NULL;
		while( tarv->next->next != NULL)
		{
			tarv = tarv->next;
		}
		temp = tarv->next;
		tarv->next = NULL;
		delete(temp);
	}
	LOG("delete_node_from_last_location end");
	return status;
}

TLLret singly_linked_list::delete_node_from_specific_location(int location)
{
	TLLret status = eLL_SUCCESS;
	LOG("delete_node_from_specific_location start");
	if(location == 1)
	{
		delete_node_from_first_location();
	}
	else if( (uint32_t) location == count_node() )
	{
		delete_node_from_last_location();
	}
	else
	{
		snode_t *trav = head;
		snode_t *temp = NULL;
		uint32_t count = 0;
		while(count == (uint32_t) location-1)
		{
			trav = trav->next;
			count++;
		}
		temp = trav->next;
		trav->next = temp->next;
		delete(temp);
	}
	LOG("delete_node_from_specific_location end");
	return status;
}

TLLret singly_linked_list::display_list()
{
	LOG("display_list start");
	TLLret status = eLL_SUCCESS;
	snode_t *trav = head;
	while( trav!= NULL)
	{
		cout <<"\t"<<trav->data;
		trav = trav->next;
	}cout<<endl;
	LOG("display_list end");
	return status;
}

uint32_t singly_linked_list::count_node()
{
	LOG("count_node start");
	uint32_t list_count = 0;
	snode_t *trav = head;
	while(trav->next != NULL)
	{
		trav=trav->next;
		list_count ++;
	}
	printf("list count %d\n",list_count);
	LOG("count_node end");
	return list_count;
}

void singly_linked_list::main_menu_list()
{
	cout<<"Singly Linked List"<<endl;
	cout<<"1. Add node "<<endl;
	cout<<"2. Delete node "<<endl;
	cout<<"3. Display List"<<endl;
}

void singly_linked_list::add_list_menu()
{
	cout<<"1. Please Enter Location and data "<<endl;
}

void singly_linked_list::delete_node_menu()
{
	cout<<"1. Please Enter Location"<<endl;
}

int main()
{
	main_menu *mmSLL;
	singly_linked_list singlyLinkedList;
	mmSLL = &singlyLinkedList;
	uint32_t s_case = 0;
	uint32_t location = 0;
	uint32_t data = 0;
	while(1)
	{
		mmSLL->main_menu_list();
		cin>>s_case;
		switch(s_case)
		{
		case 1:
		{
			singlyLinkedList.add_list_menu();
			cout<<"Location"<<endl;
			cin>>location;
			cout<<"Data"<<endl;
			cin>>data;
			mmSLL->add_node_to_specific_location(location,data);
		}
		break;
		case 2:
		{
			singlyLinkedList.delete_node_menu();
			LOG("Location");
			cin>>location;
			mmSLL->delete_node_from_specific_location(location);
		}
		break;
		case 3:
		{
			mmSLL->display_list();
		}
		break;
		default:
		{
			cout<<"Incorrect Option"<<endl;
		}
		break;
		}
	}
	return 0;
}
