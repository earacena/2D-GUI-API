/*
 *	File Name:	application.cpp
 *	Author:		Emanuel Aracena
 *	Date Created: 	January 3, 2019
 *	Description:	Application class implementation.
 */
#include "application.h"

// Constructor
Application::Application()
{
    std::cout << "Constructing application..." << std::endl;

    // GUI initialization
    if (gui.initialize_sdl() == 0)
	std::cout << "All application components initialized successfully." << std::endl;
    else
	std::cout << "Failure to initialize all application components." << std::endl;
}

// Main execution loop
void Application::execute()
{
	int time1, time2;
	std::cout << "Executing..." << std::endl;

    // parameters: posx,posy, width, height, name, r, g, b, a, bool mouse_detection
    gui.add_panel(50, 50, 100, 400, "PANEL A", 255, 255, 255, 255, false);
    gui.add_panel(50, 500, 100, 50, "PANEL B", 10, 255, 24, 255, true);
    gui.add_panel(75, 75, 20, 20, "BUTTON A", 255, 255, 255, 255, true);

    std::cout << "Entering render loop..." << std::endl;

    while(!quit) {
    	time1 = SDL_GetTicks();
    	while(SDL_PollEvent(&event)) {
    		if( event.type == SDL_QUIT ) 
			quit = true;
    	}
    	gui.render();
    	// Check if mouse is hovering over panels
    	for(Panel panel : gui.panels) {
    		if (panel.check_mouse_activity && panel.is_mouse_within_boundaries()) 
    			std::cout << panel.get_panel_name() << ": FOCUSED" << std::endl;
    	}
	
    }

	gui.quit_sdl();
}
