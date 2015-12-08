#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <fstream>
#include <cctype>
#include <string>

class LoadTileMap2 {
public:

	LoadTileMap2();											// Oletuskonstruktori
	~LoadTileMap2();											// Destruktori
	void Draw(sf::RenderWindow &window);					// TileMap piirtopinnalle
	void init();											// Hakee tiedoston, asettaa ensimm‰isen rivin hakemaan spritesheet, lukee sprithesheetilta tilet

private:
	std::string tileLocation;
	sf::Texture tileTexture;
	sf::Sprite tiles;
	sf::Vector2i map[100][100];								// 2-ulotteinen vektori
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);			// Aloittaa tiilien tulkinnan nollakohdasta (0,0), k‰ytet‰‰n rivinvaihtojen laskemiseen
};