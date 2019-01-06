/*
 *	File Name:	gui.cpp
 *	Author:		Emanuel Aracena
 *	Date Created: 	January 3, 2019
 *	Description:	GUI class implementation.
 */

#include "gui.h"

GUI::GUI()
{
    	std::cout << "Constructing GUI..." << std::endl;
    	window_width = 800;
    	window_height = 600;
}

int GUI::initialize_sdl()
{
    	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        	SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        	return EXIT_FAILURE;
    	}

    	// Create Window
    	window = SDL_CreateWindow("Paintor", 100, 100, window_width, window_height, SDL_WINDOW_SHOWN);
    	if(window == nullptr) {
    		SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
    		SDL_Quit();
    		return EXIT_FAILURE; 
    	}

    	// Create Renderer
    	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if(renderer == nullptr) {
		SDL_Log("SDL_CreateRenderrer ErrorL %s" , SDL_GetError());
    		SDL_DestroyWindow(window);
		SDL_Quit();
    		return EXIT_FAILURE;
    	}

    	std::cout << "SDL successfully initialized..." << std::endl;

    	//std::cout << "Changing background color..." << std::endl;
    	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	SDL_RenderClear(renderer);
    
 	return 0;
}

void GUI::add_panel(int x, int y, int w, int h, std::string name, int r, int g, int b, int a, bool flag)
{
	int offset = 1;
	Panel panel_border(x-offset, y-offset, w+offset+offset, h+offset+offset, name + " border");
	panel_border.set_panel_color(0,0,0,255);
	panel_border.check_mouse_activity = false;
	panels.push_back(panel_border);

	Panel panel(x, y, w, h, name);
	panel.set_panel_color(r, g, b, a);
	panel.check_mouse_activity = flag;
	panels.push_back(panel);

}

void GUI::render()
{
    // Render panel list by iterating over vector
    for(Panel panel : panels) {
    	SDL_SetRenderDrawColor(renderer, panel.color_r, panel.color_g, panel.color_b, panel.color_a);    
		SDL_Rect panel_rect = panel.get_sdl_rect();
		SDL_RenderFillRect(renderer, &panel_rect);
    }

    SDL_RenderPresent(renderer);
	
}

void GUI::quit_sdl()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}