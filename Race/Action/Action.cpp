#include "Action.h"

void Action::moveCars(std::vector<Car*> cars,void(Car::*goDirection)())
{
	for(auto car : cars)
	{
		(car->*goDirection)();
	}
}

void Action::moveCar(Car* car,void(Car::*goDirection)())
{
	        (car->*goDirection)();
}
