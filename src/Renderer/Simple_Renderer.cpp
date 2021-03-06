﻿#include "Simple_Renderer.h"
#include "../Maths/Matrix_Maths.h"
#include "../Entity/Blocks/Quad.h"
#include <iostream>

namespace Renderer
{
	void Simple_Renderer::draw(const Quad & quad)
	{
		m_quads.push_back(&quad);
	}

	void Simple_Renderer::update(const Camera & camera)
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
			quad->getModel().unbind();
		}
		m_quads.clear();
	}

	void Simple_Renderer::prepare(const Quad & quad)
	{
		quad.getModel().bind(); //on récupère le model

		//envoie de la matrice de models (les quads) au shader
		m_shader.setModelMatrix(Maths::createModelMatrix(quad));
	}
}