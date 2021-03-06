#include "Level2.h"
#include "character.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

Level2::Level2(float width, float height) {
	init();
}

Level2::~Level2() {}

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
	glassman.setData("glassman.png", 960, 618, &glassmantex);
	lvl2.setTileFile("map2.txt");
	lvl2.init();
	loadCollisionMap();
	glassman.setFalling(false);
	goal.setGoalLocation("resources/goal.png", 20, 35, &goaltex);

	// objektit menee dynaamisesti vektoriin
	enemies.push_back(new Saw("resources/saw.png", 790, 270, &sawtex));
	enemies.push_back(new Spike("resources/spike.png", 400, 60, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 748, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 778, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 808, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 838, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 862, 691, &spiketex));
}

void Level2::startScorecounter() {
	ifstream scorefile;
	scorefile.open("score.dat");
	if (scorefile.is_open()) {
		while (!scorefile.eof()) {
			scorefile >> this->currentscore;
		}
	}
	else cout << "Cannot open score.dat!" << endl;
	scorefile.close();
}

void Level2::stopScorecounter() {
	ofstream scorefile;
	scorefile.open("score.dat", ios::trunc);
	scorefile << this->currentscore;
	scorefile.close();
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
	if (scorewaiter <= 501)	scorewaiter++;

	//Level Reset
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
		glassman.notShattered();
		glassman.setPosition(960, 618);
		if (scorewaiter >= 500) {
			currentscore--;
			cout << currentscore << endl;
			scorewaiter = 0;
		}
	}

	if (goal.right < glassman.left || goal.left > glassman.right || goal.top > glassman.bottom || goal.bottom < glassman.top) {
		// t�ss� ei osu mihink��n palikkaan.
	}
	else {
		level2finished = true;
	}

	//Piirto looppi vektorille
	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
		window.draw(*(*it));

	}
	// sahojen liikuttaminen
	enemies[0]->move();
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
					if (glassman.top + 35 <= top && isFalling) {
						glassman.stopjump();
						glassman.setFalling(false);

					}

					else {

						break;
					}

				}
			}
		}
	}

}