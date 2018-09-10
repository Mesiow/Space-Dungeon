#pragma once
#include "World.h"

class Game
{
public:
	Game();
	~Game();

	Game(const Game &other) = delete;
	Game(Game &&other) = delete;
	Game &operator=(const Game &other) = delete;

public:
	void update();
	void input();
	void render();

public:
	bool isRunning();

private:
	World *world;
	bool running;
};