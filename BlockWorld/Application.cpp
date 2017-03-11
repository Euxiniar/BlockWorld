#include "Application.h"

Application::Application()
{
	init();
}

void Application::runMainGameLoop()
{
}

void Application::pushState()
{
}

void Application::popState()
{
}

void Application::resetSong()
{
	static std::string songFilesPath = "Data/Music/";
	static std::vector<std::string> songNames =
	{
		"Game_of_Thrones",
		"Doctor_Who",
	};

	static auto lastSong = songNames.size();
	auto thisSong = lastSong;

	while (thisSong == lastSong)
		thisSong = m_random.getInteger(0, songNames.size() - 1);

	lastSong = thisSong;
	m_song.openFromFile(songFilesPath + songNames[thisSong] + ".ogg");
	m_song.play();
	m_songDuration = m_song.getDuration();
	m_songTimer.restart();
	m_song.setVolume(5);
}

void Application::init()
{
	//Lancement de la musique
	resetSong();
}
