#include "RaceStatement.h"
#include "./../../lib/GameSettings.h"

bool RaceStatement::topCarBelowThan(int y_coord,Car* car)
{
	if(car == nullptr) 
	{
		return false;
	}
	int top_car = car->getCoord().front().second;
	return top_car > y_coord; 
}

bool RaceStatement::canSpawnEnemyCar(Car* car)
{
	int line_spawn = (car->getHeight() + 1) * 2;
	return topCarBelowThan(line_spawn,car);
}

bool RaceStatement::lastEnemyCarBehindTheMap(Car* car)
{
	int map = GameSettings::get("map_height");
	return topCarBelowThan(map,car);
}

bool RaceStatement::isGameOver(std::vector<Car*> enemy,Car* player)
{
        std::vector<Car*> cars = enemy;
        for(int i = 0; i < cars.size(); i++)
        {
                if(*cars[i] == *player)
		{
                        return true;
		}
        }
        return false;
}
