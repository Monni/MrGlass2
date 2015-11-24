#include "Level1.h"
#include "character.h"

Level1::Level1(float width, float height) {
	init();
}

Level1::~Level1() {

}

void Level1::init() {
	glassman.setData("glassman.png", 500, 300, &glassmantex);
	/*
	Level1 tilemap
	Musiikit?
	Möröt
	*/
}

void Level1::draw(sf::RenderWindow &window) {

	window.draw(glassman);

}

void Level1::MoveUp() {
	glassman.moveLeft(); // testi
}

void Level1::MoveDown() {
	glassman.moveRight(); //testi
}