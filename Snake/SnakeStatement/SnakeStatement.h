#pragma once

#ifndef _SNAKESTATEMENT_H_
#define _SNAKESTATEMENT_H_

#include "./../Snake/Snake.h"
#include "./../Fruits/Fruits.h"

class SnakeStatement
{
	public:

	static bool snakeAteFruit(Snake& snake,Fruits* fruit);
	static bool snakeAteSnake(Snake& snake);
};

#endif
