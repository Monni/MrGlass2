#include "enemy.h"
#include <string>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

Enemy::Enemy() {}
Enemy::Enemy(std::string imagename, float x, float y, sf::Texture * tex) {}
Enemy::~Enemy() {}

void Enemy::update() {

}

void Enemy::draw(sf::RenderWindow & window) {
	window.draw(*this);
}