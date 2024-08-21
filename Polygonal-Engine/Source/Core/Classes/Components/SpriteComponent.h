#pragma once

#include "BaseComponent.h"
#include "glm/glm.hpp"

#include <stdint.h>

namespace Polygame
{
	/*
	* A component that invokes the ResourceManager with a file path to a sprite image.
	* The ResourceManager will load the sprite and return its texture ID to be stored in RenderInfo and passed to the Renderer,
	* or it will return the texture ID of the already loaded texture with the passed in name to also be stored and sent to the Renderer.
	*/
	class SpriteComponent : public BaseComponent
	{
	public:
		SpriteComponent() {}
		SpriteComponent(const char* name, const char* path);

		// Sets the info for the Sprite if not using the constructor that does so. Automatically invokes the ResourceManager to load the Sprite with passed in info.
		void SetSpriteInfo(const char* name, const char* path);

		// The texture ID for this texture instance.
		uint32_t m_TextureID = 0;

	private:
		// The name of the sprite for the lookup table in the ResourceManager
		const char* m_SpriteName = 0;

		// The file path of the sprite for loading it in the ResourceManager
		const char* m_SpritePath = 0;
	};
}