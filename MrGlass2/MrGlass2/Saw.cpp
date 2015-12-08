#include "saw.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Saw::Saw() {}

Saw::Saw(std::string imagename, float x, float y, sf::Texture * tex) {
	sf::Image img;
	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(70, 30));
	this->setPosition(x, y);
	this->setTexture(tex);
}

Saw::~Saw() {}

void Saw::draw(sf::RenderWindow & window) {
	window.draw(*this);
	std::cout << "sadfasfsaf";
}

void Saw::setEnemyData(std::string imagename, float x, float y, sf::Texture * tex) {
	sf::Image img;
	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(70, 30));
	this->setPosition(x, y);
	this->setTexture(tex);
}

void Saw::update() {
}