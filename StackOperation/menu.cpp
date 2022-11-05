/*
 * menu.cpp
 *
 *  Created on: 02-Jul-2021
 *      Author: Kartik
 */

#include "menu.h"
#include "stackArray.h"
#include "stackLinkendList.h"

stackArray stackArray_t;
stackLinkendList linkedlist;

menu::menu() {
	// TODO Auto-generated constructor stub

}

menu::~menu() {
	// TODO Auto-generated destructor stub
}

void menu::main_menu( void )
{
	cout<<"Please select option"<<endl;
	cout<<"1.Stack using Array"<<endl;
	cout<<"2.Stack using Linked List"<<endl;
}

void menu::array_sub_menu( void )
{
	int data = 0;
	cout<<"Please select option"<<endl;
	cout<<"1.PUSH"<<endl;
	cout<<"2.POP"<<endl;
	cout<<"3.PEEK"<<endl;
	cout<<"4.TOP"<<endl;
	cin>>data;

	switch( data )
	{
	case 1:
	{
		cout<<"Please Enter Number"<<endl;
		cin>>data;
		if( stackArray_t.push( data ) )
		{
			stackArray_t.display_array();
		}
	}
	break;
	case 2:
	{
		if( stackArray_t.pop() )
		{
			stackArray_t.display_array();
		}
	}
	break;
	case 3:
	{
		cout<<"Please Enter Index"<<endl;
		cin>>data;
		cout<<"["<<stackArray_t.peek(data)<<"]"<<endl;
	}
	break;
	case 4:
	{
		cout<<"Stack Top ["<<stackArray_t.stack_top()<<"]"<<endl;
	}
	break;
	}
}

void menu::linkedlist_submenu( void )
{
	int data = 0;
	cout<<"Please select option"<<endl;
	cout<<"1.PUSH"<<endl;
	cout<<"2.POP"<<endl;
	cout<<"3.PEEK"<<endl;
	cout<<"4.TOP"<<endl;
	cout<<"5.Display"<<endl;
	cin>>data;

	switch( data )
	{
	case 1:
	{
		cout<<"Please Enter Number"<<endl;
		cin>>data;
		linkedlist.push( data);
		linkedlist.display_list();
	}
	break;
	case 2:
	{
		linkedlist.delete_node();
		linkedlist.display_list();
	}
	break;
	case 3:
	{
		cout<<"Please Enter Position"<<endl;
		cin>>data;
		cout<<"["<<linkedlist.peek(data)<<"]"<<endl;
	}
	break;
	case 4:
	{
		cout<<"["<<linkedlist.stack_top()<<"]"<<endl;
	}
	break;
	case 5:
	{
		linkedlist.display_list();
	}
	break;
	}
}

void menu::push( void )
{
	cout<<"Please Enter Number to Push"<<endl;
}

void menu::peek( void )
{
	cout<<"Please Enter Position to Peek"<<endl;
}
