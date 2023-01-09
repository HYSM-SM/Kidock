#pragma once

#ifndef _ACTION_H_
#define _ACTION_H_

#include "./../Car/Car.h"
#include <vector>

class Action
{
	public:

	static void moveCars(std::vector<Car*> cars,void(Car::*goDirection)());
	static void moveCar(Car* car,void(Car::*goDirection)());
};

#endif
