#pragma once
#include "SFML/Graphics.hpp"
#include "character.h"
#include "loadTileMap.h"
#include "Spike.h"
#include "Enemy.h"
#include "Saw.h"



class Level1 {
public:
	Level1(float width, float height);
	~Level1();
	void draw(sf::RenderWindow &window);
	void init();
	sf::Texture glassmantex;
	Character glassman;
	sf::Texture spiketex;
	
	sf::Texture sawtex;
	LoadTileMap lvl1;
	//luodaan dynaaminen Enemy vektori
	std::vector<Enemy*> enemies;
	std::vector<Enemy> enemies2;
	std::vector<std::vector<int>> colMap;
	sf::Clock dClock;		// dClock FPS:stä riippumaton peliaika
	void loadCollisionMap();



private:

	sf::Font font;
	const float GAME_SPEED = 200.0f;

	int collisioncounter = 0;
};