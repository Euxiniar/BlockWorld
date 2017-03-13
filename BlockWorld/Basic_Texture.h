#pragma once
#include "GL\glew.h"
#include <string>

namespace Texture
{
	class Basic_Texture
	{
	public:
		Basic_Texture(std::string fileName);
		void load(const std::string& fileName);
		void bind();
		void unbind();

	private:
		GLuint m_textureId;

	};
}

