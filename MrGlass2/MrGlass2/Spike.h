#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Enemy.h"

class Spike : public Enemy {
public:
	Spike();
	~Spike();
	void update();
	void draw(sf::RenderWindow &window);
	void checkCollision();

private:
	float bottom;
	float top;
	float left;
	float right;
	float y;
	float x;
	float movespeed = 1;
};