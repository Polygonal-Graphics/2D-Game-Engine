#pragma once

#include "BaseComponent.h"
#include "glm/glm.hpp"

namespace Polygame
{
	class TransformComponent : public BaseComponent
	{
	public:
		// Returns a model matrix with the TransformComponent's location, rotation, and scale
		glm::mat4 GetModelMatrix();

		glm::vec3 m_Location = glm::vec3(0.0f);
		glm::vec3 m_Rotation = glm::vec3(0.0f);
		glm::vec3 m_Scale = glm::vec3(1.0f);
	};
}