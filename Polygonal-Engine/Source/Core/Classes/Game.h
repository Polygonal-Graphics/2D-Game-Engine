#pragma once

namespace PE
{
	class InputManager;
	class Window;

	class Game
	{
	public:
		// Constructors
		Game();
		~Game();

		bool Start();

	private:
		// System pointers
		InputManager* m_InputManager = nullptr;
		Window* m_Window = nullptr;

		// Initialization functions
		bool Init();

	public:
		bool GetKeyDown(const char Key);
	};
}
