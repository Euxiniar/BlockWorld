#include "Simple_Renderer.h"
#include "Matrix_Maths.h"
#include "Quad.h"

namespace Renderer
{
	void Renderer::Simple_Shader::draw(const Quad & quad)
	{
		m_quads.push_back(&quad);
	}

	void Renderer::Simple_Shader::update(const Camera & camera)
	{
		m_shader.bind();
		//on rempli la variable de temps du shader avec la valeur du temps
		m_shader.setTime(m_clock.getElapsedTime().asSeconds());

		//on passe la matrice de vue au shader (donc la camera)
		m_shader.setViewMatrix(Maths::createViewMatrix(camera));

		for (auto& quad : m_quads) //on affiche chacun des quads l'un apres l'autre
		{
			prepare(*quad);
			glDrawElements(GL_TRIANGLES, quad->getModel().getIndicesCount(), GL_UNSIGNED_INT, nullptr);
		}
		m_quads.clear();
	}

	void Renderer::Simple_Shader::prepare(const Quad & quad)
	{
		quad.getModel().bind(); //on récupère le model

		//envoie de la matrice de models (les quads) au shader
		m_shader.setModelMatrix(Maths::createModelMatrix(quad));
	}
}