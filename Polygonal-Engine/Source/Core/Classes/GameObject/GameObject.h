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
		template <class T> T* GetComponent();
		// Returns the next GameObject in the linked list or nullptr if none exists.
		GameObject* GetNextObject() const { return m_NextGameObject; }

		// Used to identify the GameObject in the scene linked list.
		const char* m_Name = "GameObject";

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
	
	template<class T>
	inline T* GameObject::GetComponent()
	{
		T* foundComponent = nullptr;
		for (BaseComponent* component : m_Components)
		{
			foundComponent = dynamic_cast<T*>(component);
			if (foundComponent)
				return foundComponent;
		}

		return nullptr;
	}
}