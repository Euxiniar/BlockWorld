#pragma once
#include "Game_State.h"
#include "Quad.h"
#include "Texture_Atlas.h"

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
		Quad m_quad;
	};
}