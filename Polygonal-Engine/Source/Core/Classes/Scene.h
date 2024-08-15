#pragma once

namespace Polygame
{
	class GameObject;

	/*
	* The Scene class is what holds GameObjects and information about the current game level and how it should be rendered.
	* It is responsible for managing GameObjects and calling their Start and Update methods.
	*/
	class Scene
	{
		friend class Game;

	public:
		Scene();
		~Scene();

		// Adds the given GameObject to the end of the linked list that starts with m_RootObject.
		void AddGameObject(GameObject* object);
		// Returns the last GameObject in the linked list that starts at m_RootObject.
		GameObject* GetLastGameObject();

	private:
		// Called before the first tick of the game loop. This call is propagated down the linked list of GameObjects starting with m_RootObject.
		void Start();
		// Called each tick of the game loop. This call is propagated down the linked list of GameObjects starting with m_RootObject.
		void Update(float deltaTime);

		// The root of the scene that starts the linked list of GameObjects.
		GameObject* m_RootObject = nullptr;
	};
}