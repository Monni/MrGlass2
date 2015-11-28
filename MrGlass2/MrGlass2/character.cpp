#include "character.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Character::Character() {}

Character::~Character() {}

/*
Character::Character(std::string imagename, float x, float y, sf::Texture * tex) {

sf::Image img;
img.loadFromFile(imagename);
img.createMaskFromColor(sf::Color::White);
tex->loadFromImage(img);

this->setSize(sf::Vector2f(18, 39));
this->setPosition(x, y);
this->setTexture(tex);

}*/

void Character::Update() {
	bottom = getPosition().y + getSize().y;
	left = getPosition().x;
	right = getPosition().x + getSize().x;
	top = getPosition().y;
}

void Character::draw(sf::RenderWindow & window) {
	window.draw(*this);
}

void Character::setData(std::string imagename, float x, float y, sf::Texture * tex) {
	sf::Image img;
	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(18, 39));
	this->setPosition(x, y);
	this->setTexture(tex);
}

void Character::moveLeft() {
	setPosition(getPosition() + sf::Vector2f(-movespeed, 0));
}

void Character::moveRight() {
	setPosition(getPosition() + sf::Vector2f(movespeed, 0));
}

void Character::stopjump() {
	isJumping = false;
}

void Character::SetMoveSpeed(float siirtyma) {
	this->movespeed = siirtyma;
	this->jumpspeed = -siirtyma * 2;
	this->jumpreducer = siirtyma / 250;
	this->maxfallspeed = siirtyma * 2.5;
}

void Character::checkmovement() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		isJumping = true;
	}

	if (isJumping) {
		if (!jumpspeedchecked) {
			currentjumpspeed = jumpspeed;
			jumpspeedchecked = true;
		}
		setPosition(getPosition() + sf::Vector2f(0, currentjumpspeed));
		if (currentjumpspeed <= maxfallspeed) {
			currentjumpspeed += jumpreducer;
		}
	}

	
	

	
}
