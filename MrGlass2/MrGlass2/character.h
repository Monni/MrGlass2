#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Character : public sf::RectangleShape {
public:
	int x;
	int y;
	int score;
	Character();
	~Character();
	Character(std::string, float, float, sf::Texture *);  // Luo hahmo
	void draw(sf::RenderWindow &window);
	void getNextPosition(); //kaikelle liikkeelle
	int getX();
protected:
private:
	int movespeed;
	int jumpstart;
	int jumpmax;

};