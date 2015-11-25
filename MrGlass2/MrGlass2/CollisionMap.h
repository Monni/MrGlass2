#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>

class CollisionMap {
public:

	CollisionMap();
	~CollisionMap();
	void Draw(sf::RenderWindow &window);
	void init();
	std::vector <std::vector<int>>colMap;
protected:

private:


};