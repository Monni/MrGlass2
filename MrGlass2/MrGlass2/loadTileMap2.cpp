#include "loadTileMap2.h"

LoadTileMap2::LoadTileMap2() {
	init();
}

void LoadTileMap2::init() {
	std::ifstream openfile("map2.txt");

	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		while (!openfile.eof())
		{
			std::string str;
			openfile >> str;
			char x = str[0], y = str[2]; //lukee 3 merkist‰ merkin 1 ja 3 jollois skippaa pilkun ja j‰tt‰‰ sen piirt‰m‰tt‰
			if (!isdigit(x) || !isdigit(y))
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			else
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');	// checkkaa onko numero, jos ei ole numero siirt‰‰ negatiiviseksi ykkˆseksi jottei mit‰‰n piirret‰.
			if (openfile.peek() == '\n') // rivin loputtua siirtyy toiselle
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
				loadCounter.x++;
		}
	}
}

LoadTileMap2::~LoadTileMap2() {}

void LoadTileMap2::Draw(sf::RenderWindow & window) {
	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1) // jos arvo annettu, etsii palikan tilemapista
			{
				tiles.setPosition(i * 30, j * 30); // asettaa piirtopaikan
				tiles.setTextureRect(sf::IntRect(map[i][j].x * 30, map[i][j].y * 30, 30, 30)); // etsii m‰‰r‰tyn palikan
				window.draw(tiles); // piirt‰‰ sarake kerrallaan ylh‰‰lt‰ alasp‰in
			}
		}
	}
}