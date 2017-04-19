#pragma once
#include "Game_State.h"
#include "../Entity/Blocks/Quad.h"
#include "../Textures/Texture_Atlas.h"
#include "../World/WChunk.h"

namespace State
{
	class Playing : 
		public Game_State
	{
	public:
		Playing(Application & app);
		void input(Camera& camera, float dt) override;
		void update() override;
		void draw(Renderer::Master_Renderer& renderer) override;

	private:
		Texture::Texture_Atlas m_texture;
		std::vector<Quad*> vecQuad;
		World::Chunk m_chunk;
	};
}