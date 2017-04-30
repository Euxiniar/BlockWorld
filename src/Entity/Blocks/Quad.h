#pragma once
#include "../Entity.h"
#include "Model.h"

namespace Texture
{
	class Texture_Atlas;
}

class Quad : public Entity
{
public:
	Quad(Texture::Texture_Atlas& textureAtlas);

	const Model& getModel() const;

private:
	Model m_model;
};
