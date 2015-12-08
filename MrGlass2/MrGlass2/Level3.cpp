#include "Level3.h"
#include "character.h"
#include <sstream>
#include <iostream>

using namespace std;


Level3::Level3(float width, float height) {
	init();
}

Level3::~Level3() {

}

void Level3::loadCollisionMap() {
	std::ifstream openfile("colmap3.txt");
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


void Level3::init() {
	glassman.setData("glassman.png", 40, 600, &glassmantex);
	loadCollisionMap();
	glassman.setFalling(false);
	goal.setGoalLocation("resources/goal.png", 950, 631, &goaltex);

	// objektit menee dynaamiseen muistitaulukkoon
	//	enemies.push_back(new Spike("resources/spike.png", 300, 600, &spiketex));
	//enemies.push_back(new Spike("resources/spike.png", 340, 600, &spiketex));
	//enemies.push_back(new Spike("resources/spike.png", 800, 600, &spiketex));
	//enemies.push_back(new Saw("resources/saw.png", 880, 600, &sawtex));
	enemies.push_back(new Saw("resources/saw.png", 850, 270, &sawtex));
	enemies.push_back(new Spike("resources/spike.png", 271, 121, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 350, 121, &spiketex));

	enemies.push_back(new Spike("resources/spike.png", 475, 210, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 536, 210, &spiketex));

	enemies.push_back(new Spike("resources/spike.png", 268, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 298, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 328, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 358, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 388, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 400, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 425, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 455, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 470, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 500, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 525, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 542, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 560, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 587, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 600, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 625, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 650, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 675, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 700, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 730, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 750, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 777, 691, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 800, 691, &spiketex));

}

bool Level3::checkstate() {
	return level3finished;
}

void Level3::draw(sf::RenderWindow &window) {
	lvl3.Draw(window);
	window.draw(glassman);
	window.draw(goal);
	// Goal collision
	goal.update();
	if (goal.right < glassman.left || goal.left > glassman.right || goal.top > glassman.bottom || goal.bottom < glassman.top) {
		// tässä ei osu mihinkään palikkaan.
	}
	else {
		level3finished = true;
	}

	//Piirto looppi vektorille
	for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++) {
		window.draw(*(*it));

	}
	//Collisionin tarkistus vihollisille
	for (int i = 0; i < enemies.size(); i++) {

		enemies[i]->update();
		if (enemies[i]->right < glassman.left || enemies[i]->left > glassman.right || enemies[i]->top > glassman.bottom || enemies[i]->bottom < glassman.top) {
			// tässä ei osu mihinkään palikkaan.
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


	// Pelinopeus FPS:stä riippumaton vakio
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
					// tässä ei osu mihinkään palikkaan.
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