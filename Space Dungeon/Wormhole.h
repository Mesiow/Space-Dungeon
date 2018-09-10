#pragma once

class Wormhole 
{
public:
	Wormhole(int x, int y)
		:x(x), y(y)
	{

	}

public:
	inline static constexpr char getSymbol() { return wormhole; }
	inline int getPosX() { return x; }
	inline int getPosY() { return y; }

private:
	static constexpr char wormhole = 'W';
	int x, y;
};