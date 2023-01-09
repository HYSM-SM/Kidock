#include "Snake.h"
#include "./../../lib/GameSettings.h"

void Snake::moveHead(int& coord_head,int step)
{
        coord_head += step;
}

void Snake::moveBody(std::pair<int,int> old_coord)
{
	if(coord_snake.size() == 1) 
	{
		return;
	}
	int new_x,new_y;
	int old_x = old_coord.first,old_y = old_coord.second;
	for(int i = 1; i < coord_snake.size(); i++)
	{
		new_x = coord_snake[i].first;
		new_y = coord_snake[i].second;
		coord_snake[i].first = old_x;
		coord_snake[i].second = old_y;
		old_x = new_x;
		old_y = new_y;
	}
}

void Snake::move(int& coord_head,int step)
{
	std::pair<int,int> old_coord = coord_snake.front();
	moveHead(coord_head,step);
	moveBody(old_coord);
}

void Snake::changeHeadImage(char head_image)
{
	image_snake.front() = head_image;
}

void Snake::setCoord()
{
	int begin_x = 1;
	int end_x = GameSettings::get("map_width") - 1;
	int x = begin_x + rand() % (end_x - begin_x);		
	int begin_y = 1;
	int end_y = GameSettings::get("map_height") - 1;
	int y = begin_y + rand() % (end_y - begin_y);
	coord_snake.push_back({x,y});
}

Snake::Snake()
{
	setCoord();
	image_snake = {'0'};
}

void Snake::growUp()
{
	if(coord_snake.back().second + 1 >= GameSettings::get("map_height") + 1)
	{
		return;
	}
	image_snake.push_back('x');
	std::pair<int,int> new_coord = coord_snake.back();
	new_coord.second = new_coord.second + 1;
	coord_snake.push_back(new_coord);
}

void Snake::goUp()
{
	changeHeadImage('^');
	move(coord_snake.front().second, -1);
	if(coord_snake.front().second < 1) 
	{
		coord_snake.front().second = GameSettings::get("map_height") - 2; 
	}
}

void Snake::goDown()
{
	changeHeadImage('v');
	move(coord_snake.front().second, 1);
	if(coord_snake.front().second > GameSettings::get("map_height") - 2)
	{
		coord_snake.front().second = 1;
	}
}

void Snake::goLeft()
{
	changeHeadImage('<');
	move(coord_snake.front().first, -1);
	if(coord_snake.front().first < 1)
	{
		coord_snake.front().first = GameSettings::get("map_width") - 2;
	}
}

void Snake::goRight()
{
	changeHeadImage('>');
	move(coord_snake.front().first, 1);
	if(coord_snake.front().first > GameSettings::get("map_width") - 2)
	{
		coord_snake.front().first = 1;
	}
}

void Snake::goDirection(std::string direction)
{
	if(direction == "UP")
	{
		goUp();
	}
	else if(direction == "DOWN")
	{
		goDown();
	}
	else if(direction == "LEFT")
	{
		goLeft();
	}
	else if(direction == "RIGHT")
	{
		goRight();
	}
}

std::vector<std::pair<int,int>> Snake::getCoord() const
{ 
	return coord_snake; 
}

std::vector<char> Snake::getImage() const 
{ 
	return image_snake; 
} 

void Snake::resetData()
{
	image_snake.clear();
	coord_snake.clear();
	image_snake.push_back('0');
	setCoord();
}
