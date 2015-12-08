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

void Character::setData(std::string imagename, float x, float y, sf::Texture * tex) {

	img.loadFromFile(imagename);
	img.createMaskFromColor(sf::Color::White);
	tex->loadFromImage(img);

	this->setSize(sf::Vector2f(18, 39));
	this->setPosition(x, y);
	this->setTexture(tex);

}

bool Character::checkFalling() {
	if (this->fallspeed >= 0) {
		return true;
	}
	else return false;
}

void Character::updateimg(sf::Texture * tex) {
	sf::err().rdbuf(NULL);
	if (movingleft) {
		runningleft.loadFromFile("resources/glassman_left_running.gif");
		if (!runningleft.loadFromFile("resources/glassman_left_running.gif")) {
			throw ImgException("Glassman couldn't figure out how to run left!");
		}
		tex->loadFromImage(runningleft);
	}
	else if (movingright) {
		runningright.loadFromFile("resources/glassman_right_running.gif");
		if (!runningright.loadFromFile("resources/glassman_right_running.gif")) {
			throw ImgException("Glassman couldn't figure out how to run right!");
		}
		tex->loadFromImage(runningright);
	}

	if (lastleft) {
		standingleft.loadFromFile("resources/glassman_left_standing.gif");
		if (!runningright.loadFromFile("resources/glassman_left_standing.gif")) {
			throw ImgException("Glassman couldn't figure out how to look left!");
		}
		tex->loadFromImage(standingleft);
	}
	else if (lastright) {
		standingright.loadFromFile("resources/glassman_right_standing.gif");
		if (!runningright.loadFromFile("resources/glassman_right_standing.gif")) {
			throw ImgException("Glassman couldn't figure out how to look right!");
		}
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
	if (isCollisible) {
		this->isJumping = false;
		this->jumpspeedchecked = false;
	}
	else if (isCollisible && !collided) {
		this->fallspeed = jumpspeed;
		this->collided = true;
	}
}

void Character::shatter() {
	this->isJumping = true;
	this->isCollisible = false;
}

void Character::SetMoveSpeed(float siirtyma) {
	this->movespeed = 0.28;
	this->jumpspeed = -0.35 * 1.5;
	this->jumpreducer = 0.3 / 250;
	this->maxfallspeed = siirtyma * 2.5;
}


void Character::setFalling(bool falling) {
	this->isFalling = falling;
	if (falling == false)
		fallspeedchecked = false;
}

void Character::FinishReset() {
	this->movespeed = 0;
}


void Character::checkmovement() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		moveLeft();
	}
	else
		movingleft = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		moveRight();
	}
	else
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
