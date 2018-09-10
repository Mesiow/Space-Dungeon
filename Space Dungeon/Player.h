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
	inline static constexpr char getSymbol() { return player; }
	inline int getXPos()const { return xpos; }
	inline int getYPos()const { return ypos; }

private:
	static constexpr char player = 'P';
	int xpos;
	int ypos;

};