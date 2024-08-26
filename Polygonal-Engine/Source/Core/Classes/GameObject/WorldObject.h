#pragma once

#include "GameObject.h"
#include "glm/glm.hpp"

#include <tuple>

namespace Polygame
{
	class TransformComponent;
	class SpriteComponent;

	typedef std::tuple<uint32_t, glm::mat4> RenderInfo;

	/*
	* A child of GameObject that will be rendered to the scene based on the properties of its Transform and Sprite components that are passed to the Renderer through
	* GetRenderInfo().
	*/
	class WorldObject : public GameObject
	{
	public:
		WorldObject();

		// Returns a tuple with the info needed to render the WorldObject. Index 0 contains the TextureID of the sprite for binding
		// and index 1 contains the model matrix for rendering the sprite.
		RenderInfo GetRenderInfo();

	protected:
		// Used to identify the WorldObject in the scene linked list.
		const char* m_Name = "WorldObject";
		// The TransformComponent whos model matrix will be used when rendering the WorldObject.
		TransformComponent* m_Transform = nullptr;
		// The SpriteComponent whos TextureID will be used when rendering the WorldObject.
		SpriteComponent* m_Sprite = nullptr;
	};
}