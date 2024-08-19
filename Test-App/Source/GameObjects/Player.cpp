#include "Player.h"

#include "Components/TransformComponent.h"
#include "InputManager.h"

#include <iostream>

Player::Player()
{
	m_Transform->m_Scale = glm::vec3(100.0f, 100.0f, 1.0f);
}

void Player::Update(float deltaTime)
{
	if (Polygame::InputManager::GetKeyDown(68))
	{
		m_Transform->m_Location += glm::vec3(30.0f * deltaTime, 0.0f, 0.0f);
	}
	if (Polygame::InputManager::GetKeyDown(83))
	{
		m_Transform->m_Location += glm::vec3(0.0f, 30.0f * deltaTime, 0.0f);
	}
	if (Polygame::InputManager::GetKeyDown(65))
	{
		m_Transform->m_Location += glm::vec3(-30.0f * deltaTime, 0.0f, 0.0f);
	}
	if (Polygame::InputManager::GetKeyDown(87))
	{
		m_Transform->m_Location += glm::vec3(0.0f, -30.0f * deltaTime, 0.0f);
	}
}
