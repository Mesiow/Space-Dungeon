#pragma once
#include <string>
#include <iostream>

class Entity
{
public:
	Entity() {}
	Entity(const std::string &name, float posx, float posy)
		:name(name), x(posx), y(posy)
	{

	}

public:
	/*friend std::ostream &operator<<(std::ostream &os, Entity &e)
	{
		os << "Position: " << e.position << " | " << "Size: " << e.size << std::endl;
		return os;
	}*/

protected:
	std::string name;
	float x, y;

};
