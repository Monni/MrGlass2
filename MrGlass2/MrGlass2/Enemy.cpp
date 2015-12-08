#include "enemy.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Enemy::Enemy() {}
Enemy::~Enemy() {}

void Enemy::update() {
	bottom = getPosition().y + getSize().y;
	left = getPosition().x + 3;
	right = getPosition().x + getSize().x - 3;
	top = getPosition().y + 13;
}

void Enemy::draw(sf::RenderWindow & window) {
	window.draw(*this);
	std::cout << "TULEE TÄNNE ENEMY DRAWIIN!";
}

/*void Enemy::move() {
	if (moveOrNot == 1) {
	if (movespeed > 0) {
	range++;
	setPosition(getPosition() + sf::Vector2f(movespeed, 0));
	if (range >= 1000) {
	movespeed = -0.1;
	range = 0;
	}
	}
	if (movespeed <= 0) {
	range++;
	setPosition(getPosition() + sf::Vector2f(movespeed, 0));
	if (range > 1000) {
	movespeed = 0.1;
	range = 0;
	}
	}
	}
}*/