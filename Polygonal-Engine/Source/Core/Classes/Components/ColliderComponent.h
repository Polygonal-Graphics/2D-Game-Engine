#pragma once

#include "BaseComponent.h"

namespace Polygame
{
    class ColliderComponent : public BaseComponent
    {
    public:

    protected:

        virtual void Update(float deltaTime) override;

    private:
        // True if a collision was detected with this collider during the frame
        bool m_IsColliding = false;
        // Static colliders do not move
        bool m_IsStatic = false;
        bool m_DoCollision = true;

    };
}
