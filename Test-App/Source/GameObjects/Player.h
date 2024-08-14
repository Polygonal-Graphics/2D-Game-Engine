#pragma once

#include "GameObject.h"

namespace Polygame
{
	class TransformComponent;
}

class Player : public Polygame::GameObject
{
public:
	Player();

	Polygame::TransformComponent* Transform;
};