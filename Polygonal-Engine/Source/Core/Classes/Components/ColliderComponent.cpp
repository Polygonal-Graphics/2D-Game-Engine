#include "ColliderComponent.h"

#include "../CollisionHandler.h"

namespace Polygame
{
	void ColliderComponent::Update(float deltaTime)
	{
		if (m_DoCollision)
			CollisionHandler::AddCollider(this, m_IsStatic);
	}
}