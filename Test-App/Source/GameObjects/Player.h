#pragma once

#include "GameObject/WorldObject.h"

class Player : public Polygame::WorldObject
{
public:
	Player();

	virtual void Update(float deltaTime) override;

private:
	int fallTime = 0;
	bool spacePressed = false;

};