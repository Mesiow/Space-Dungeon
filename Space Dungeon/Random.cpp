#include "Random.h"

int RandomInt()
{
	int ran = 1 + rand() % 10;
	return ran;
}