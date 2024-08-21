#include "Game.h"
#include "Scene.h"
#include "GameObjects/Player.h"
#include "GameObjects/Background.h"

using namespace Polygame;

int main()
{
	// Init Game (and GLAD)
	Game::Init();

	// Create the scene and GameObjects
	Scene* scene = new Scene;
	Background* background = new Background;
	Player* player = new Player;

	// Add the GameObjects to the scene
	scene->AddGameObject(background);
	scene->AddGameObject(player);

	// Set the game scene and start the game
	Game::SetScene(scene);
	Game::Start();

	return 0;
}