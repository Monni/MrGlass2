#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Enemy : public sf::RectangleShape {
public:
	Enemy();
	Enemy(std::string, float, float, sf::Texture *);
	~Enemy();
	void update();
	float bottom, top, left, right;
	void draw(sf::RenderWindow &window);
	//void setEnemyData(std::string, float, float, sf::Texture *);

private:
	float y;
	float x;
	float movespeed;
};