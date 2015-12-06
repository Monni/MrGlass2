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
	
	// objektit menee dynaamiseen muistitaulukkoon
	/*enemies.push_back(new Spike("resources/spike.png", 300, 600, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 340, 600, &spiketex));
	enemies.push_back(new Spike("resources/spike.png", 800, 600, &spiketex));
	*/

	//VEKTORIN TÄYTTEET
	Spike spike2;
	spike2.setEnemyData("resources/spike.png", 300, 600, &spiketex);
	enemies2.push_back(spike2);
	Spike spike3;
	spike3.setEnemyData("resources/spike.png", 340, 600, &spiketex);
	enemies2.push_back(spike3);
	Spike spike4;
	spike4.setEnemyData("resources/spike.png", 800, 600, &spiketex);
	enemies2.push_back(spike4);
	Saw saw;
	saw.setEnemyData("resources/saw.png", 880, 600, &sawtex);
	enemies2.push_back(saw);
}

void Level1::draw(sf::RenderWindow &window) {
	lvl1.Draw(window);
	window.draw(glassman);

	//TESTI VEKTORI ILMAN POINTTERIA JA DYNAAMISTA VARAUSTA, TOIMII!!//
	for (int i = 0; i < enemies2.size(); i++) {
		//vektorin piirto
		window.draw(enemies2[i]);
		//enemy sijaintien päivitys
		enemies2[i].update();
		if (enemies2[i].right < glassman.left || enemies2[i].left > glassman.right || enemies2[i].top > glassman.bottom || enemies2[i].bottom < glassman.top) {
			// tässä ei osu mihinkään palikkaan.
		}
		else {
			glassman.shatter();
			cout << "SPIKE OSUMA!";
		}
	}

	// objectien piirtäminen ei onnistu, ARSKA APUA

	/*for (std::vector<Enemy*>::iterator it = enemies.begin(); it != enemies.end(); it++){
	(*&*it)->draw(window);

	/*		for (unsigned int i = 0; i < enemies.size(); i++) {
	enemies.at(i).draw(window);
	}
	//	std::vector<Enemy *&> Tempenemies;
	//Pointteri Objektit löytyvät taulukosta
	for (int i = 0; i < enemies.size(); i++) {
	//window.draw(&enemies[i]);
	enemies[i]->draw(window);
	cout << &*enemies[i] << endl;
	//enemies*[i]->draw(&window);
	enemies[i]->update();
	if (enemies[i]->right < glassman.left || enemies[i]->left > glassman.right || enemies[i]->top > glassman.bottom || enemies[i]->bottom < glassman.top) {
	// tässä ei osu mihinkään palikkaan.
	}
	else {
	cout << "SPIKE OSUMA!?!??!?!";
	}

	}



	}*/

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
						if (glassman.top <= top) {
						/*	cout << "top collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
								<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
								<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
								<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
							// jalat osuu maahan*/
							glassman.stopjump();
							glassman.setFalling(false);

						}
						else if (glassman.bottom > bottom) {
							//pää osuu kattoon


							/*cout << "bottom collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
								<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
								<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
								<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
								*/
						}
						if (glassman.right - 15 > right + 2) {
							//glassmanin vasen reuna osuu seinän oikeaan reunaan


							/*cout << "right collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
								<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
								<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
								<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
						*/}
						else if (glassman.left + 15 < left - 2) {
						/*	cout << "left collision" << endl << "Glassman right = " << glassman.right << endl << "Right = " << right
								<< endl << "Glassman left = " << glassman.left << endl << "Left = " << left
								<< endl << "Glassman Bottom = " << glassman.bottom << endl << "Bottom = " << bottom
								<< endl << "Glassman Top = " << glassman.top << endl << "Top = " << top << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
							//glassmanin oikea reuna osuu seinän vasempaan reunaan*/

						}

						else {

							break;
						}


					
				}
			}
		}
	}

}