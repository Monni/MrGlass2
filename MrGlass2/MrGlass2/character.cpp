#include "character.h"
#include <string>
#include "SFML/Graphics.hpp"

Character::Character() {}
Character::~Character() {}


Character::Character(std::string imagename, float x, float y, sf::Texture * tex) {

	sf::Image img;
	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(18, 39));
	this->setPosition(x, y);
	this->setTexture(tex);

}

/*void Character::draw(sf::RenderWindow & window) {
	window.draw(*this);
}*/

int Character::getX() {
	return x;
}

void Character::getNextPosition() {
	setPosition(getPosition() + sf::Vector2f(0, +1));
}