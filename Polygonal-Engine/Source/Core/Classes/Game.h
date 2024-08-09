#pragma once

namespace PE
{
	class Game
	{
	public:

		// Constructors
		Game();
		~Game();

		bool Start();

	private:
		// Misc. Variables
		class Window* m_Window = nullptr;

		// Initialization functions
		bool Init();
	};
}
