#pragma once
#include "Entity.h"
#include "../Affichage/Display.h"
#include <SFML\System\Clock.hpp>

	class Camera :
		public Entity
	{
	public:
		Camera();

		void input(float dt);

	private:
		void mouseInput(float dtMouse);
		const int centerX = Display::WIDTH / 2;
		const int centerY = Display::HEIGHT / 2;
		sf::Clock m_clock;
	};
