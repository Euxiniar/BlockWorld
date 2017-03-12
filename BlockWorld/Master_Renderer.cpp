#include "Master_Renderer.h"
#include "Display.h"

namespace Renderer
{
	void Master_Renderer::clear()
	{
		//on efface l'ecran
		Display::get().clear();
	}

	void Master_Renderer::update(const Camera& camera)
	{
		m_simpleRenderer.update(camera);

		Display::get().update();
	}

	void Master_Renderer::draw(const Quad& model)
	{
		m_simpleRenderer.draw(model);
	}
}