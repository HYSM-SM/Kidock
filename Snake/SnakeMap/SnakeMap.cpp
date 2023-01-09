#include "SnakeMap.h"

SnakeMap::SnakeMap(int width,int height):width(width),height(height)
{
	map = std::vector<std::string>(height - 2,std::string(width,' '));
	char wall = '|';
	for(int i = 0; i < map.size(); i++)
	{
		map[i].front() = wall;
		map[i].back() = wall;
	}
	std::string roof_floor = std::string(width,'-');
	map.insert(map.begin(),roof_floor);
	map.push_back(roof_floor);
}

std::vector<std::string> SnakeMap::getImage() const
{
	return map;
}
