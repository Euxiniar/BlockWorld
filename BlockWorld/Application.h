#pragma once
#include <stack>
#include <memory>
#include <SFML\Audio.hpp>

#include "Random_Maths.h"

class Application
{
public:
	Application();

	void runMainGameLoop();
	void pushState();
	void popState();
	void resetSong();

private:
	void init();

	sf::Music m_song;
	sf::Time m_songDuration;
	sf::Clock m_songTimer;
	Maths::Random m_random;

	//TODO On cree la partie du programme qui s'occupera du rendu

	//TODO Création du point de vue, qui sera une camera
};

