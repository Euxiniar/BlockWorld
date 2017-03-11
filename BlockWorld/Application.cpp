#include "Application.h"
#include "Playing.h"

Application::Application()
{
	init();
	//ajout de l'application dans le game_State
	pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{
}

void Application::pushState(std::unique_ptr<State::Game_State> state)
{
	m_states.push(std::move(state));
}

void Application::popState()
{
	m_states.pop();
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
