#pragma once
#include "../Maths/Noise.h"
#include "../Entity/Blocks/Quad.h"
#include "../Entity/Textures/Texture_Atlas.h"

#include <vector>

namespace World
{
	class Chunk
	{
		public:
			Chunk();
			void generate(std::vector<Quad*>& quadTab, int xBound, int yBound);

		private :
			HeightMap::Noise m_noise;
			Texture::Texture_Atlas m_texture;
	};
}