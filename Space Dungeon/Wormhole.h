#pragma once

class Wormhole 
{
public:
	Wormhole(int x, int y)
		:x(x), y(y)
	{

	}

public:
	inline int getPosX() { return x; }
	inline int getPosY() { return y; }

public:
	static constexpr char wormhole = 'W';

private:
	int x, y;
};