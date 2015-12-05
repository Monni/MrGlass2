#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Enemy : public sf::RectangleShape {
public:
	Enemy();
	~Enemy();
	void update();
	void draw(sf::RenderWindow &window);

private:
	float y;
	float x;
	float movespeed;
};