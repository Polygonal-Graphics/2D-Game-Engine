#pragma once

#include <vector>

namespace Polygame
{
    class GameObject;
    class ColliderComponent;

    // A class that takes in a scene root and performs collision checks on the colliders attached to GameObjects in that scene.
    class CollisionHandler
    {
    public:

        // Takes in a scene root and collects all collisions. Then, checks if dynamic colliders have collided with any
        // other dynamic colliders or static colliders, and calls their OnCollision methods.
        static void CheckCollisions() { return Get().CheckCollisionsImpl(); }

        // Colliders sent through this method will be tested in collision simulation
        static void AddCollider(ColliderComponent* collider, bool isStatic) { return Get().AddColliderImpl(collider, isStatic); }

    private:

        // Checks if the given bounding boxes are colliding / overlapping.
        bool BoundingBoxCollisionCheck(ColliderComponent* colliderA, ColliderComponent* colliderB);

        // Holds all of the dynamic colliders to test for collisions
        std::vector<ColliderComponent*> m_DynamicColliders;
        // Holds all of the static colliders to test for collisions
        std::vector<ColliderComponent*> m_StaticColliders;

        static CollisionHandler& Get()
        {
            static CollisionHandler instance;
            return instance;
        }

        void CheckCollisionsImpl();
        void AddColliderImpl(ColliderComponent* collider, bool isStatic);

        CollisionHandler() {}
    };
}
