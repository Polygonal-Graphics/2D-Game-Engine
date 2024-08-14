#include "GameObjects/Player.h"
#include "Components/TransformComponent.h"
#include "Game.h"

int main()
{
	Player player;
	Polygame::BaseComponent* TransformBaseComponent = player.GetComponent("Transform");
	Polygame::TransformComponent* Transform = dynamic_cast<Polygame::TransformComponent*>(TransformBaseComponent);

	Polygame::Game::Start();

	return 0;
}