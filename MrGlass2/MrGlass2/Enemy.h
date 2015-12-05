#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Enemy : public sf::RectangleShape {
public:
	Enemy();
	~Enemy();
	void update();
	void draw(sf::RenderWindow &window);
	void setEnemyData(std::string, float, float, sf::Texture *);

private:
	float y;
	float x;
	float movespeed;
};