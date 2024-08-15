#include "Scene.h"
#include "GameObject.h"

#include <iostream>

namespace Polygame
{
	Scene::Scene()
	{
		m_RootObject = new GameObject;
	}

	Scene::~Scene()
	{
		GameObject* currentObject = m_RootObject;
		GameObject* nextObject = nullptr;

		while (currentObject)
		{
			nextObject = currentObject->m_NextGameObject;
			delete currentObject;
			currentObject = nextObject;
		}

		std::cout << "Scene deleted\n";
	}

	void Scene::Start()
	{
		m_RootObject->Start();
	}

	void Scene::Update(float deltaTime)
	{
		m_RootObject->Update(deltaTime);
	}

	void Scene::AddGameObject(GameObject* object)
	{
		GameObject* lastObject = GetLastGameObject();
		lastObject->m_NextGameObject = object;
		object->m_PreviousGameObject = lastObject;
	}

	GameObject* Scene::GetLastGameObject()
	{
		GameObject* currentObject = m_RootObject;

		while (currentObject != nullptr && currentObject->m_NextGameObject != nullptr)
		{
			currentObject = currentObject->m_NextGameObject;
		}

		return currentObject;
	}
}

