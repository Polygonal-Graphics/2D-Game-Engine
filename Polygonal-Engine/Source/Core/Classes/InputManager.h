#pragma once

struct GLFWwindow;

namespace PE
{
	class InputManager
	{
	public:
		// Constructors
		InputManager(GLFWwindow* activeWindow);

		void SetActiveWindow(GLFWwindow* activeWindow);

		GLFWwindow* m_WindowInstance = nullptr;
		bool Keys[1024] = { false };
	};
}