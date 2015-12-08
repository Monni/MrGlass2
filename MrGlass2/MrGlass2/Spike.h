#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Enemy.h"

class Spike : public Enemy {
public:
	Spike();														// Oletuskonstruktori
	Spike(std::string, float, float, sf::Texture *);				// Overload-konstruktori
	~Spike();														// Destruktori
	void update();													// Olion sijainnin p‰ivitys
	void draw(sf::RenderWindow &window);							// Olio piirtopinnalle
	void setEnemyData(std::string, float, float, sf::Texture *);	// Olion attribuuttien m‰‰ritys

private:
	float y;														// Olion y-koordinaatti
	float x;														// Olion x-koordinaatti
};