#include "InputManager.h"

#include "GLFW/glfw3.h"
#include "Game.h"

namespace Polygame
{
    bool InputManager::GetKeyDownImpl(int key)
    {
        GLFWwindow* window = static_cast<GLFWwindow*>(Game::GetWindow());
        bool state = glfwGetKey(window, key);
        return state == GLFW_PRESS;
    }
    
    bool InputManager::GetMouseButtonDownImpl(int button)
    {
        GLFWwindow* window = static_cast<GLFWwindow*>(Game::GetWindow());
        bool state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    glm::vec2 InputManager::GetMouseScreenPosImpl()
    {
        GLFWwindow* window = static_cast<GLFWwindow*>(Game::GetWindow());
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        return glm::vec2((float)xpos, (float)ypos);
    }
}