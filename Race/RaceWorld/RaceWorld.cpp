#include "RaceWorld.h"
#include "./../../lib/GameSettings.h"
#include <utility>

std::vector<std::string> RaceWorld::getImage(RaceMap& map,std::vector<Car*> enemy,Car* player)
{
	std::vector<std::string> world = map.getImage();
	std::vector<std::pair<int,int>> coord_car;
	std::string image_car;
	std::vector<Car*> cars = enemy;
	cars.push_back(player);
	for(int i = 0; i < cars.size(); i++)
	{
		coord_car = cars[i]->getCoord();
		image_car = cars[i]->getImage();
		for(int j = 0; j < coord_car.size(); j++)
		{
			if(coord_car[j].first < 1 || coord_car[j].first >= world.front().size() - 1)
			{
				continue;
			}
			else if(coord_car[j].second < 0 || coord_car[j].second >= world.size())
			{
				continue;
			}
			world[coord_car[j].second][coord_car[j].first] = image_car[j];
		}
	}
	return world;
}

std::pair<int,int> RaceWorld::getCoord()
{
	int x = GameSettings::get("move_map_x");
	int y = GameSettings::get("moce_map_y");
	return { x,y };
}
