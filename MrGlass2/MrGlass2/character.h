#pragma once
#include "SFML/Graphics.hpp"
#include "ImgException.cpp"
#include <string>

class Character : public sf::RectangleShape {
public:
	float x;													// Glassmanin x-koordinaatti
	float y;													// Glassmanin y-koordinaatti
	float bottom, left, right, top;								// Sijainnit collisionia varten
	int score;
	Character();												// Oletuskonstruktori
	~Character();												// Oletusdestruktori
	void setData(std::string, float, float, sf::Texture *);		// Konstruktori. Kuva, x ja y sijainti, tekstuurin lataus

	void updateimg(sf::Texture *);								// P�ivitt�� glassmanin texturen liikekomentojen muuttuessa
	void stopjump();											// Maahan osuessa muuttaa hypyn booleania mahdollistaakseen uuden hypp��misen
	void Update();												// Glassmanin sijainnin p�ivitys collisionia varten
	void moveLeft();											// Glassmanin liike vasemmalle + liikett� kuvaavien booleanien muutokset
	void moveRight();											// Glassmanin liike oikealle + liikett� kuvaavien booleanien muutokset
	void checkmovement();										// Tarkistetaan pelaajan n�pp�inpainallukset ja toimitaan sen mukaan. Tarkistaa my�s hypyn ja painovoiman tilan ja liikuttaa glassmania sen mukaan
	void SetMoveSpeed(float);									// Antaa glassmanin liikkeille pelinopeuden mukaisen nopeuden, FPS:sta riippumatta.
	void setFalling(bool);										// Kutsutaan hypyn loputtua lopettaakseen putoaminen ja aloittaakseen uusi putoamisnopeuslaskuri
	void shatter();												// Kutsutaan kun halutaan hajottaa glassman
	void notShattered();										// Palautetaan pelaajan "ehj�ksi"
	bool checkFalling();										// Tarkistetaan putoaako pelaaja, kent�n alal�pihyppy� varten
	void FinishReset();											// Pys�ytt�� pelaajan hetkeksi maalissa

protected:
private:
	// Liikkumisnopeudet
	float movespeed;
	float jumpspeed;
	float fallspeed;
	float jumpreducer;
	float maxfallspeed;

	// Hyppyyn ja painovoimaan tarvittavat booleanit
	bool isJumping = false;
	bool isFalling = false;
	bool jumpspeedchecked = false;
	bool fallspeedchecked = false;

	// Liikkeen booleanit kuvienp�ivityst� varten
	bool lastleft = false;
	bool lastright = false;
	bool movingleft = false;
	bool movingright = false;

	// Glassmanin hajoamista tukevat booleanit
	bool isCollisible = true;
	bool collided = false;

	// Glassmanin kuvat eri asennoissa
	sf::Image img;
	sf::Image runningleft;
	sf::Image runningright;
	sf::Image standingleft;
	sf::Image standingright;

};