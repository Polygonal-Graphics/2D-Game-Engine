#pragma once

#include "GameObject/WorldObject.h"

namespace Polygame
{
	class TransformComponent;
}

class Player : public Polygame::WorldObject
{
public:
	Player();

	virtual void Update(float deltaTime) override;

};