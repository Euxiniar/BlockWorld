﻿#pragma once
#include <vector>
#include "../Shaders/Simple_Shader.h"
#include <SFML/System/Clock.hpp>

class Quad;
class Camera;

namespace Renderer
{
	class Simple_Renderer
	{
	public:
		void draw(const Quad& quad);
		void update(const Camera& camera);

	private:
		void prepare(const Quad& quad);

		std::vector<const Quad *> m_quads;

		//on crée un objet de type Simple_Shader
		Shader::Simple_Shader m_shader;

		sf::Clock m_clock;
	};
}
