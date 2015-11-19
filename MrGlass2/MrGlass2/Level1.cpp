#include "Level1.h"

Level1::Level1(float width, float height) {

}

Level1::~Level1() {

}

void Level1::draw(sf::RenderWindow &window) {
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);	
}

void Level1::MoveUp() {

}

void Level1::MoveDown() {

}