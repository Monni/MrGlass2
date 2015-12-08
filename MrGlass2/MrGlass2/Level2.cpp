#include "Level2.h"
#include "character.h"
#include <sstream>
#include <iostream>

using namespace std;


Level2::Level2(float width, float height) {
	init();
}

Level2::~Level2() {

}

void Level2::loadCollisionMap() {
	std::ifstream openfile("colmap2.txt");
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


void Level2::init() {
	glassman.setData("glassman.png", 100, 10, &glassmantex);
	loadCollisionMap();

	goal.setGoalLocation("resources/goal.png", 960, 570, &goaltex);

	// objektit menee dynaamiseen muistitaulukkoon
//	enemies.push_back(new Spike("resources/spike.png", 300, 600, &spiketex));
	//enemies.push_back(new Spike("resources/spike.png", 340, 600, &spiketex));
	//enemies.push_back(new Spike("resources/spike.png", 800, 600, &spiketex));
	//enemies.push_back(new Saw("resources/saw.png", 880, 600, &sawtex));

}

bool Level2::checkstate() {
	return level2finished;
}

void Level2::draw(sf::RenderWindow &window) {
	lvl2.Draw(window);
	window.draw(glassman);
	window.draw(goal);
	// Goal collision
	goal.update();
	if (goal.right < glassman.left || goal.left > glassman.right || goal.top > glassman.bottom || goal.bottom < glassman.top) {
		// t�ss� ei osu mihink��n palikkaan.
	}
	else {
		cout << "GOAAAAAAAAAAAL!";
		level2finished = true;
	}

	//Piirto looppi vektorille
	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
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
	isFalling = glassman.checkFalling();


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
				

				}

				else {
					if (glassman.top <= top && isFalling) {
						/*	cout << "top collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
						<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
						<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
						<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
						// jalat osuu maahan*/
						glassman.stopjump();
						glassman.setFalling(false);
						std::cout << top << endl;
						cout << glassman.top << endl;
					

					}


					else {

						break;
					}

				}
			}
		}
	}

}