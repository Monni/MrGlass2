#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Enemy : public sf::RectangleShape {
public:
	Enemy();													// Oletuskonstruktori
	~Enemy();													// Destruktori
	void update();												// Hakee enemyn sijainnin
	float bottom, top, left, right;								// Collisionin m‰‰rittely
	void draw(sf::RenderWindow &window);						// Olio piirtopinnalle
	void move();

private:
	int moveOrNot = 1;
	int range = 0;
	float movespeed = 0.1;
	float y;													// Olion y-koordinaatti
	float x;													// Olion x-koordinaatti
};