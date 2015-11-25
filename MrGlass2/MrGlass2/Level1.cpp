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
	lvl1.Draw(window);
	window.draw(glassman);
	glassman.checkmovement();

	// Pelinopeus FPS:stä riippumaton vakio
	float d = dClock.restart().asSeconds();
	float siirtyma = d * GAME_SPEED;
	glassman.SetMoveSpeed(siirtyma);

}