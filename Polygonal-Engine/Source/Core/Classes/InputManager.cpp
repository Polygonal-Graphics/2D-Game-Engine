#include "InputManager.h"
#include "GLFW/glfw3.h"

PE::InputManager::InputManager(GLFWwindow* activeWindow)
{
	SetActiveWindow(activeWindow);
}

void PE::InputManager::SetActiveWindow(GLFWwindow* activeWindow)
{
	m_WindowInstance = activeWindow;	
	glfwSetWindowUserPointer(m_WindowInstance, this);

	glfwSetKeyCallback(m_WindowInstance, [](GLFWwindow* window, int key, int scancode, int action, int mode)
		{
			InputManager* IM = static_cast<InputManager*>(glfwGetWindowUserPointer(window));
            // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
            if (key >= 0 && key < 1024)
            {
                if (action == GLFW_PRESS)
                    IM->Keys[key] = true;
                else if (action == GLFW_RELEASE)
                    IM->Keys[key] = false;
            }
		});
}
