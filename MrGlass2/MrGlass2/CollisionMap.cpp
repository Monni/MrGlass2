
#include "CollisionMap.h"

CollisionMap::CollisionMap() {
	init();
}

void CollisionMap::init() {
	std::ifstream openfile("colmap1.txt");

	if (openfile.is_open())
	{

		while (!openfile.eof())
		{
			std::string str, value;
			std::getline(openfile, str);
			std::stringstream stream(str);

			while (std::getline(stream, value, ' ')) {
				if (value.length() > 0) {
					int a = atoi(value.c_str());
				}
			}
		}
	}
}

CollisionMap::~CollisionMap() {}

void CollisionMap::Draw(sf::RenderWindow & window) {

}