#include "Game.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"

#include <iostream>

namespace PE
{
    Game::Game()
    {
        std::cout << "Game Created\n";
    }

    bool Game::StartImpl()
    {
        if (!Init()) return false;

        // deltaTime variables
        // -------------------
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        while (!glfwWindowShouldClose(m_Window))
        {
            // calculate delta time
            // --------------------
            float currentFrame = glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            glfwPollEvents();

            // render
            // ------
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_Window);
        }

        std::cout << "OpenGL Error Code: " << glGetError() << std::endl;

        glfwTerminate();

        return true;
    }

    bool Game::Init()
    {
        m_Window = PWindow::CreateWindow(1920, 1080, false);
        if (!m_Window)
        {
            std::cout << "Could not create window\n";
            return false;
        }

        // OpenGL configuration
        // --------------------
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }
}