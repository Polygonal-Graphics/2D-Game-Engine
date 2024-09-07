#include "CollisionHandler.h"

#include "Components/ColliderComponent.h"
#include "glm/glm.hpp"

namespace Polygame
{
    void CollisionHandler::CheckCollisionsImpl()
    {
        for (ColliderComponent* testingCollider : m_DynamicColliders)
        {
            for (ColliderComponent* staticCollider : m_StaticColliders)
            {
                BoundingBoxCollisionCheck(testingCollider, staticCollider);
            }

            for (ColliderComponent* dynamicCollider : m_DynamicColliders)
            {
                if (testingCollider != dynamicCollider)
                {
                    BoundingBoxCollisionCheck(testingCollider, dynamicCollider);
                }
            }
        }

        // Clear collision vectors. Colliders to be checked will be sent each frame.
        m_StaticColliders.clear();
        m_DynamicColliders.clear();
    }

    void CollisionHandler::AddColliderImpl(ColliderComponent* collider, bool isStatic)
    {
        isStatic ? m_StaticColliders.push_back(collider) : m_DynamicColliders.push_back(collider);
    }

    bool CollisionHandler::BoundingBoxCollisionCheck(ColliderComponent* colliderA, ColliderComponent* colliderB)
    {
        glm::vec2 aPos = colliderA->GetPosition();
        glm::vec2 bPos = colliderB->GetPosition();
        glm::vec2 aSize = colliderA->GetDimensions();
        glm::vec2 bSize = colliderB->GetDimensions();

        // Check for x overlap
        bool collisionX = aPos.x + aSize.x >= bPos.x && bPos.x + bSize.x >= aPos.x;

        // Check for y overlap
        bool collisionY = aPos.y + aSize.y >= bPos.y && bPos.y + bSize.y >= aPos.y;

        return collisionX && collisionY;
    }
}
