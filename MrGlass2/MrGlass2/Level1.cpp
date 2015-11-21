#include "Level1.h"
#include "character.h"

Level1::Level1(float width, float height) {

}

Level1::~Level1() {

}

void Level1::draw(sf::RenderWindow &window) {
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.draw(shape);	

	sf::Texture glassmantex;
	Character glassman("glassman.png", 500, 500, &glassmantex);
	window.draw(glassman);
}

void Level1::MoveUp() {
	
}

void Level1::MoveDown() {

}