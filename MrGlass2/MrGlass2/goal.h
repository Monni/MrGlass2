#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Goal : public sf::RectangleShape {
public:
	Goal();
	Goal(std::string, float, float, sf::Texture *);
	~Goal();
	void update();
	float bottom, top, left, right;
	void draw(sf::RenderWindow &window);
	void setGoalLocation(std::string, float, float, sf::Texture *);

private:
	float y;
	float x;
};