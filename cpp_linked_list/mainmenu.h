/*
 * mainmenu.h
 *
 *  Created on: 15-Aug-2020
 *      Author: Kartik
 */

#ifndef MAINMENU_H_
#define MAINMENU_H_

#include <stdint.h>

typedef enum
{
	eLL_SUCCESS,
	eLL_FAILED
}TLLret;

class main_menu {
public:
	main_menu();
	virtual ~main_menu();
	virtual TLLret add_node_to_first_location(int data) = 0;
	virtual TLLret add_node_to_last_location(int data) = 0;
	virtual TLLret add_node_to_specific_location(int location,int data) = 0;
	virtual TLLret delete_node_from_first_location(void) = 0;
	virtual TLLret delete_node_from_last_location(void) = 0;
	virtual TLLret delete_node_from_specific_location(int location) = 0;
	virtual TLLret display_list() = 0;
	virtual uint32_t count_node() = 0;
	virtual void main_menu_list() = 0;
};

#endif /* MAINMENU_H_ */
