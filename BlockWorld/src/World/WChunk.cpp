#include "WChunk.h"

namespace World
{
	Chunk::Chunk()
		: m_texture("Texture_Atlas", 512, 16)
	{
	}

	void Chunk::generate(std::vector<Quad*>& quadTab, int xBound, int yBound)
	{
		m_noise.setBound(xBound, yBound);
		for (int z = 0; z < 16; z++)
		{
			for (int x = 0; x < 16; x++)
			{
				Quad* quad = new Quad(m_texture);
				quad->position.z -= z;
				quad->position.x -= x;
				quad->position.y -= static_cast<int>(m_noise.getPositionY(x, z) * 10);
				quadTab.push_back(quad);
			}
		}
	}
}
