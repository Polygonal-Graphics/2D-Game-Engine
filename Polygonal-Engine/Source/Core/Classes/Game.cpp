#include "Game.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "Scene.h"
#include "Renderer.h"

#include <iostream>

namespace Polygame
{
    Game::Game()
    {
        bool success = true;

        // Create a GLFWwindow on initalization (also initializes GLAD)
        m_Window = PolyWindow::CreateWindow(1920, 1080, false);
        if (!m_Window)
        {
            std::cout << "Could not create window\n";
            success = false;
        }

        // OpenGL configuration
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        if (success)
            std::cout << "Game Created Successfully\n";
        else
            std::cout << "Game Could not be Created\n";
    }

    bool Game::StartImpl()
    {
        // Check if there is an active scene
        if (!m_ActiveScene)
        {
            std::cout << "No active scene\n";
            return false;
        }

        // DeltaTime variables
        float deltaTime = 0.0f;
        float lastFrame = 0.0f;

        while (!glfwWindowShouldClose(m_Window))
        {
            // Call start if a new scene was set last frame
            if (m_SceneChangedLastFrame)
            {
                m_ActiveScene->Start();
                m_SceneChangedLastFrame = false;
            }

            // Calculate delta time
            float currentFrame = (float)glfwGetTime();
            deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;
            glfwPollEvents();

            // Update the active scene
            m_ActiveScene->Update(deltaTime);

            // Render
            Renderer::Render();

            glfwSwapBuffers(m_Window);
        }

        std::cout << "OpenGL Error Code: " << glGetError() << std::endl;
        glfwTerminate();
        delete m_ActiveScene;

        return true;
    }

    void Game::SetSceneImpl(Scene* scene)
    {
        m_ActiveScene = scene;
        // Pass the scene root to the Renderer
        Renderer::SetRoot(m_ActiveScene->m_RootObject);
        m_SceneChangedLastFrame = true;
    }
}