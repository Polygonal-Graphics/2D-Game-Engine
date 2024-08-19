#include "Game.h"
#include "Scene.h"
#include "GameObjects/Player.h"

using namespace Polygame;

int main()
{
	Scene* scene = new Scene;
	Player* player = new Player;
	scene->AddGameObject(player);
	Game::SetScene(scene);
	Game::Start();

	return 0;
}