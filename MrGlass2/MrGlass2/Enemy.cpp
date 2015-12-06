#include "enemy.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Enemy::Enemy() {}
Enemy::Enemy(std::string imagename, float x, float y, sf::Texture * tex) {}
Enemy::~Enemy() {}

void Enemy::update() {
	bottom = getPosition().y + getSize().y;
	left = getPosition().x + 3;
	right = getPosition().x + getSize().x - 3;
	top = getPosition().y + 13;
}

void Enemy::draw(sf::RenderWindow & window) {
	window.draw(*this);
}