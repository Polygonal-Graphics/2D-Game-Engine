#pragma once

#include <vector>

namespace Polygame
{
	class BaseComponent;

	/*
	* The GameObject class serves as a container for components that drive gameplay.
	*/
	class GameObject
	{
		friend class Scene;

	public:
		~GameObject();

		// Adds the given component to the GameObject, storing the component in the Components vector.
		void AddComponent(BaseComponent* component);
		// Returns a pointer to the first component of the given type contained in the GameObject's Components vector. Returns a nullptr if no object of the type is found.
		BaseComponent* GetComponent(const char* componentTypeString);

	protected:
		// Called before the first tick of the game loop.
		virtual void Start();
		// Called every tick of the game loop.
		virtual void Update(float deltaTime);

	private:
		// The components attached to the GameObject.
		std::vector<BaseComponent*> m_Components;

		// The next GameObject in the linked list of the owning scene.
		GameObject* m_NextGameObject = nullptr;

		// The previous GameObject in the linked list of the owning scene.
		GameObject* m_PreviousGameObject = nullptr;
	};

}