
#include "loadTileMap.h"

LoadTileMap::LoadTileMap() {
	init();
}

void LoadTileMap::init() {
	std::ifstream openfile("map1.txt");

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
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y))
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);
			else
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');	// checkkaa onko numero, jos ei ole numero siirtää negatiiviseksi ykköseksi jottei mitään piirretä.
			if (openfile.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
				loadCounter.x++;
		}
	}
}

LoadTileMap::~LoadTileMap(){}

void LoadTileMap::Draw(sf::RenderWindow & window) {
	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1)
			{
				tiles.setPosition(i * 32, j * 32);
				tiles.setTextureRect(sf::IntRect(map[i][j].x * 32, map[i][j].y * 32, 32, 32));
				window.draw(tiles);
			}
		}
	}
}