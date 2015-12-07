#include "goal.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Goal::Goal() {}

Goal::~Goal() {}

void Goal::update() {
	bottom = getPosition().y + getSize().y-5;
	left = getPosition().x + 5;
	right = getPosition().x + getSize().x-10;
	top = getPosition().y + 10;
}

void Goal::setGoalLocation(std::string imagename, float x, float y, sf::Texture * tex) {
	sf::Image img;
	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(50, 60));
	this->setPosition(x, y);
	this->setTexture(tex);
}

void Goal::draw(sf::RenderWindow & window) {
	window.draw(*this);
}