#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Level1.h"
#include "Level2.h"



// SFML 2.1 tutorial 51
int main() {
	



	bool playclicked = false;
	bool level1finished = false;
	bool level2finished = false;


	sf::RenderWindow window(sf::VideoMode(1024, 720), "MrGlass2");


	Menu menu(window.getSize().x, window.getSize().y);
	Level1 level1(window.getSize().x, window.getSize().y);
	Level2 level2(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) kyseinen termi ei nykäise liikkuessa
		level1.MoveUp();*/
			while (window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::KeyPressed:
					switch (event.key.code) {

					case sf::Keyboard::Up:
						menu.MoveUp();
						break;

					case sf::Keyboard::Down:
						menu.MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (menu.GetPressedItem()) {
						case 0:
							if (!playclicked) {
								std::cout << "Play button has been pressed" << std::endl;
								playclicked = true;
							}
							break;
						case 1:
							if (!playclicked) {
								std::cout << "Options button has been pressed" << std::endl;
							}
							break;
						case 2:
							if (!playclicked) {
								window.close();
							}
							break;
						}

						break;
					}
					break;

				case sf::Event::Closed:
					window.close();
					break;
				}
			}

		
		window.clear();
	
		if (!playclicked) {
			menu.draw(window);
		}
		else if (playclicked && !level1finished) {

			level2.draw(window);
			level1finished = level1.checkstate();
			std::cout << level1finished << std::endl;
		
		}
		else if (playclicked && level1finished && !level2finished) {
			level2.draw(window);
			level2.checkstate();
		}

		window.display();
	}

}
