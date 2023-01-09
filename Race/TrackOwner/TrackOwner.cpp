#include "TrackOwner.h"
#include "./../../lib/GameSettings.h"

void TrackOwner::removeCar(std::vector<Car*>& cars)
{
	delete cars.back();
	cars.erase(cars.end() - 1,cars.end());
}

void TrackOwner::addCar(std::vector<Car*>& cars)
{
	 cars.insert(cars.begin(),getEnemyCar());
}

Enemy* TrackOwner::getEnemyCar()
{
        int side_track;
        side_track = rand() % 2;
	int behind_map = -4;
        Enemy* enemy = new Enemy(0,behind_map);
        (side_track) ? enemy->goLeft() : enemy->goRight();
        return enemy;
}

Player* TrackOwner::getPlayerCar()
{
        int y = GameSettings::get("map_height") / 2;
        Player* player = new Player(0,y);
	player->goRight();
	return player;
}

void TrackOwner::restartRace(Car* player,std::vector<Car*>& cars,bool& car_move_right)
{
        delete player;
        player = getPlayerCar();
        cars.clear();
        cars.push_back(getEnemyCar());
        car_move_right = false;
}
