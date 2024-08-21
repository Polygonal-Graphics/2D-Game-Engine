#include "Player.h"

#include "Components/TransformComponent.h"
#include "Components/SpriteComponent.h"
#include "InputManager.h"

#include <iostream>

Player::Player()
{
	m_Sprite->SetSpriteInfo("Bird", "Assets/Textures/bird.png");
	m_Transform->m_Scale = glm::vec3(100.0f, 100.0f, 1.0f);
}

void Player::Update(float deltaTime)
{
	WorldObject::Update(deltaTime);

	// Move right
	m_Transform->m_Location += glm::vec3(100.0f * deltaTime, 0.0f, 0.0f);

	// Gravity
	if (m_Transform->m_Location.y <= 980.0f)
	{
		m_Transform->m_Location += glm::vec3(0.0f, fallTime * 7.0f * deltaTime, 0.0f);
		fallTime += 1;
	}

	// Input
	if (Polygame::InputManager::GetKeyDown(32) && !spacePressed)
	{
		m_Transform->m_Location += glm::vec3(0.0f, -100.0f, 0.0f);
		fallTime = 0;
		spacePressed = true;
	}
	else if (!Polygame::InputManager::GetKeyDown(32))
		spacePressed = false;
}
