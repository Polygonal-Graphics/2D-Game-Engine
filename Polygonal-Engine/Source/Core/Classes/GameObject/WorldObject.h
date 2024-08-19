#pragma once

#include "GameObject.h"
#include "glm/glm.hpp"

#include <tuple>

namespace Polygame
{
	class TransformComponent;
	class SpriteComponent;

	typedef std::tuple<const char*, glm::mat4> RenderInfo;

	class WorldObject : public GameObject
	{
	public:
		WorldObject();

		// Returns a tuple with the info needed to render the WorldObject. Index 0 contains the name of the sprite in the ResourceManager
		// and index 1 contains the model matrix for rendering the sprite.
		RenderInfo GetRenderInfo();

		// Used to identify the WorldObject in the scene linked list.
		const char* m_Name = "WorldObject";

	protected:
		TransformComponent* m_Transform = nullptr;
		SpriteComponent* m_Sprite = nullptr;
	};
}