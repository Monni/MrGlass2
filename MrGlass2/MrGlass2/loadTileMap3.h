#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <fstream>
#include <cctype>
#include <string>

class LoadTileMap3 {
public:

	LoadTileMap3();											// Oletuskonstruktori
	~LoadTileMap3();											// Destruktori
	void Draw(sf::RenderWindow &window);					// TileMap piirtopinnalle
	void init();											// Hakee tiedoston, asettaa ensimm‰isen rivin hakemaan spritesheet, lukee sprithesheetilta tilet

private:
	std::string tileLocation;
	sf::Texture tileTexture;
	sf::Sprite tiles;
	sf::Vector2i map[100][100];								// 2-ulotteinen vektori
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);			// Aloittaa tiilien tulkinnan nollakohdasta (0,0), k‰ytet‰‰n rivinvaihtojen laskemiseen
};