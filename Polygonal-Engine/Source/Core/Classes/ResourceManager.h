#pragma once

#include <stdint.h>
#include <map>

namespace Polygame
{
	class ResourceManager
	{
	public:

		// Returns a loaded texture with the given name. If there is no loaded texture, loads a texture and returns that.
		static uint32_t LoadTexture(const char* name, const char* path) { return Get().LoadTextureImpl(name, path); }

	private:

		// Initializes and returns the static ResourceManager singleton instance
		static ResourceManager& Get()
		{
			static ResourceManager instance;
			return instance;
		}

		/*
		* Static Implementations
		*/
		uint32_t LoadTextureImpl(const char* name, const char* path);

		// Stores all loaded textures. Remains the same among all Texture instances.
		std::map<const char*, uint32_t> TextureMap;

		ResourceManager() {};
	};
}