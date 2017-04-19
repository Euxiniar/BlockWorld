#include "../Affichage/Display.h"
#include "../Affichage/Application.h"

int main()
{
	Display::get().setTitle("BlockWorld");
	Application app;
	app.runMainGameLoop();
}