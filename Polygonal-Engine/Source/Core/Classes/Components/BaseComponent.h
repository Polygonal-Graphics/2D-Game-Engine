#pragma once

namespace Polygame
{	
	/*
	* The BaseComponent class serves as the base for all components, which are the building blocks of gameplay in Polygame and are attached to GameObjects.
	*/
	class BaseComponent
	{
		friend class GameObject; // Parent GameObject needs to call Start() and Update().

	protected:
		// Called before the first tick of the game loop.
		virtual void Start() {}
		// Called every tick of the game loop.
		virtual void Update(float deltaTime) {}

		const char* m_TypeString = "BaseComponent"; // String used to identify the component's type (should be unique for each derived component class).

	public:
		// Returns the TypeString of the component.
		const char* GetTypeString() { return m_TypeString; }
	};
}