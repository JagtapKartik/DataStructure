/*
 * menu.h
 *
 *  Created on: 02-Jul-2021
 *      Author: Kartik
 */

#ifndef MENU_H_
#define MENU_H_

class menu {
public:
	menu();
	virtual ~menu();
	void main_menu( void );
	void array_sub_menu( void );
	void linkedlist_submenu( void );
	void push( void );
	void peek( void );
};

#endif /* MENU_H_ */
