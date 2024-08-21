#include "SpriteComponent.h"

#include "../ResourceManager.h"

namespace Polygame
{
	SpriteComponent::SpriteComponent(const char* name, const char* path) : m_SpriteName(name), m_SpritePath(path)
	{
		m_TextureID = ResourceManager::LoadTexture(m_SpriteName, m_SpritePath);
	}

	void SpriteComponent::SetSpriteInfo(const char* name, const char* path)
	{
		m_SpriteName = name;
		m_SpritePath = path;
		m_TextureID = ResourceManager::LoadTexture(m_SpriteName, m_SpritePath);
	}
}