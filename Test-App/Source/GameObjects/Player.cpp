#include "Player.h"
#include "Components/TransformComponent.h"
#include <iostream>

Player::Player()
{
	Transform = new Polygame::TransformComponent;
	AddComponent(Transform);
	Start();
}
