#pragma once
#include "SFML/Graphics.hpp"
#include "character.h"
#include "loadTileMap.h"
#include "Spike.h"
#include "Enemy.h"
#include "Saw.h"
#include "goal.h"

class Level1 {
public:
	Level1(float width, float height);								// Konstruktori
	~Level1();														// Oletusdestruktori
	void draw(sf::RenderWindow &window);							// Tekstuuri piirtopinnalle
	void init();													// Luo pelaajahahmon ja muut objektit piirtopinnalle
	void loadCollisionMap();										// Ladataan collisionit
	bool checkstate();												// L‰hetet‰‰n menulle tieto, onko pelaaja maalissa
	void startScorecounter();										// Alustaa pistelaskurin
	void stopScorecounter();										// Tallentaa nykyiset pisteet filuun

private:
	sf::Texture glassmantex;										// Glassmanin tekstuuri
	Character glassman;												// Character-luokan glassman
	sf::Texture spiketex;											// Piikkien tekstuuri
	Goal goal;														// Goal-luokan goal
	sf::Texture goaltex;											// Maalin tekstuuri
	sf::Texture sawtex;												// Sahan tekstuuri
	LoadTileMap lvl1;												// Ykkˆskent‰n TileMap
	std::vector<Enemy*> enemies;									// Dynaaminen Enemy vektori
	std::vector<std::vector<int>> colMap;							// Collisionmap vektori
	sf::Clock dClock;												// dClock FPS:st‰ riippumaton peliaika
	const float GAME_SPEED = 200.0f;								// Peliaikavakio
	bool level1finished = false;									// P‰‰stess‰ maaliin muutetaan trueksi ja l‰hetet‰‰n menulle, mik‰ vaihtaa piirrett‰v‰n mapin.
	bool isFalling = false;											// Tarkistetaan putoaako pelaaja collisionia varten, tallennetaan t‰h‰n
	int currentscore;												// Pistelaskurin nykyinen tila
	int scorewaiter = 0;											// Odotuttaa pistelaskurin v‰hennyst‰
};