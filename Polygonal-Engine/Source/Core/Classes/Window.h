#pragma once

#include <cstdint>

struct GLFWwindow;

namespace PE
{
	class Window
	{
	public:
		// Constructors
		Window(uint32_t width, uint32_t height, bool fullscreen);
		~Window();

		// Window actions
		void ActivateWindow();
		void PollEvents();
		void SwapBuffers();
		float GetActiveTime();
		bool WindowActive();

		// Screen variables
		uint32_t m_WindowWidth;
		uint32_t m_WindowHeight;
		bool m_Fullscreen;

	private:
		GLFWwindow* m_WindowInstance;

	public:
		GLFWwindow* GetGLFWWIndow() const { return m_WindowInstance; }
	};
}