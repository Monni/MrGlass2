#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Goal : public sf::RectangleShape {
public:
	Goal();																// Oletuskonstruktori
	~Goal();															// Destruktori
	void update();														// Olion sijainnin p‰ivitys
	float bottom, top, left, right;										
	void draw(sf::RenderWindow &window);								// Olio piirtopinnalle
	void setGoalLocation(std::string, float, float, sf::Texture *);		// Olion attribuutien m‰‰ritys(kuva, x ja y sijainti, tekstuuri)

private:
	float y;															// Olion y-koordinaatti
	float x;															// Olion x-koordinaatti
};