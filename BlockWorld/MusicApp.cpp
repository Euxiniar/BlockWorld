#include "MusicApp.h"
#include <string>
#include <vector>

MusicApp::MusicApp(int seed)
{
	setSeed(seed);
	resetSong();
}
MusicApp::MusicApp()
{
	resetSong();
}

void MusicApp::setSeed(int seed)
{
	m_random.setSeed(seed);
}


void MusicApp::resetSong()
{
	static std::string songFilesPath = "Data/Music/";
	static std::vector<std::string> songNames =
	{
		"Game_of_Thrones",
		"Doctor_Who",
		"The_Witcher_3"
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
	m_song.setVolume(100);
}

sf::Time MusicApp::getSongDuration()
{
	return m_songDuration;
}

sf::Time MusicApp::getSongTimer()
{
	return m_songTimer.getElapsedTime();
}
