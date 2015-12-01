#include "spike.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Spike::Spike() {}

Spike::~Spike() {}

void Spike::update() {

}

void Spike::draw(sf::RenderWindow & window) {
	window.draw(*this);
}

void Spike::checkCollision() {

}