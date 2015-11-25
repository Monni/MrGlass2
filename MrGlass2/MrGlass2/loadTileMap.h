#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <fstream>
#include <cctype>
#include <string>

class LoadTileMap {
public:

	LoadTileMap();
	~LoadTileMap();
	void Draw(sf::RenderWindow &window);
	void init();
	std::string tileLocation;
	sf::Texture tileTexture;
	sf::Sprite tiles;
	sf::Vector2i map[100][100];
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);
protected:

private:


};