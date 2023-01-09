#pragma once

#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>
#include <utility>
#include <string>

class Snake
{
       private:

       std::vector<std::pair<int,int>> coord_snake;
       std::vector<char> image_snake;

       void moveHead(int& coord_head,int step);
       void moveBody(std::pair<int,int> old_coord);
       void move(int& coord_head,int step);
       void changeHeadImage(char head_image);
       void setCoord();

       public:

	Snake();
	void growUp();
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
	void goDirection(std::string direction);
	std::vector<std::pair<int,int>> getCoord() const;
	std::vector<char> getImage() const;
	void resetData();
};

#endif 
