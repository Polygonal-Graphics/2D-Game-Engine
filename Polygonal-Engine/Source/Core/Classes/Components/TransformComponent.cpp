#include "TransformComponent.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Polygame
{
	glm::mat4 TransformComponent::GetModelMatrix()
	{
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::scale(model, m_Scale);
		model = glm::rotate(model, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, m_Location);

		return model;
	}
}