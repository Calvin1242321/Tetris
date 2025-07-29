#pragma once
#include <random>

class Game
{
public:
	Game();
	~Game();

	static unsigned short get_random_number(unsigned min, unsigned max);
private:

public:
	int level;
	int line;
	int point;
};