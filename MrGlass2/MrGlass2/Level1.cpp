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
	glassman.setData("glassman.png", 100, 200, &glassmantex);
	loadCollisionMap();
	
	goal.setGoalLocation("resources/goal.png", 960, 570, &goaltex);
	
	// objektit menee dynaamiseen muistitaulukkoon
	enemies.push_back(new Spike("resources/spike.png", 300, 600, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 340, 600, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 800, 600, &spiketex));
	enemies.push_back(new Saw("resources/saw.png", 880, 600, &sawtex));

}

void Level1::draw(sf::RenderWindow &window) {
	lvl1.Draw(window);
	window.draw(glassman);
	window.draw(goal);
	// Goal collision
	goal.update();
	if (goal.right < glassman.left || goal.left > glassman.right || goal.top > glassman.bottom || goal.bottom < glassman.top) {
		// t�ss� ei osu mihink��n palikkaan.
	}
	else {	cout << "GOAAAAAAAAAAAL!";}

	//Piirto looppi vektorille
	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++){
			window.draw(*(*it));
	
	}
	//Collisionin tarkistus vihollisille
	for (int i = 0; i < enemies.size(); i++) {

		enemies[i]->update();
		if (enemies[i]->right < glassman.left || enemies[i]->left > glassman.right || enemies[i]->top > glassman.bottom || enemies[i]->bottom < glassman.top) {
			// t�ss� ei osu mihink��n palikkaan.
		}
		else {
			glassman.shatter();
		}
	}

	glassman.checkmovement();
	try {
		glassman.updateimg(&glassmantex);
	}
	catch (ImgException ex) { cout << ex.getMessage() << endl; }
	
	
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
						glassman.setFalling(true);
						topcol = true;

					}

					else {
						if (glassman.top <= top && top) {
						/*	cout << "top collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
								<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
								<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
								<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
							// jalat osuu maahan*/
							glassman.stopjump();
							glassman.setFalling(false);
							topcol = false;

						}
						else if (glassman.bottom > bottom) {
							//p�� osuu kattoon


							/*cout << "bottom collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
								<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
								<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
								<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
								*/
						}
						if (topcol) {
							if (glassman.right > right) {
								//glassmanin vasen reuna osuu sein�n oikeaan reunaan
								std::cout << "righti";

								/*cout << "right collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
									<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
									<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
									<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	*/
							}
							else if (glassman.left < left) {
								std::cout << "lefti";
								/*	cout << "left collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
										<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
										<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
										<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
									//glassmanin oikea reuna osuu sein�n vasempaan reunaan*/

							}
						}
						else {

							break;
						}
					
				}
			}
		}
	}

}