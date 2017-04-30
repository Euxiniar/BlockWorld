#pragma once
#include <stack>
#include <memory>

#include "../States/Game_State.h"
#include "MusicApp.h"
#include "../Maths/Random_Maths.h"
#include "../Entity/Camera.h"
#include "../Renderer/Master_Renderer.h"

class Application
{
public:
	Application();

	void runMainGameLoop();
	void pushState(std::unique_ptr<State::Game_State> state);
	void popState();

private:
	void init();
	std::stack <std::unique_ptr<State::Game_State>> m_states;

	//Creation de la partie du programme qui s'occupera du rendu
	Renderer::Master_Renderer m_renderer;

	//Creation du point de vue, qui sera une camera
	Camera camera;

	MusicApp m_song;
};

