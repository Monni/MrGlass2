#include "enemy.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Enemy::Enemy() {}

Enemy::~Enemy() {}

void Enemy::update() {

}


void Enemy::draw(sf::RenderWindow & window) {
	window.draw(*this);
}