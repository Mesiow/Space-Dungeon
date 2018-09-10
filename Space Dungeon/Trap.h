#pragma once

class Trap
{
public:
	Trap(int x, int y)
		:x(x), y(y)
	{

	}

public:
	void setPosX(int x) { this->x = x; }
	void setPosY(int y) { this->y = y; }
	void setPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

public:
	inline static constexpr char getSymbol() { return trap; }
	inline int &getPosX() { return x; }
	inline int &getPosY() { return y; }

private:
	static constexpr char trap = 'T';
	int x, y;

};