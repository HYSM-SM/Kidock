#pragma once

#ifndef _TRACKOWNER_H_
#define _TRACKOWNER_H_

#include "./../Car/Car.h"
#include "./../Car/Player.h"
#include "./../Car/Enemy.h"
#include <vector>

class TrackOwner
{
	public:
	
	static void removeCar(std::vector<Car*>& cars);
	static void addCar(std::vector<Car*>& cars);
	static Enemy* getEnemyCar();
	static Player* getPlayerCar();
	static void restartRace(Car* player,std::vector<Car*>& cars,bool& car_move_right);
};

#endif
