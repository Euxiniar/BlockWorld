#include "Playing_State.h"
#include "../Entity/Camera.h"
#include "../Renderer/Master_Renderer.h"

namespace State
{
	Playing::Playing(Application & app)
		:  Game_State(app),
		m_texture("Texture_Atlas", 512, 16)
	{
		for (int z = 0; z < 2; z++)
		{
			for (int x = 0; x < 2; x++)
			{
				m_chunk.generate(vecQuad, x, z);
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
		//affiche les blocks de notre Chunk
		for (auto& quad : vecQuad)
		{
			renderer.draw(*quad);
		}
	}
}