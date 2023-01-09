#include "SnakeWorld.h"
#include "./../Fruits/Apple.h"
#include "./../Fruits/Banan.h"
#include "./../Fruits/Orange.h"
#include "./../SnakeScore/SnakeScore.h"
#include "./../../lib/GameSettings.h"

std::vector<std::string> SnakeWorld::getImage(SnakeMap& map,Snake snake,Fruits* fruit)
{
	std::vector<std::string> image_world = map.getImage();
	std::pair<int,int> fruit_coord = fruit->getCoord();
	image_world[fruit_coord.second][fruit_coord.first] = fruit->getImage();
	std::vector<std::pair<int,int>> snake_coord = snake.getCoord();
	std::vector<char> image_snake = snake.getImage();
	for(int i = 0; i < snake_coord.size(); i++)
	{
		image_world[snake_coord[i].second][snake_coord[i].first] = image_snake[i];
	}
	return image_world;
}

std::pair<int,int> SnakeWorld::getCoord()
{
	int x = GameSettings::get("move_map_x");
	int y = GameSettings::get("move_map_y");
	return {x,y};
}

Fruits* SnakeWorld::getFruit()
{
        int choice = rand() % 3;
        if(choice == 0)
	{
		return new Apple;
	}
        else if(choice == 1) 
	{
		return new Banan;
	}
        else if(choice == 2)
	{
		return new Orange;
	}
        return new Apple;
}

void SnakeWorld::restartGame(Snake& snake,Fruits* fruit)
{
        snake.resetData();
        fruit = getFruit();
        SnakeScore::reset();
}
