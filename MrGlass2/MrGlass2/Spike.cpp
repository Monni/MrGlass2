#include "spike.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Spike::Spike() {}

Spike::Spike(std::string imagename, float x, float y, sf::Texture * tex) {
	sf::Image img;
	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(40, 30));
	this->setPosition(x, y);
	this->setTexture(tex);
}

Spike::~Spike() {}
