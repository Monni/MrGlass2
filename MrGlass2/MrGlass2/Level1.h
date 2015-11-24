#pragma once
#include "SFML/Graphics.hpp"
#include "character.h"


class Level1 {
public:
	Level1(float width, float height);
	~Level1();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	void init();
	sf::Texture glassmantex;
	Character glassman;



private:

	sf::Font font;

};