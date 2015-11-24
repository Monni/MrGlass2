#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Character : public sf::RectangleShape {
public:
	float x;
	float y;
	int score;
	Character();
	~Character();
	Character(std::string, float, float, sf::Texture *);  // Luo hahmo
	void draw(sf::RenderWindow &window);
	void setData(std::string, float, float, sf::Texture *);
	void moveLeft();
	void moveRight();
	void jump();

protected:
private:
	float movespeed = 4;
	float jumpstart = 5;
	float jumpmax = 5;

};