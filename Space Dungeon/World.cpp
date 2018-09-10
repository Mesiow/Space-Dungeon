#include "World.h"

World::World()
	:gameover(false), score(0)
{
	srand(time(NULL));

	init();
}

World::~World()
{
	delete player;
	delete entrance;
	delete exit;
	
}

void World::init()
{
	player = new Player(9, 1 + rand() % 9); //spawn player at bottom row and any column
	entrance = new Wormhole(6 + rand() % 8, rand() % 9 + 1);
	exit = new Wormhole(rand() % 6 + 1, rand() % 6 + 1);

	for (int i = 0; i < ROW; i++)
	{
		for (int k = 0; k < COLUMN; k++)
		{
			grid[i][k] = '.';
		}
	}

	setEntityPosition(player->getXPos(), player->getYPos(), player->getSymbol());

	for (int i = 0; i < ROW; i++) //generate traps
	{
		for (int k = 0; k < COLUMN; k++)
		{
			int ran = RandomInt();

			if (ran == 5)
			{
				traps.push_back(Trap(rand() % 9 + 1, rand() % 9 + 1)); //give trap random location and push it into the vector
			}	
		}
	}

	for (unsigned i = 0; i < traps.size(); i++)
		setEntityPosition(traps[i].getPosX(), traps[i].getPosY(), traps[i].getSymbol()); //set trap pos after creating them

	setEntityPosition(entrance->getPosX(), entrance->getPosY(), entrance->getSymbol());
	setEntityPosition(exit->getPosX(), exit->getPosY(), exit->getSymbol());


	initCollision();
	
}

void World::update()
{
	logic();
}

void World::initCollision() //check spawn collisions, called once
{
	int playerX = player->getXPos();
	int playerY = player->getYPos();

	int wormX = entrance->getPosX();
	int wormY = entrance->getPosY();

	//make sure trap does not spawn on player, if it does replace with player
	for (unsigned i = 0; i < traps.size(); i++)
	{
		int trapX = traps[i].getPosX();
		int trapY = traps[i].getPosY();

		if (grid[playerX][playerY] == grid[trapX][trapY]) //check if trap overlaps player when starting game
			grid[playerX][playerY] = 'P';
		
		if (grid[trapX][trapY] == grid[wormX][wormY]) 
		{
			grid[trapX][trapY] = 'W';
			traps.erase(traps.begin() + i);
		}
	}

	if (grid[playerX][playerY] == grid[wormX][wormY]) //if player spawns on wormhole move it up 1
		grid[wormX - 1][wormY] = 'W';

	

}

void World::logic()
{
	enemyMovement();
	collision();
	addScore();
}

void World::enemyMovement()
{
	for (unsigned i = 0; i < traps.size(); i++)
	{
		int random = RandomInt();

		int trapX = traps[i].getPosX();
		int trapY = traps[i].getPosY();

		if (random == 5)
		{
			grid[trapX][trapY - 1]=traps[i].getSymbol();
			grid[trapX][trapY] = '.';
			traps[i].setPosY(trapY - 1); //have position follow trap
			
		}
		else if (random == 3)
		{
			grid[trapX][trapY + 1] = traps[i].getSymbol();
			grid[trapX][trapY] = '.';
			traps[i].setPosY(trapY + 1);
		}
	}
}

void World::addScore()
{
	for (int i = 0; i < COLUMN; i++) //if player reaches top we get a point
	{
		if (grid[0][i] == player->getSymbol())
		{
			score++;
			reset();
		}
			
	}
}

void World::collision() //check for collisions every frame
{
	int playerX = player->getXPos();
	int playerY = player->getYPos();

	int wormX = entrance->getPosX();
	int wormY = entrance->getPosY();

	for (unsigned i = 0; i < traps.size(); i++) //trap collision with player or trap
	{
		int trapX = traps[i].getPosX();
		int trapY = traps[i].getPosY();

		if (grid[playerX][playerY] == grid[trapX][trapY])
		{
			player->setPosition(11, 11);
			grid[playerX][playerY] = '.';

			int x = player->getXPos();
			int y = player->getYPos();

			grid[x][y] = 'P';

			//delete trap after we step into it
			traps.erase(traps.begin() + i);

		}

		if (grid[trapX][trapY] == grid[wormX][wormY]) // check if trap overlaps wormhole entrance or exit and change the wormhole to trap and collapse both holes
		{
			grid[trapX][trapY] = 'T';
		}
	}
	   

	if (grid[playerX][playerY] == grid[wormX][wormY]) //check if player pos and worm hole pos collide
	{
		int wX = exit->getPosX();
		int wY = exit->getPosY();

		player->setPosition(wX, wY);

		grid[wX][wY] = 'P';
		grid[playerX][playerY] = '.';
		grid[wormX][wormY] = '.';
	}


}

void World::reset()
{
	delete player;
	delete entrance;
	delete exit;

	traps.clear();

	init();
}

void World::input()
{
	char input;
	std::cin >> input;

	int playerX = player->getXPos();
	int playerY = player->getYPos();

	switch (input)
	{
	case 'w':
		grid[playerX - 1][playerY] = player->getSymbol();
		grid[playerX][playerY] = '.';

		player->setPosX(playerX - 1);  //update player position
		break;

	case 'a':
		grid[playerX][playerY - 1] = player->getSymbol();
		grid[playerX][playerY] = '.';

		player->setPosY(playerY - 1);
		break;

	case 's':
		grid[playerX + 1][playerY] = player->getSymbol();
		grid[playerX][playerY] = '.';

		player->setPosX(playerX + 1);
		break;

	case 'd':
		grid[playerX][playerY + 1] = player->getSymbol();
		grid[playerX][playerY] = '.';

		player->setPosY(playerY + 1);
		break;

	default:
		break;
	}
}

void World::render()
{
	std::cout << "Player: P  ";
	std::cout << "Trap: T  ";
	std::cout << "Wormhole: W                   " << " Score: " << score;
	std::cout << std::endl;
	for (int i = 0; i < ROW; i++)
	{
		for (int k = 0; k < COLUMN; k++)
		{
			std::cout << grid[i][k] << " ";
		}
		std::cout << std::endl;
	}
}

void World::setEntityPosition(int row, int column, char symbol)
{
	grid[row][column] = symbol;
}
