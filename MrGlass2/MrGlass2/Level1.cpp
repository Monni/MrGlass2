#include "Level1.h"
#include "character.h"
#include <sstream>
#include <iostream>

using namespace std;


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
	glassman.setData("glassman.png", 300, 200, &glassmantex);
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
				bottom = i * 30 + 30;
				top = i * 30;
				right = j * 30 + 30;
				left = j * 30;

				if (glassman.right < left || glassman.left > right || glassman.top > bottom || glassman.bottom < top) {
					// tässä ei osu mihinkään palikkaan.
				}

				else {

					if (glassman.right > right) {
						//glassmanin vasen reuna osuu seinän oikeaan reunaan
						glassman.setPosition(200, 200);
						cout << "right collision" << glassman.left << endl << right;
					}
					else if (glassman.left < left) {
						cout << "left collision" << endl;
						//glassmanin oikea reuna osuu seinän vasempaan reunaan
						glassman.setPosition(300, 100);
					}
					else if (glassman.top > top) {
						cout << "top collision" << endl;
						// jalat osuu maahan
						glassman.setPosition(305, 500);
					}
					else if (glassman.bottom < bottom) {
						//pää osuu kattoon
						glassman.setPosition(105, 500);
						cout << "bottom collision" << endl;
						glassman.stopjump();
					}

					// liikkumisen esto hyvä toteuttaa booleaneilla

					else {

						break;
					}
				}
			}
		}
	}

}