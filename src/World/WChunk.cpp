﻿#include "WChunk.h"
#include <limits>

namespace World
{
	Chunk::Chunk()
		: m_texture("Texture_Atlas", 512, 16)
	{
		m_noise.setSeed(static_cast<uint64_t>(m_random.getInteger(0, INT32_MAX)));
	}

	void Chunk::generate(std::vector<Quad*>& quadTab, int xPos, int zPos)
	{
		xPos *= 16;
		zPos *= 16;
		for (int z = 0; z < 16; z++)
		{
			for (int x = 0; x < 16; x++)
			{
				Quad* quad = new Quad(m_texture);
				quad->position.z -= (z+zPos);
				quad->position.x -= (x+xPos);
				quad->position.y -= static_cast<int>(m_noise.getValue((x + xPos), (z + zPos), 1, 1));

				quadTab.push_back(quad);
				for (int i = -10; i < quad->position.y; i++)
				{
					Quad* quadUnder = new Quad(m_texture);
					quadUnder->position.z -= z;
					quadUnder->position.x -= x;
					quadUnder->position.y = (float)i;
					quadTab.push_back(quadUnder);
				}
				
			}
		}
	}
}
