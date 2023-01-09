#pragma once

#ifndef _RACESTATEMENT_H_
#define _RACESTATEMENT_H_

#include "./../Car/Car.h"
#include <vector>

class RaceStatement
{
	private:

	static bool topCarBelowThan(int y_coord,Car* car);

	public:

	static bool canSpawnEnemyCar(Car* cars);
	static bool lastEnemyCarBehindTheMap(Car* cars);
	static bool isGameOver(std::vector<Car*> cars,Car* player);
};

#endif
