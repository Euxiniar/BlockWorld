#pragma once
#include "../Maths/Noise_Generator.h"
#include "../Entity/Blocks/Quad.h"
#include "../Textures/Texture_Atlas.h"
#include "../Maths/Random_Maths.h"

#include <vector>

namespace World
{
	class Chunk
	{
		public:
			Chunk();
			void generate(std::vector<Quad*>& quadTab, int xPos, int zPos);

		private :
			Texture::Texture_Atlas m_texture;
			Maths::Random m_random;
	};
}