/*
 *	File Name:	menu.h
 *	Author:		Emanuel Aracena Beriguete
 *	Date Created: 	January 5, 2019
 *	Description:	Menu class interface.
 */

#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>

class Menu
{
public:
	Menu();
	void add_item(std::string item_name);
private:
	//std::vector<Items> items_;
};

#endif	// MENU_H
