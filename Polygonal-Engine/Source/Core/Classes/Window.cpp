#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

PE::Window::Window(unsigned int width, unsigned int height, bool fullscreen) : m_WindowWidth(width), m_WindowHeight(height), m_Fullscreen(fullscreen)
{
    ActivateWindow();
}

PE::Window::~Window()
{
    glfwSetWindowShouldClose(m_WindowInstance, true);
    glfwTerminate();
}

void PE::Window::ActivateWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWmonitor* monitor = m_Fullscreen ? glfwGetPrimaryMonitor() : nullptr;
    m_WindowInstance = glfwCreateWindow(m_WindowWidth, m_WindowHeight, "Poly-Game", monitor, nullptr);
    glfwMakeContextCurrent(m_WindowInstance);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
    }
    glViewport(0, 0, m_WindowWidth, m_WindowHeight);

    glfwSetKeyCallback(m_WindowInstance, [](GLFWwindow* window, int key, int scancode, int action, int mode)
        {
            // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            {
                glfwSetWindowShouldClose(window, true);
            }
            if (key >= 0 && key < 1024)
            {
                /*
                if (action == GLFW_PRESS)
                    Breakout.Keys[key] = true;
                else if (action == GLFW_RELEASE)
                    Breakout.Keys[key] = false;*/
            }
        });

    glfwSetFramebufferSizeCallback(m_WindowInstance, [](GLFWwindow* window, int width, int height)
        {
            // make sure the viewport matches the new window dimensions; note that width and 
            // height will be significantly larger than specified on retina displays.
            glViewport(0, 0, width, height);
        });
}

void PE::Window::PollEvents()
{
    if (m_WindowInstance)
    {
        glfwPollEvents();
    }
    else
    {
        std::cout << "No active window instance to poll events!\n";
    }
}

void PE::Window::SwapBuffers()
{
    if (m_WindowInstance)
    {
        glfwSwapBuffers(m_WindowInstance);
    }
    else
    {
        std::cout << "No active window instance to swap buffers!\n";
    }
}

bool PE::Window::WindowActive()
{
    return !glfwWindowShouldClose(m_WindowInstance);
}

float PE::Window::GetActiveTime()
{
    return (float)glfwGetTime();
}