#include "Car.h"
#include "./../../lib/GameSettings.h"

void Car::initializeImage(char image_driver)
{
	image_car = "|~~?~~|/\\";
        image_car[3] = image_driver;
}

void Car::initializeCoord(int x,int y)
{
	coord_car.push_back( {x,y} );
        coord_car.push_back( {x - 2,y + 1} );
        coord_car.push_back( {x - 1,y + 1} );
        coord_car.push_back( {x,y + 1} );
        coord_car.push_back( {x + 1,y + 1} );
        coord_car.push_back( {x + 2,y + 1} );
        coord_car.push_back( {x,y + 2} );
        coord_car.push_back( {x - 1,y + 3} );
        coord_car.push_back( {x + 1,y + 3} );
}

void Car::move(int horizontal_move,int vertical_move)
{
	for(int i = 0; i < coord_car.size(); i++)
	{
		coord_car[i].first += horizontal_move;
		coord_car[i].second += vertical_move;
	}
}

Car::Car(int x,int y,char image_driver)
{
      initializeCoord(x,y);
      initializeImage(image_driver);
      car_width = 4;
      car_height = 3;
}

void Car::appearAt(int x,int y)
{
	coord_car.clear();
	initializeCoord(x,y);
}

void Car::goUp()
{
	move(0,-1);
}

void Car::goDown()
{
	move(0,1);
}

void Car::goLeft()
{
	int x = 3;
	int y = coord_car[0].second;
	appearAt(x,y);
}

void Car::goRight()
{
	int x = GameSettings::get("map_width") - car_width;
	int y = coord_car[0].second;
	appearAt(x,y);
}

std::vector<std::pair<int,int>> Car::getCoord() const
{
	return coord_car;
}

std::string Car::getImage() const
{
	return image_car;
}

int Car::getHeight() const
{
	return car_height;
}

int Car::getWidth() const
{
	return car_width;
}

bool Car::operator==(Car& second_car)
{
	std::vector<std::pair<int,int>> coord_second_car = second_car.getCoord();
	for(int i = 0; i < coord_car.size(); i++)
	{
		for(int j = 0; j < coord_second_car.size(); j++)
		{
			if(coord_car[i] == coord_second_car[j])
			{
				return true;
			}
		}
	}
	return false;
}
