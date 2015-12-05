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

	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(18, 39));
	this->setPosition(x, y);
	this->setTexture(tex);

}

void Character::updateimg(sf::Texture * tex) {
	if (movingleft) {
		runningleft.loadFromFile("resources/glassman_left_running.gif");
		tex->loadFromImage(runningleft);
	} else if (movingright) {
		runningright.loadFromFile("resources/glassman_right_running.gif");
		tex->loadFromImage(runningright);
	}

	if (lastleft) {
		standingleft.loadFromFile("resources/glassman_left_standing.gif");
		tex->loadFromImage(standingleft);
	} else if (lastright) {
		standingright.loadFromFile("resources/glassman_right_standing.gif");
		tex->loadFromImage(standingright);
	}

}



void Character::moveLeft() {
	setPosition(getPosition() + sf::Vector2f(-movespeed, 0));
	movingleft = true;
	lastleft = true;
	lastright = false;
	movingright = false;

	
}

void Character::moveRight() {
	setPosition(getPosition() + sf::Vector2f(movespeed, 0));
	movingleft = false;
	lastleft = false;
	movingright = true;
	lastright = true;
	
}

void Character::stopjump() {
	this->isJumping = false;
	this->jumpspeedchecked = false;
}

void Character::SetMoveSpeed(float siirtyma) {
	this->movespeed = siirtyma;
	this->jumpspeed = -0.4 * 1.5;
	this->jumpreducer = siirtyma / 250;
	this->maxfallspeed = siirtyma * 2.5;
}


void Character::setFalling(bool falling) {
	this->isFalling = falling;
	if (falling == false)
		fallspeedchecked = false;
}


void Character::checkmovement() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveLeft();
	}
	else
		movingleft = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveRight();
	} else
		movingright = false;
	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping) {
		this->isJumping = true;
		jumpspeedchecked = false;
	}

	if (isJumping) {
		if (!jumpspeedchecked) {
			fallspeed = jumpspeed;
			jumpspeedchecked = true;
		}
		setPosition(getPosition() + sf::Vector2f(0, fallspeed));
		if (fallspeed <= maxfallspeed) {
			fallspeed += jumpreducer;
		}
	}

	if (isFalling && !isJumping) {
		if (!fallspeedchecked) {
			fallspeed = 0;
			fallspeedchecked = true;
		}
		setPosition(getPosition() + sf::Vector2f(0, fallspeed));
		if (fallspeed <= maxfallspeed) {
			fallspeed += jumpreducer;
		}
	}





}
