#include "GameObjects/Player.h"
#include "Scene.h"
#include "Game.h"
#include <iostream>

using namespace Polygame;

int main()
{
	Scene* scene = new Scene;
	Player* player = new Player;
	Player* player2 = new Player;
	scene->AddGameObject(player);
	Game::SetScene(scene);
	Game::Start();

	return 0;
}