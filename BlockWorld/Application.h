#pragma once
#include <stack>
#include <memory>
#include <SFML\Audio.hpp>

#include "Game_State.h"
#include "Random_Maths.h"

class Application
{
public:
	Application();

	void runMainGameLoop();
	void pushState(std::unique_ptr<State::Game_State> state);
	void popState();
	void resetSong();

private:
	void init();
	std::stack <std::unique_ptr<State::Game_State>> m_states;

	sf::Music m_song;
	sf::Time m_songDuration;
	sf::Clock m_songTimer;

	Maths::Random m_random;

	//TODO Création de la partie du programme qui s'occupera du rendu

	//TODO Création du point de vue, qui sera une camera
};

