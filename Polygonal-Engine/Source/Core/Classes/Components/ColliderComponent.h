#pragma once

#include "BaseComponent.h"
#include "glm/vec2.hpp"

namespace Polygame
{
    class TransformComponent;

    class ColliderComponent : public BaseComponent
    {
    public:
        ColliderComponent(TransformComponent* owningTransform);

        void SetDimensions(int width, int height);
        glm::vec2 GetDimensions();
        glm::vec2 GetPosition();

    protected:

        virtual void Update(float deltaTime) override;

    private:
        TransformComponent* m_OwningTransform = nullptr;

        // True if a collision was detected with this collider during the frame
        bool m_IsColliding = false;
        // Static colliders do not move
        bool m_IsStatic = false;
        bool m_DoCollision = true;
        // Dimensions of the collider
        int m_Width = 10;
        int m_Height = 10;

    };
}
