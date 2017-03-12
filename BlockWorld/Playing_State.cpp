#include "Playing_State.h"
#include "Camera.h"

namespace State
{
	Playing::Playing(Application & app)
		:  Game_State(app)
	{
	}

	void Playing::input(Camera & camera, float dt)
	{
		//recuperation des inputs de la camera
		camera.input(dt);
	}

	void Playing::update()
	{
		
	}

	void Playing::draw(Renderer::Master_Renderer & renderer)
	{
	}
}