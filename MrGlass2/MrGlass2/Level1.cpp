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
	M�r�t
	*/
}

void Level1::draw(sf::RenderWindow &window) {
	lvl1.Draw(window);
	window.draw(glassman);
	glassman.checkmovement();

	// Pelinopeus FPS:st� riippumaton vakio
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
					// t�ss� ei osu mihink��n palikkaan.
				}

				else {
					if (glassman.top < top) {
						cout << "top collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
							<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
							<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
							<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
						// jalat osuu maahan
						glassman.stopjump();
						glassman.setPosition(550, 550);
					}
					else if (glassman.bottom > bottom) {
						//p�� osuu kattoon

						glassman.setPosition(550, 350);
						cout << "bottom collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
							<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
							<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
							<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

					}
					if (glassman.right -15 > right+2) {
						//glassmanin vasen reuna osuu sein�n oikeaan reunaan

						glassman.setPosition(630, 450);
						cout << "right collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
							<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
							<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
							<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
					}
					else if (glassman.left +15 < left-2) {
						cout << "left collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
							<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
							<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
							<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
						//glassmanin oikea reuna osuu sein�n vasempaan reunaan
						glassman.setPosition(500, 450);
					}

					else {

						break;
					}
				}
			}
		}
	}

}