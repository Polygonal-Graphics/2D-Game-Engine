#pragma once

struct GLFWwindow;

namespace Polygame
{
	class InputManager;
	class Window;
	class Scene;

	/*
	* A singleton class that brings together Polygame subsystems as the hub of any game.
	*/
	class Game
	{
	public:

		// Initializes and returns the static Game singleton instance
		static Game& Get()
		{
			static Game instance;
			return instance;
		}

		// Creates the window and loads GLAD. Must be called before anything else.
		static bool Init() { return Get().InitImpl(); };
		// Starts the game by entering the game loop.
		static bool Start() { return Get().StartImpl(); }

	private:

		/*
		* Private members
		*/

		// Native GLFW window instance
		GLFWwindow* m_Window = nullptr;

		// The current scene that will be updated and rendered.
		Scene* m_ActiveScene = nullptr;

		/*
		* Private methods
		*/

		// Initializes subsystems prior to starting the game. Returns false if any subsystems fail to initialize.
		bool InitImpl();

		/*
		* Static Implementations
		*/

		bool StartImpl();
		void SetSceneImpl(Scene* scene);

		// Private constructor for singleton
		Game();

	public:

		/*
		* Getters and Setters
		*/

		static GLFWwindow* GetWindow() { return Get().m_Window; }

		static void SetScene(Scene* scene) { Get().SetSceneImpl(scene); }
	};
}
