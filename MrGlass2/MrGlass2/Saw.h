#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include "Enemy.h"

class Saw : public Enemy {
public:
	Saw();
	Saw(std::string, float, float, sf::Texture *);
	~Saw();
	void update();
	void draw(sf::RenderWindow &window);
	void setEnemyData(std::string, float, float, sf::Texture *);
	void checkCollision();
	//float bottom, top, left, right;

private:

	float y;
	float x;
	float movespeed = 1;
};