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
	void move();												// Liikutetaan oliota

private:
	int range = 0;												// Liikkeen pituus
	float movespeed = 0.1;										// Liikenopeus
	float y;													// Olion y-koordinaatti
	float x;													// Olion x-koordinaatti
};