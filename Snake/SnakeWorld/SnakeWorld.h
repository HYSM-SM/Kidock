#pragma once

#ifndef _SNAKEWORLD_H_
#define _SNAKEWORLD_H_

#include "./../Snake/Snake.h"
#include "./../SnakeMap/SnakeMap.h"
#include "./../Fruits/Fruits.h"
#include <vector>
#include <string>
#include <utility>

class SnakeWorld
{
	public:

	static std::vector<std::string> getImage(SnakeMap& map,Snake snake,Fruits* fruit);
	static std::pair<int,int> getCoord();
	static Fruits* getFruit();
	static void restartGame(Snake& snake,Fruits* fruit);
};

#endif
