#include "WorldObject.h"
#include "../Components/TransformComponent.h"
#include "../Components/SpriteComponent.h"

#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

namespace Polygame
{
	WorldObject::WorldObject()
	{
		m_Transform = new TransformComponent;
		AddComponent(m_Transform);
		m_Sprite = new SpriteComponent;
		AddComponent(m_Sprite);
	}

	RenderInfo WorldObject::GetRenderInfo()
	{
		if (!m_Transform || !m_Sprite)
		{
			std::cout << "Failed to get render info for" << m_Name << std::endl;
			return { 0, 0 };
		}

		return { m_Sprite->m_TextureID, m_Transform->GetModelMatrix() };
	}
}

