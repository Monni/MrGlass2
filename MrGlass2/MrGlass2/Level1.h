#pragma once
#include "SFML/Graphics.hpp"


class Level1 {
public:
	Level1(float width, float height);
	~Level1();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	


private:

	sf::Font font;

};