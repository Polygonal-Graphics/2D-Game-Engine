#include "SpriteComponent.h"

namespace Polygame
{
	SpriteComponent::SpriteComponent(const char* name, const char* path, const uint32_t width, const uint32_t height) : m_SpriteName(name), m_SpritePath(path), m_SpriteWidth(width), m_SpriteHeight(height)
	{
		// ResourceManager::LoadTexture(name, path, width, height)
	}

	void SpriteComponent::SetSpriteInfo(const char* name, const char* path, const uint32_t width, const uint32_t height)
	{
		m_SpriteName = name;
		m_SpritePath = path;
		m_SpriteWidth = width;
		m_SpriteHeight = height;
		// ResourceManager::LoadTexture(name, path, width, height)
	}
}