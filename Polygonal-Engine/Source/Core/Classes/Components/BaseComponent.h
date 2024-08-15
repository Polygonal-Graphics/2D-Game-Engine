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
	};
}