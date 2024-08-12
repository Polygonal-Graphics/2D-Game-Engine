#pragma once

namespace PE
{
	class InputManager;
	class Window;

	// A singleton class that brings together Polygame subsystems as the hub of any game.
	class Game
	{
	public:
		// Initializes and returns the static Game singleton instance
		static Game& Get()
		{
			static Game instance;
			return instance;
		}

		// Loads the game, opens the window, and enters the game loop.
		static bool Start() { return Get().StartImpl(); }

		~Game();

	private:
		// Subsystem pointers
		InputManager* m_InputManager = nullptr;
		Window* m_Window = nullptr;

		// Initializes subsystems prior to starting the game. Returns false if any subsystems fail to initialize.
		bool Init();

		/*
		* Static Implementations
		*/

		bool StartImpl();

		Game();

	public:
		bool GetKeyDown(const char Key);
	};
}
