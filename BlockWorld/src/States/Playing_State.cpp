#include "Playing_State.h"
#include "../Entity/Camera.h"
#include "../Renderer/Master_Renderer.h"
#include <iostream>

namespace State
{
	Playing::Playing(Application & app)
		:  Game_State(app),
		m_texture("Texture_Atlas", 512, 16)
		, m_quad(m_texture)
		, m_quad2(m_texture)
	{
		m_quad.position.z -= 5;
		m_quad2.position.z -= 4;
		
		for (int i = 0; i < 5; i++)
		{
			static Quad quad(m_texture);
			quad.position.z -= 8;
			vecQuad.push_back(quad);
		}
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
		renderer.draw(m_quad); //work
		renderer.draw(m_quad2); //work
		for (auto& quad : vecQuad) //doesn't work
		{
			renderer.draw(quad);
		}
	}
}