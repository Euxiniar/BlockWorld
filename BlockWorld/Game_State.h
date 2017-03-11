#pragma once

class Camera;
class Application;

namespace State
{
	class Game_State
	{
	public:
		Game_State(Application & app);

		virtual void input(Camera& camera, float dt) = 0;
		virtual void update() = 0;

	protected:
		Application *m_app;
	};

}