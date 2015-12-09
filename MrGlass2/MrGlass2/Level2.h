#pragma once
#include "SFML/Graphics.hpp"
#include "character.h"
#include "loadTileMap.h"
#include "Spike.h"
#include "Enemy.h"
#include "Saw.h"
#include "goal.h"

class Level2 {
public:
	Level2(float width, float height);								// Konstruktori
	~Level2();														// Oletusdestruktori
	void draw(sf::RenderWindow &window);							// Tekstuuri piirtopinnalle
	void init();													// Luo pelaajahahmon ja muut objektit piirtopinnalle
	void loadCollisionMap();										// Ladataan collisionit
	bool checkstate();												// L‰hetet‰‰n menulle tieto, onko pelaaja maalissa


private:
	sf::Texture glassmantex;										// Glassmanin tekstuuri
	Character glassman;												// Character-luokan glassman
	sf::Texture spiketex;											// Piikkien tekstuuri
	Goal goal;														// Goal-luokan goal
	sf::Texture goaltex;											// Maalin tekstuuri
	sf::Texture sawtex;												// Sahan tekstuuri
	LoadTileMap lvl2;												// Ykkˆskent‰n TileMap
	std::vector<Enemy*> enemies;									// Dynaaminen Enemy vektori

	std::vector<std::vector<int>> colMap;
	sf::Clock dClock;												// dClock FPS:st‰ riippumaton peliaika
	sf::Font font;
	const float GAME_SPEED = 200.0f;								// Peliaikavakio
	bool level2finished = false;									// P‰‰stess‰ maaliin muutetaan trueksi ja l‰hetet‰‰n menulle, mik‰ vaihtaa piirrett‰v‰n mapin.
	bool isFalling = false;
};