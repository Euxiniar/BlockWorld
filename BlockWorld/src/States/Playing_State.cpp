#include "Playing_State.h"
#include "../Entity/Camera.h"
#include "../Renderer/Master_Renderer.h"
#include <iostream>

namespace State
{
	Playing::Playing(Application & app)
		:  Game_State(app),
		m_texture("Texture_Atlas", 512, 16)
	{
		m_noise.setBound(0, 0);
		//std::cout << m_noise.getPositionY(1, 1) * 10;
		for (int z = 0; z < 16; z++)
		{
			for (int x = 0; x < 16; x++)
			{
				Quad* quad = new Quad(m_texture);
				quad->position.z -= z;
				quad->position.x -= x;
				quad->position.y -= static_cast<int>(m_noise.getPositionY(x, z)*10);
				vecQuad.push_back(quad);
			}
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
		for (auto& quad : vecQuad) //doesn't work
		{
			renderer.draw(*quad);
		}
	}
}