#include "Display.h"
#include <GL\glew.h>

Display & Display::get(std::string title)
{
	static Display display(title);
	return display;
}

Display::Display(std::string title)
{
	//on d�finit un objet qui contiendra tous les param�tres de notre fenetre
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	//cr�ation de la fenetre
	m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(WIDTH, HEIGHT),
		title,
		sf::Style::Close,
		settings);

	//on impl�mente glew pour pouvoir utiliser OpenGL dans notre fenetre
	glewInit();

	//on d�finit la taille qu'occupera OpenGL dans la fenetre
	glViewport(0, 0, WIDTH, HEIGHT);

	//On rajoute le depth-test qui permettra d'�viter la supperposition des faces
	glEnable(GL_DEPTH_TEST);

	//on rajoute le cull face pour n'afficher que les faces qui sont faces � la camera
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	glFrontFace(GL_CW);
	
	//les derniers param�tres de la fenetre
	m_window->setMouseCursorVisible(true);
	m_window->setFramerateLimit(60);
	m_window->setVerticalSyncEnabled(true);
}

void Display::close()
{
	m_window->close();
}

void Display::checkForClose()
{
	//on cr�e un evenement pour r�cup�rer les actions subits par la fenetre
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			close();
		}
	}
}

bool Display::isSelect()
{
	return m_window->hasFocus();
}

const sf::Window & Display::get()
{
	return *m_window;
}
