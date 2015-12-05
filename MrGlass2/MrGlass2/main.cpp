#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Level1.h"



// SFML 2.1 tutorial 51
int main() {
	



	bool playclicked = false;


	sf::RenderWindow window(sf::VideoMode(1024, 720), "MrGlass2");


	Menu menu(window.getSize().x, window.getSize().y);
	Level1 level1(window.getSize().x, window.getSize().y);

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
						std::cout << "Play button has been pressed" << std::endl;
						playclicked = true;

						break;
					case 1:
						std::cout << "Options button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
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
		else if (playclicked) {

			level1.draw(window);

		}

		window.display();
	}

}
