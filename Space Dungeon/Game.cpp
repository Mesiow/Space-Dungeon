#include "Game.h"

Game::Game()
	:running(true)
{
	world = new World();
}

Game::~Game()
{
	delete world;
}


void Game::update()
{
	world->update();
}

void Game::input()
{
	world->input();
}

void Game::render()
{
	world->render();
}

bool Game::isRunning()
{
	if (world->isOver())
		running = false;

	return running;
}
