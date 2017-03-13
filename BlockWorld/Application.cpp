#include "Application.h"
#include "Playing_State.h"

Application::Application()
{
	init();
	//ajout de l'application dans le game_State
	pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{
	sf::Clock clock;

	//tant que la fenêtre est ouverte
	while (Display::get().isOpen())
	{
		//temps écoulé a chaque execution de la boucle
		auto dt = clock.restart().asSeconds();

		//on efface l'écran
		m_renderer.clear();

		//On sélectionne le Last In et on appelle les fonctions inputs update et draw
		//(les fonctions appelées seront celles des enfants de Game_State
		if (Display::get().isSelect())
		{
			m_states.top()->input(camera, dt);
			m_states.top()->update();
		}

		m_states.top()->draw(m_renderer);

		//On rafraichit le contexte OpenGL
		m_renderer.update(camera);

		//On regarde si on doit fermer
		Display::get().checkForClose();

		//si le temps de la chnson est fini
		if (m_songTimer.getElapsedTime() > m_songDuration)
			resetSong();
	}
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

void Application::init()
{
	//Lancement de la musique
	resetSong();
}
