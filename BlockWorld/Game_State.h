#pragma once

class Application;

namespace State
{
	class Game_State
	{
	public:
		Game_State(Application & app);

	protected:
		Application *m_app;
	};

}