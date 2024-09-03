#include "CollisionHandler.h"

#include "Components/ColliderComponent.h"

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
        return false;
    }
}
