#pragma once
#include <iostream>
#include "Random.h"
#include "Player.h"
#include "Trap.h"
#include "Wormhole.h"



#define ROW 12
#define COLUMN 12
#define MAX_WORM_HOLES 2
#include <vector>

class World
{
public:
	World();
	~World();

	//delete copying and assigning
	World(const World &other) = delete;
	World(World &&other) = delete;
	World &operator=(const World &other) = delete;

public:
	void update();
	void input();
	void init();
	void initCollision();
	void render();

public:
	void logic();
	void enemyMovement();
	void addScore();
	void collision();
	void reset();
	void setEntityPosition(int row, int column, char symbol);

public:
	inline bool isOver()const { return gameover; }

private:
	char grid[ROW][COLUMN];
	bool gameover;
	int score;

private:
	Player *player;
	Wormhole *entrance;
	Wormhole *exit;
	std::vector<Trap> traps;

};
