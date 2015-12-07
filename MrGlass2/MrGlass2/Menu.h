#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3

class Menu {
public:
	Menu(float width, float height);						// Menun konstruktori
	~Menu();												// Destruktori

	void draw(sf::RenderWindow &window);					// Menu piirtopinnalle
	void MoveUp();											// Valitsijan liikutus yl�sp�in
	void MoveDown();										// Valitsijan liikutus alasp�in
	int GetPressedItem();									// Menun valitun napin v�rj�ys



private:
	int selectedItemIndex;									// Valitun menutoiminnon laskuri
	sf::Font font;											// Fonttiluokan olio
	sf::Text menu[MAX_NUMBER_OF_ITEMS];						// Text-luokan taulukko-olio
};