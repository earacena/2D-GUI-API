/*
 *	File Name:	panel.cpp
 *	Author:		Emanuel Aracena Beriguete
 *	Date Created: 	January 4, 2019
 *	Description:	Panel class implementation.
 */
#include "panel.h"

Panel::Panel(int position_x, int position_y, int panel_width, int panel_height, std::string name)
{
	panel_.x = position_x;
	panel_.y = position_y;
	panel_.w = panel_width;
	panel_.h = panel_height;
	name_ 	 = name;
}

int Panel::get_panel_x()
{
	return panel_.x;
}

int Panel::get_panel_y()
{
	return panel_.y;
}

int Panel::get_panel_width()
{
	return panel_.w;
}

int Panel::get_panel_height()
{
	return panel_.h;
}

//Color Panel::get_panel_color()

void Panel::set_panel_color(int r, int g, int b, int a)
{
	if(r > 255 || r < 0)
		r %= 255;
	if(g > 255 || g < 0)
		g %= 255;	
	if(b > 255 || b < 0)
		b %= 255;
	if(a > 255 || a < 0 )
		a %= 255;

	color_r = r;
	color_g = g;
	color_b = b;
	color_a = a;
}


SDL_Rect Panel::get_sdl_rect()
{
	return panel_;
}

bool Panel::is_mouse_within_boundaries()
{
	int mouse_x;
	int mouse_y;
	SDL_GetMouseState(&mouse_x, &mouse_y);
	return ( ( (mouse_x >= panel_.x) && (mouse_x <= (panel_.x + panel_.w))) &&
		 ( (mouse_y >= panel_.y) && (mouse_y <= (panel_.y + panel_.h)))    );
}

std::string Panel::get_panel_name()
{
	return name_;
}
