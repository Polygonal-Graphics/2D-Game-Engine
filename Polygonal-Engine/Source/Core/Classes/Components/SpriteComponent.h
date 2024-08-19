#pragma once

#include "BaseComponent.h"
#include "glm/glm.hpp"

#include <stdint.h>

namespace Polygame
{
	/*
	* A component that invokes the ResourceManager with a file path to a sprite image. The ResourceManager will load the sprite into a table.
	* When the Renderer sees a sprite component, it will find the sprite in the ResourceManager based on m_SpriteName and draw it according to m_SpriteWidth, m_SpriteHeight,
	* and the GameObject's Transform component.
	*/
	class SpriteComponent : public BaseComponent
	{
	public:
		SpriteComponent() {}
		SpriteComponent(const char* name, const char* path, const uint32_t width, const uint32_t height);

		// Sets the info for the Sprite if not using the constructor that does so.
		void SetSpriteInfo(const char* name, const char* path, const uint32_t width, const uint32_t height);

		// The name of the sprite for the lookup table in the ResourceManager
		const char* m_SpriteName = 0;
		// The width of the sprite image
		uint32_t m_SpriteWidth = 1;
		// The height of the sprite image
		uint32_t m_SpriteHeight = 1;

	private:
		// The file path of the sprite for loading it in the ResourceManager
		const char* m_SpritePath = 0;
	};
}