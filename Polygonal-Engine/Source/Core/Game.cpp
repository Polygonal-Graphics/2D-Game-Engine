#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Game.h"

#include <iostream>

PE::Game::Game()
{
    Start();
}

bool PE::Game::Start()
{
    if (!WindowInit()) return false;

    // deltaTime variables
    // -------------------
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(window))
    {
        // calculate delta time
        // --------------------
        float currentFrame = (float)glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    return 0;
}

bool PE::Game::WindowInit()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWmonitor* monitor = FULLSCREEN ? glfwGetPrimaryMonitor() : nullptr;
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", monitor, nullptr);
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mode)
        {
            // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, true);
            if (key >= 0 && key < 1024)
            {
                /*
                if (action == GLFW_PRESS)
                    Breakout.Keys[key] = true;
                else if (action == GLFW_RELEASE)
                    Breakout.Keys[key] = false;*/
            }
        });

    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height)
        {
            // make sure the viewport matches the new window dimensions; note that width and 
            // height will be significantly larger than specified on retina displays.
            glViewport(0, 0, width, height);
        });

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    return true;
}