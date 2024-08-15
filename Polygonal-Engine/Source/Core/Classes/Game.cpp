#include "Game.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Scene.h"

#include <iostream>

namespace Polygame
{
    Game::Game()
    {
        std::cout << "Game Created\n";
    }

    bool Game::StartImpl()
    {
        if (!Init()) return false;

        // DeltaTime variables
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        // Call start on the active scene
        m_ActiveScene->Start();

        while (!glfwWindowShouldClose(m_Window))
        {
            // Calculate delta time
            float currentFrame = (float)glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            glfwPollEvents();

            // Update the active scene
            m_ActiveScene->Update(deltaTime);

            // Render
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(m_Window);
        }

        std::cout << "OpenGL Error Code: " << glGetError() << std::endl;
        glfwTerminate();
        delete m_ActiveScene;

        return true;
    }

    bool Game::Init()
    {
        // Check if there is an active scene
        if (!m_ActiveScene)
        {
            std::cout << "No active scene\n";
            return false;
        }

        // Create a GLFWwindow on initalization
        m_Window = PolyWindow::CreateWindow(1920, 1080, false);
        if (!m_Window)
        {
            std::cout << "Could not create window\n";
            return false;
        }

        // OpenGL configuration
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        return true;
    }

    void Game::SetSceneImpl(Scene* scene)
    {
        m_ActiveScene = scene;
    }
}