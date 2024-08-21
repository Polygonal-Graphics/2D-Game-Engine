#include "Background.h"

#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "InputManager.h"

#include <iostream>

Background::Background()
{
	m_Sprite->SetSpriteInfo("Background", "Assets/Textures/background.png");
	m_Transform->m_Scale = glm::vec3(1920.0f, 1080.0f, 1.0f);
}