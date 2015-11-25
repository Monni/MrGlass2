#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Character : public sf::RectangleShape {
public:
	float x;
	float y;
	float bottom, left, right, top;
	int score;
	Character();
	~Character();
	Character(std::string, float, float, sf::Texture *);  // Luo hahmo
	bool Collision(Character mrglass);

	void Update();
	void draw(sf::RenderWindow &window);
	void setData(std::string, float, float, sf::Texture *);
	void moveLeft();
	void moveRight();
	void jump();
	void checkmovement();
	void SetMoveSpeed(float);

protected:
private:
	float movespeed;
	float jumpstart = 5;
	float jumpmax = 5;

};