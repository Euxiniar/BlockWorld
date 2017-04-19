#pragma once
#include "Simple_Renderer.h"

namespace Renderer
{
	class Master_Renderer
	{
	public:
		void clear();
		void update(const Camera& camera);
		void draw(const Quad& model);

	private:
		//on crée un objet de type Simple
		Simple_Renderer m_simpleRenderer;
	};
}