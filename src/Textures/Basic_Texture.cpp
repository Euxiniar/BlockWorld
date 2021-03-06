#include "Basic_Texture.h"
#include <SFML/Graphics/Image.hpp>
#include <GL/glew.h>

namespace Texture
{
	Basic_Texture::Basic_Texture(std::string fileName)
	{
		load(fileName);
	}

	void Basic_Texture::load(const std::string & fileName)
	{
		std::string filePath = "Data/Textures/" + fileName + ".png";

		//on charge l'image depuis le fichier pass� en argument
		sf::Image image;
		image.loadFromFile(filePath);

		//on assigne � OpenGL de la place pour stocker la texture et la lire 
		glGenTextures(1, &m_textureId);

		//on selectionne la texture qu'on utilise comme �tant 2D. 
		glBindTexture(GL_TEXTURE_2D, m_textureId);

		//on d�finit les propri�t�s de l'image
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RGBA,
			image.getSize().x,
			image.getSize().y,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			image.getPixelsPtr());

		//En cas de d�bordement de la forme, la texture se d�forme pour rentrer
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//on d�selectionne la texture
		glDisable(GL_TEXTURE_2D);
	}

	void Basic_Texture::bind()
	{
		//on selectionne la texture
		glBindTexture(GL_TEXTURE_2D, m_textureId);
	}

	void Basic_Texture::unbind()
	{
		glDisable(GL_TEXTURE_2D);
	}
}
