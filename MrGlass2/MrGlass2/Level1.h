#pragma once
#include "SFML/Graphics.hpp"
#include "character.h"
#include "loadTileMap.h"



class Level1 {
public:
	Level1(float width, float height);
	~Level1();
	void draw(sf::RenderWindow &window);
	void init();
	sf::Texture glassmantex;
	Character glassman;
	LoadTileMap lvl1;
	std::vector<std::vector<int>> colMap;
	sf::Clock dClock;		// dClock FPS:stä riippumaton peliaika
	void loadCollisionMap();



private:

	sf::Font font;
	const float GAME_SPEED = 200.0f;
};