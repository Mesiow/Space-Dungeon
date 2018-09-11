#pragma once

class Player 
{
public:
	Player() {}
	Player(int x, int y)
	{
		this->xpos = x;
		this->ypos = y;
	}

public:
	void setPosX(int x) { this->xpos = x; }
	void setPosY(int y) { this->ypos = y; }

	void setPosition(int x, int y)
	{
		this->xpos = x;
		this->ypos = y;
	}

public:
	inline int getXPos()const { return xpos; }
	inline int getYPos()const { return ypos; }

public:
	static constexpr char player = 'P';

private:
	int xpos;
	int ypos;

};