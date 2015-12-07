#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Enemy : public sf::RectangleShape {
public:
	Enemy();													// Oletuskonstruktori
	Enemy(std::string, float, float, sf::Texture *);			// Konstruktori
	~Enemy();													// Destruktori
	void update();												// Hakee enemyn sijainnin
	float bottom, top, left, right;								// Collisionin m‰‰rittely
	void draw(sf::RenderWindow &window);						// Olio piirtopinnalle
	//void setEnemyData(std::string, float, float, sf::Texture *);

private:
	float y;													// Olion y-koordinaatti
	float x;													// Olion x-koordinaatti
	float movespeed;
};