#include "Headers/Game.h"

Game::Game()
{
	level = 0;
	line = 0;
	point = 0;
}
Game::~Game() {}

unsigned short Game::get_random_number(unsigned min, unsigned max) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);

    unsigned short r = dist(rng);
	return r;
}