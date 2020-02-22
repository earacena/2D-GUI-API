/*      Project title:  Paint application with GUI system using SDL
 *      Author:         Emanuel Aracena Beriguete
 *      Date Created:   January 3, 2019
 *
 *          File name:      main.cpp
 *          Description:    Main routine file of project. Uses SDL for immediate
 *                          GUI.
 */
#include "application.h"

int main(int argc, char* argv[])
{
	Application app;

	app.execute();

	return EXIT_SUCCESS;
}
