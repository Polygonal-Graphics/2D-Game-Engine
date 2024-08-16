#include "GameObject.h"

#include "Components/BaseComponent.h"

#include <iostream>

namespace Polygame
{
	void GameObject::Start()
	{
		if (m_NextGameObject) m_NextGameObject->Start();

		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->Start();
		}
	}

	void GameObject::Update(float deltaTime)
	{
		if (m_NextGameObject) m_NextGameObject->Update(deltaTime);

		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->Update(deltaTime);
		}
	}

	void GameObject::AddComponent(BaseComponent* component)
	{
		if (!component)
			std::cout << "Attempt to add null component\n";

		m_Components.push_back(component);
	}

	GameObject::~GameObject()
	{
		// Fix the linked list for when object is deleted.
		if (m_NextGameObject && m_PreviousGameObject)
		{
			m_PreviousGameObject->m_NextGameObject = m_NextGameObject;
			m_NextGameObject->m_PreviousGameObject = m_PreviousGameObject;
		}
		else if (m_PreviousGameObject)
		{
			m_PreviousGameObject->m_NextGameObject = nullptr;
		}

		// Delete each component to free memory.
		for (int i = 0; i < m_Components.size(); i++)
		{
			delete m_Components[i];
		}
	}
}