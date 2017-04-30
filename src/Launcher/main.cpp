#include "../Affichage/Display.h"
#include "../Affichage/Application.h"
#include <iostream>

int main()
{
	try
	{
		Display::get().setTitle("BlockWorld");
		Application app;
		app.runMainGameLoop();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}