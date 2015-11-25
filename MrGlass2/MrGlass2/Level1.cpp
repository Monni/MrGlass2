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

	glassman.Update();

	for (int i = 0; i < colMap.size(); i++) {
		for (int j = 0; j < colMap[i].size(); j++) {
			if (colMap[i][j] == 1) {
				int bottom, top, left, right;
				bottom = i * 32 + 32;
				top = i * 32;
				right = j * 32 + 32;
				left = j * 32;

				if (glassman.right < left || glassman.left > right || glassman.top > bottom || glassman.bottom < top) {
					glassman.setPosition(300, 400);
				}
				else {
					break;
				}
			}
		}
	}

}