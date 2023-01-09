#include "SnakeStatement.h"
#include <vector>
#include <utility>

bool SnakeStatement::snakeAteFruit(Snake& snake,Fruits* fruit)
{
	std::vector<std::pair<int,int>> coord_snake = snake.getCoord();
	std::pair<int,int> coord_fruit = fruit->getCoord();
	int fruit_x = coord_fruit.first;
	int fruit_y = coord_fruit.second;
	int snake_x,snake_y;
	for(int i = 0; i < coord_snake.size(); i++)
	{
		snake_x = coord_snake[i].first;
		snake_y = coord_snake[i].second;
		if(snake_x == fruit_x && snake_y == fruit_y)
		{
			return true;
		}
	}
	return false;
}

bool SnakeStatement::snakeAteSnake(Snake& snake)
{
	std::vector<std::pair<int,int>> coord_snake = snake.getCoord();
	int current_x,current_y;
	int verif_x,verif_y;
	for(int i = 0; i < coord_snake.size() - 1; i++)
	{
		verif_x = coord_snake[i].first;
		verif_y = coord_snake[i].second;
		for(int j = i + 1; j < coord_snake.size(); j++)
		{
			current_x = coord_snake[j].first;
			current_y = coord_snake[j].second;
			if(current_x == verif_x && current_y == verif_y)
			{
				return true;
			}
		}
	}
	return false;
}
