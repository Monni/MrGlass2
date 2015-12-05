#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Enemy.h"

class Spike : public Enemy {
public:
	Spike();
	Spike(std::string, float, float, sf::Texture *);
	~Spike();
	void update();
	void draw(sf::RenderWindow &window);
	void checkCollision();
	float bottom, top, left, right;

private:

	float y;
	float x;
	float movespeed = 1;
};