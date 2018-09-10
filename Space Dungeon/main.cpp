#include <iostream>
#include "Game.h"

int main()
{
	Game game;

	while (game.isRunning())
	{
		game.render();
		game.input();
		game.update();
		system("PAUSE");
		system("CLS");
	}

	return 0;
}