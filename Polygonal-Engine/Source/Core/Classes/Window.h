#pragma once

class GLFWwindow;

namespace PE
{
	class Window
	{
	public:
		Window(unsigned int width, unsigned int height, bool fullscreen);
		~Window();

		void ActivateWindow();

		void PollEvents();
		void SwapBuffers();
		float GetActiveTime();
		bool WindowActive();

		// Screen variables
		unsigned int m_WindowWidth;
		unsigned int m_WindowHeight;
		bool m_Fullscreen;

	private:
		GLFWwindow* m_WindowInstance;
	};
}