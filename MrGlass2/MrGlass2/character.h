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

	void updateimg(sf::Texture *);
	void stopjump();
	void Update();
	void draw(sf::RenderWindow &window);
	void setData(std::string, float, float, sf::Texture *);
	void moveLeft();
	void moveRight();
	void jump();
	void checkmovement();
	void SetMoveSpeed(float);
	void setFalling(bool);

protected:
private:
	float movespeed;
	float jumpspeed;
	float fallspeed;
	float jumpreducer;
	float maxfallspeed;

	float jumpstart = 5;
	float jumpmax = 5;

	bool isJumping = false;
	bool isFalling = false;
	bool jumpspeedchecked = false;
	bool fallspeedchecked = false;

	bool lastleft = false;
	bool lastright = false;
	bool movingleft = false;
	bool movingright = false;

	sf::Image img;
	sf::Image runningleft;
	sf::Image runningright;
	sf::Image standingleft;
	sf::Image standingright;

};