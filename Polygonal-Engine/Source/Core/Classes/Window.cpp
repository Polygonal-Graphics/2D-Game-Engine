#include "Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

PE::Window::Window(uint32_t width, uint32_t height, bool fullscreen) : m_WindowWidth(width), m_WindowHeight(height), m_Fullscreen(fullscreen)
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

    glfwSetFramebufferSizeCallback(m_WindowInstance, [](GLFWwindow* window, int width, int height)
        {
            // make sure the viewport matches the new window dimensions; note that width and 
            // height will be significantly larger than specified on retina displays.
            glViewport(0, 0, width, height);
        });
}

void PE::Window::PollEvents()
{
    glfwPollEvents();
}

void PE::Window::SwapBuffers()
{
    glfwSwapBuffers(m_WindowInstance);
}

bool PE::Window::WindowActive()
{
    return !glfwWindowShouldClose(m_WindowInstance);
}

float PE::Window::GetActiveTime()
{
    return (float)glfwGetTime();
}