#pragma once

#include <stdint.h>

namespace Polygame
{
	class GameObject;
	class Shader;

	/*
	* The Renderer class is a singleton class that accepts a scene root GameObject as input.
	* It will render all objects in the linked list starting at the root that derive from the WorldObject class.
	*/
	class Renderer
	{
	public:
		~Renderer();

		// Sets the m_SceneRoot member variable to the passed in GameObject.
		static void SetRoot(GameObject* sceneRoot) { Get().SetRootImpl(sceneRoot); };
		// Called from the Game class to render the scene.
		static void Render() { Get().RenderImpl(); };

	private:

		// Initializes and returns the static Renderer singleton instance
		static Renderer& Get()
		{
			static Renderer instance;
			return instance;
		}

		/*
		* Private members
		*/

		GameObject* m_SceneRoot = nullptr;
		Shader* m_ActiveShader = nullptr;
		uint32_t m_QuadVAO = 0;

		/*
		* Static Implementations
		*/

		void SetRootImpl(GameObject* sceneRoot);
		void RenderImpl();

		// Private constructor for singleton
		Renderer();
	};
}