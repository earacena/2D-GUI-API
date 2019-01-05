/*
 *	File Name:	gui.h
 *	Author:		Emanuel Aracena
 *	Date Created: 	January 3, 2019
 *	Description:	GUI class interface.
 */

#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>

#include "panel.h"

class GUI
{
public:
	GUI();
	int initialize_sdl();
	void add_panel(int x, int y, int w, int h, std::string name, int r, int g, int b, int a, bool flag);
	void render();
	void quit_sdl();
	std::vector<Panel> panels;
private:
	SDL_Window 	*window = nullptr;
	SDL_Renderer 	*renderer = nullptr;
	int window_width;
	int window_height;
	
};

#endif // GUI_H
