#pragma once
#include "Game_State.h"

namespace State
{
	class Playing : 
		public Game_State
	{
	public:
		Playing(Application & app);
		void input(Camera& camera, float dt) override;
		void update() override;
	};
}