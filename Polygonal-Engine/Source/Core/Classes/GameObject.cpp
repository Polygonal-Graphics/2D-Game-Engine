#include "GameObject.h"
#include "Components/BaseComponent.h"
#include <iostream>

namespace Polygame
{
	void GameObject::Start()
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->Start();
		}
	}

	void GameObject::Update(float deltaTime)
	{
		for (int i = 0; i < m_Components.size(); i++)
		{
			m_Components[i]->Update(deltaTime);
		}
	}

	void GameObject::AddComponent(BaseComponent* component)
	{
		if (!component)
			std::cout << "Attempt to add null component\n";

		component->m_Parent = this;
		m_Components.push_back(component);
	}

	BaseComponent* GameObject::GetComponent(const char* componentTypeString)
	{
		for (BaseComponent* component : m_Components)
		{
			if (component->GetTypeString() == componentTypeString)
				return component;
		}

		return nullptr;
	}

	GameObject::~GameObject()
	{
		// Delete each component to free memory.
		for (int i = 0; i < m_Components.size(); i++)
		{
			delete m_Components[i];
		}
	}
}