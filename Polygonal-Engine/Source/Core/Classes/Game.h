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

		// Initializes the game by calling the Game constructor. Must be called before anything else.
		static void Init() { Get(); }
		// Starts the game by entering the game loop.
		static bool Start() { return Get().StartImpl(); }

		// Getters and Setters

		static GLFWwindow* GetWindow() { return Get().m_Window; }
		static void SetScene(Scene* scene) { Get().SetSceneImpl(scene); }

	private:

		// Native GLFW window instance
		GLFWwindow* m_Window = nullptr;
		// The current scene that will be updated and rendered.
		Scene* m_ActiveScene = nullptr;
		// Set to true if the scene was changed last frame. Used for calling Start when scene changes during runtime.
		bool m_SceneChangedLastFrame = false;

		// Initializes and returns the static Game singleton instance
		static Game& Get()
		{
			static Game instance;
			return instance;
		}

		// Static Implementations

		bool StartImpl();
		void SetSceneImpl(Scene* scene);

		// Private constructor for singleton. Creates the window and loads GLAD when the first call to Get() is made.
		Game();
	};
}
