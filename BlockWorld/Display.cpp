#include "Display.h"
#include <GL\glew.h>


Display::Display(std::string title)
{
	//on définit un objet qui contiendra tous les paramètres de notre fenetre
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	//création de la fenetre
	window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT),
		title,
		sf::Style::Close,
		settings);

	//on implémente glew pour pouvoir utiliser OpenGL dans notre fenetre
	glewInit();

	//on définit la taille qu'occupera OpenGL dans la fenetre
	glViewport(0, 0, WIDTH, HEIGHT);

	//On rajoute le depth-test qui permettra d'éviter la supperposition des faces
	glEnable(GL_DEPTH_TEST);

	//on rajoute le cull face pour n'afficher que les faces qui sont faces à la camera
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CW);
	
	//les derniers paramètres de la fenetre
	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);
}

Display::~Display()
{
	window->close();
}

void Display::close()
{
	window->close();
}

void Display::checkForClose()
{
	//on crée un evenement pour récupérer les actions subits par la fenetre
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			close();
		}
	}
}

bool Display::isSelect()
{
	return window->hasFocus();
}