#include "Classes/Game.h"
#include <iostream>

int main()
{
	PE::Game game;
	if (!game.Start()) return -1;

	return 0;
}