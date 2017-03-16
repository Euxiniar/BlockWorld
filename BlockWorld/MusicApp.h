#pragma once
#include <SFML\Audio.hpp>
#include "Random_Maths.h"

class MusicApp
{
public:
	MusicApp(int seed);
	MusicApp();
	void setSeed(int seed);
	void resetSong();
	sf::Time getSongDuration();
	sf::Time getSongTimer();
private:
	sf::Music m_song;
	sf::Time m_songDuration;
	sf::Clock m_songTimer;

	Maths::Random m_random;
};

