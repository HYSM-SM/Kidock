#include "SpeedManager.h"
#include "./../Timer/Timer.h"
#include "./../../lib/GameSettings.h"

void SpeedManager::setSpeed(int speed)
{
        game_speed = speed;
}

void SpeedManager::increaseSpeed()
{
        int max_speed_per_one_game_cycle = -GameSettings::get("max_speed");
	int current_speed_per_one_game_cycle = -game_speed;
        if(current_speed_per_one_game_cycle >= max_speed_per_one_game_cycle)
	{
                return;
	}
	else if(Timer::getSeconds() % 10 == 0)
	{
                game_speed -= 500;
	}
}

int SpeedManager::getGameSpeed()
{
	return game_speed;
}

int SpeedManager::getCarSpeed()
{
	int min_speed_per_one_game_cycle = GameSettings::get("min_speed");
        return (min_speed_per_one_game_cycle - game_speed) / 1000;
}
