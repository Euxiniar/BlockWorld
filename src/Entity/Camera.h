#pragma once
#include "Entity.h"
#include "../Affichage/Display.h"


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

	};
