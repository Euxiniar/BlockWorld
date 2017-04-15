#pragma once
#include "Game_State.h"
#include "../Entity/Blocks/Quad.h"
#include "../Entity/Textures/Texture_Atlas.h"
#include "../Maths/Noise.h"

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
		HeightMap::Noise m_noise;
	};
}