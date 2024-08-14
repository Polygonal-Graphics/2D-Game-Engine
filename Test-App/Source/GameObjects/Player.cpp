#include "Player.h"
#include "Components/TransformComponent.h"

Player::Player()
{
	Transform = new Polygame::TransformComponent;
	AddComponent(Transform);
	Start();
}
