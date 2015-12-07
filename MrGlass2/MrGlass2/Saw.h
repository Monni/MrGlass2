#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Enemy.h"

class Saw : public Enemy {
public:
	Saw();															// Oletuskonstruktori
	Saw(std::string, float, float, sf::Texture *);					// Konstruktori
	~Saw();															// Destruktori
	void update();													// P‰ivitt‰‰ olion sijainnin
	void draw(sf::RenderWindow &window);							// Olio piirtopinnalle
	void setEnemyData(std::string, float, float, sf::Texture *);	// Olion attribuuttien m‰‰ritys
	//float bottom, top, left, right;

private:

	float y;														// Olion y-koordinaatti
	float x;														// Olion x-koordinaatti
	float movespeed = 1;											// Olion liikenopeus
};