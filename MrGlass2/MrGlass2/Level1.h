#pragma once
#include "SFML/Graphics.hpp"
#include "character.h"


class Level1 {
public:
	Level1(float width, float height);
	~Level1();

	void draw(sf::RenderWindow &window);
	void init();
	sf::Texture glassmantex;
	Character glassman;
	sf::Clock dClock;		// dClock FPS:st� riippumaton peliaika



private:

	sf::Font font;
	const float GAME_SPEED = 200.0f;

};