#include "Level1.h"
#include "character.h"


Level1::Level1(float width, float height) {
	init();
}

Level1::~Level1() {

}

void Level1::loadCollisionMap() {
	std::ifstream openfile("colmap1.txt");
	std::vector<int>tempMap;
	colMap.clear();
	if (openfile.is_open())
	{

		while (!openfile.eof())
		{
			std::string str, value;
			std::getline(openfile, str);
			std::stringstream stream(str);

			while (std::getline(stream, value, ' ')) {
				if (value.length() > 0) {
					int a = atoi(value.c_str());
					tempMap.push_back(a);
				}
			}
			colMap.push_back(tempMap);
			tempMap.clear();
		}
	}
}


void Level1::init() {
	glassman.setData("glassman.png", 300, 300, &glassmantex);
	loadCollisionMap();
	//colMap.init();
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
					// tässä ei osu mihinkään palikkaan.
				}
				else {
					// liikkumisen esto hyvä toteuttaa booleaneilla
					init();
					break;
				}
			}
		}
	}

}