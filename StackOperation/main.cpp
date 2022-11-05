/*
 * main.cpp
 *
 *  Created on: 02-Jul-2021
 *      Author: Kartik
 */

#include"stackArray.h"
#include<stdlib.h>
#include "menu.h"

menu menu_t;

int main( void )
{
	system("Color 0A");
	int num = 0;
	while( 1 )
	{
		cout<<"Please select option"<<endl;
		menu_t.main_menu();
		cin>>num;

		switch ( num )
		{
		case 1:
		{
			menu_t.array_sub_menu();
			num = 0;
		}
		break;

		case 2:
		{
			menu_t.linkedlist_submenu();
			num = 0;
		}
		break;
		}
		cout<<endl;
	}
	return 0;
}


