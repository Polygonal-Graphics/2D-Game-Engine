#pragma once

#include "BaseComponent.h"

namespace Polygame
{
  class ColliderComponent : BaseComponent
  {
    public:

    private:
      // True if a collision was detected with this collider during the frame
      bool m_IsColliding = false;
      
  }
}
