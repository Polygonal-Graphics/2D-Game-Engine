## Polygame V1

<img src="https://github.com/user-attachments/assets/1e822aa3-8c74-4ad6-b719-6c6c85a986e7" width="200" height="200"/>

Polygame is a small game engine created for Windows devices. The following will layout the goals and plans for Polygame V1.

**Goal:** Create an engine capable of making a simple Flappy Bird clone and similar simple games. While this is the desirable outcome of Polygame V1, the project is primarily a learning experience.

**Requirements:** The engine must be capable of abstracting the creation of an OpenGL version of Flappy Bird. Features should include: A rendering system to draw the world, bird, and pipes, an input system that can detect input from the keyboard to control the bird, and simple ECS system to implement bird, pipe, and gameplay logic. The components needed for a Flappy Bird clone will include sprites, colliders, transforms, and a component for managing the game state.

**Building Blocks:** The major building blocks of Polygame will include a `Game` class that will bring together the various subsystems and contain the game loop. A `GameObject` class that will hold various `Components` (another class) that contain gameplay logic. A `Scene` class that will hold all of the `GameObjects` and info needed for rendering the scene. A `Renderer` that will draw the scene according to the information held in the current `Scene`. And finally, an `Input` subsystem that can detect keyboard and mouse inputs.

The articles contained in the <a href="https://github.com/Polygonal-Graphics/Polygame/wiki">wiki</a> explain the workings of the various systems that Polygame provides for game creation.
