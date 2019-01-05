/*
 *	File Name:	application.h
 *	Author:		Emanuel Aracena
 *	Date Created: 	January 3, 2019
 *	Description:	Application class interface.
 */
#ifndef APPLICATION_H
#define APPLICATION_H

#include<iostream>
#include "gui.h"

class Application
{
public:
	Application();
	void execute();
private:
	GUI gui;
	SDL_Event event;
	bool quit = false;
};

#endif // APPLICATION_H
