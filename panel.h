/*
 *	File Name:	panel.h
 *	Author:		Emanuel Aracena
 *	Date Created: 	January 4, 2019
 *	Description:	Panel class interface.
 */
#ifndef PANEL_H
#define PANEL_H

#include <SDL2/SDL.h>
#include <string>


class Panel
{
public:
	Panel(int position_x, int position_y, int panel_width, int panel_height, std::string name);
	SDL_Rect get_sdl_rect();
	bool is_mouse_within_boundaries();
	int get_panel_x();
	int get_panel_y();
	int get_panel_height();
	int get_panel_width();
	//Color Panel::get_panel_color();
	void set_panel_color(int r, int g, int b, int a);
	std::string get_panel_name();

	int color_r;
	int color_g;
	int color_b;
	int color_a;

	bool check_mouse_activity;

private:
	SDL_Rect panel_;
	std::string name_;
};

#endif	// PANEL_H