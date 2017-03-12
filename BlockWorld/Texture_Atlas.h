#pragma once
#include <vector>
#include "Basic_Texture.h"
#include "Glm_Common.h"


namespace Texture
{
	class Texture_Atlas : public Basic_Texture
	{
	public:
		Texture_Atlas(const std::string& textureName, GLuint size, GLuint textureSize);

		std::vector<GLfloat> getTextureCoords(const Vector2& location);

	private:
		const GLuint m_size;
		const GLuint m_textureSize;
	};
}