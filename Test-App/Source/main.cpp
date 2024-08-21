#include "Game.h"
#include "Scene.h"
#include "GameObjects/Player.h"
#include "GameObjects/Background.h"

using namespace Polygame;

int main()
{
	Game::Init();
	Scene* scene = new Scene;
	Background* background = new Background;
	Player* player = new Player;
	scene->AddGameObject(background);
	scene->AddGameObject(player);
	Game::SetScene(scene);
	Game::Start();

	return 0;
}