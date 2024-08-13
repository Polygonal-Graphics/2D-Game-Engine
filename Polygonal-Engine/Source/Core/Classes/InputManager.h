#pragma once

#include <glm/vec2.hpp>

struct GLFWwindow;

namespace Polygame
{
	/*
	* A singleton class that can be queried for various mouse and keyboard inputs.
	*/
	class InputManager
	{
	public:

		// Initializes and returns the static InputManager singleton instance
		static InputManager& Get()
		{
			static InputManager instance;
			return instance;
		}

		static bool GetKeyDown(int key) { return Get().GetKeyDownImpl(key); }
		static bool GetMouseButtonDown(int button) { return Get().GetMouseButtonDownImpl(button); }
		static glm::vec2 GetMouseScreenPos() { return Get().GetMouseScreenPosImpl(); }

	private:

		/*
		* Static Implementations
		*/
		
		bool GetKeyDownImpl(int key);
		bool GetMouseButtonDownImpl(int button);
		glm::vec2 GetMouseScreenPosImpl();
	};
}