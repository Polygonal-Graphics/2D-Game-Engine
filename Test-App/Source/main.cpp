#include "Game.h"
#include "Scene.h"
#include <iostream>

using namespace Polygame;

int main()
{
	Scene* scene = new Scene;
	Game::SetScene(scene);
	Game::Start();

	return 0;
}