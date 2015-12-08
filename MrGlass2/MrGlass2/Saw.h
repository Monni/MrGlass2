#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Enemy.h"

class Saw : public Enemy {
public:
	Saw();															// Oletuskonstruktori
	Saw(std::string, float, float, sf::Texture *);					// Konstruktori
	~Saw();															// Destruktori

private:
	float y;														// Olion y-koordinaatti
	float x;														// Olion x-koordinaatti
};