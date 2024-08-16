#include "Renderer.h"

#include "GameObject.h"
#include "Core/Shaders/Shader.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace Polygame
{
	Renderer::Renderer()
	{
        /*
        * Set default configuration
        */
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

        /*
        * Create quad VAO for rendering sprites
        */
        uint32_t VBO;
        float vertices[] = {
            // pos      // tex
            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 0.0f, 0.0f,

            0.0f, 1.0f, 0.0f, 1.0f,
            1.0f, 1.0f, 1.0f, 1.0f,
            1.0f, 0.0f, 1.0f, 0.0f
        };

        glGenVertexArrays(1, &m_QuadVAO);
        glGenBuffers(1, &VBO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindVertexArray(m_QuadVAO);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        /*
        * Create default 2D shader
        */
        m_ActiveShader = new Shader("../Polygonal-Engine/Source/Core/Shaders/DefaultVertex.vert", "../Polygonal-Engine/Source/Core/Shaders/DefaultFragment.frag");
	}

    void Renderer::SetRootImpl(GameObject* sceneRoot)
	{
		m_SceneRoot = sceneRoot;
	}

	void Renderer::RenderImpl()
	{
        glClear(GL_COLOR_BUFFER_BIT);

        if (m_SceneRoot == nullptr)
        {
            std::cout << "Renderer has no scene\n";
            return;
        }

        m_ActiveShader->Use();
        m_ActiveShader->UMat4("model", glm::scale(glm::mat4(1.0f), glm::vec3(500.0f)));
        m_ActiveShader->UMat4("projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));
        glBindVertexArray(m_QuadVAO);

        glDrawArrays(GL_TRIANGLES, 0, 6);

        glBindVertexArray(0);
	}

    Renderer::~Renderer()
    {
        delete m_ActiveShader;
        glDeleteVertexArrays(1, &m_QuadVAO);
    }
}

