#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Game.h"
#include "Window.h"
#include "InputManager.h"

#include <glad/glad.h>
#include <iostream>

PE::Game::Game()
{
    std::cout << "Game Created\n";
}

PE::Game::~Game()
{
    delete m_Window;
    delete m_InputManager;
}

bool PE::Game::Start()
{
    if (!Init()) return false;

    // deltaTime variables
    // -------------------
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while (m_Window->WindowActive())
    {
        // calculate delta time
        // --------------------
        float currentFrame = m_Window->GetActiveTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        m_Window->PollEvents();

        // render
        // ------
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m_Window->SwapBuffers();
    }

    std::cout << "OpenGL Error Code: " << glGetError() << std::endl;

    return true;
}

bool PE::Game::Init()
{
    m_Window = new Window(1920, 1080, false);
    if (!m_Window)
    {
        std::cout << "Could not create window\n";
        return false;
    }

    m_InputManager = new InputManager(m_Window->GetGLFWWIndow());
    if (!m_InputManager)
    {
        std::cout << "Could not create input manager\n";
        return false;
    }

    // OpenGL configuration
    // --------------------
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}

bool PE::Game::GetKeyDown(char Key)
{
    return m_InputManager->Keys[Key];
}
