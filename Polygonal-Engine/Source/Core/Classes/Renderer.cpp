#include "Renderer.h"

#include "GameObject/GameObject.h"
#include "GameObject/WorldObject.h"
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
        // Start frame
        glClear(GL_COLOR_BUFFER_BIT);

        // Check scene root
        if (m_SceneRoot == nullptr)
        {
            std::cout << "Renderer has no scene\n";
            return;
        }

        // Prepare for Rendering
        m_ActiveShader->Use();
        m_ActiveShader->UMat4("projection", glm::ortho(0.0f, 1920.0f, 1080.0f, 0.0f, -1.0f, 1.0f));
        glBindVertexArray(m_QuadVAO);

        // Render scene hierarchy
        GameObject* CurrentObject = m_SceneRoot;
        while (CurrentObject)
        {
            if (WorldObject* CurrentWorldObject = dynamic_cast<WorldObject*>(CurrentObject))
            {
                RenderInfo renderInfo = CurrentWorldObject->GetRenderInfo();
                glBindTextureUnit(0, get<0>(renderInfo));
                m_ActiveShader->UMat4("model", get<1>(renderInfo));
                glDrawArrays(GL_TRIANGLES, 0, 6);
            }

            CurrentObject = CurrentObject->GetNextObject();
        }

        // Complete frame
        glBindVertexArray(0);
	}

    Renderer::~Renderer()
    {
        delete m_ActiveShader;
        glDeleteVertexArrays(1, &m_QuadVAO);
    }
}

