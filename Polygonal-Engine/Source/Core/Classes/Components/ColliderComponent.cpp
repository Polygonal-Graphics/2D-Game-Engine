#include "ColliderComponent.h"

#include "../CollisionHandler.h"
#include "glm/vec2.hpp"
#include "TransformComponent.h"

namespace Polygame
{
	ColliderComponent::ColliderComponent(TransformComponent* owningTransform)
	{
		m_OwningTransform = owningTransform;
	}

	void ColliderComponent::SetDimensions(int width, int height)
	{
		m_Width = width;
		m_Height = height;
	}

	glm::vec2 ColliderComponent::GetDimensions()
	{
		return glm::vec2(m_Width, m_Height);
	}

	glm::vec2 ColliderComponent::GetPosition()
	{
		return glm::vec2(m_OwningTransform->m_Location);
	}

	void ColliderComponent::Update(float deltaTime)
	{
		if (m_DoCollision)
			CollisionHandler::AddCollider(this, m_IsStatic);
	}
}