#include "Playing_State.h"
#include "../Entity/Camera.h"
#include "../Renderer/Master_Renderer.h"

namespace State
{
	Playing::Playing(Application & app)
		:  Game_State(app),
		m_texture("Texture_Atlas", 512, 16)
	{
		m_chunk.generate(vecQuad, 0, 0);
		m_chunk.generate(vecQuad, 0, 1);
		m_chunk.generate(vecQuad, 0, 2);
		m_chunk.generate(vecQuad, 0, 3);
		m_chunk.generate(vecQuad, 0, 4);
		m_chunk.generate(vecQuad, 0, 5);
		m_chunk.generate(vecQuad, 0, 6);
		m_chunk.generate(vecQuad, 0, 7);
		m_chunk.generate(vecQuad, 0, 8);
		m_chunk.generate(vecQuad, 0, 9);
		m_chunk.generate(vecQuad, 0, 10);
		m_chunk.generate(vecQuad, 0, 11);
		m_chunk.generate(vecQuad, 0, 12);
		m_chunk.generate(vecQuad, 0, 13);
		m_chunk.generate(vecQuad, 0, 14);
		m_chunk.generate(vecQuad, 0, 15);
		m_chunk.generate(vecQuad, 0, 16);
		m_chunk.generate(vecQuad, 0, 17);
		m_chunk.generate(vecQuad, 0, 18);
		m_chunk.generate(vecQuad, 0, 19);
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