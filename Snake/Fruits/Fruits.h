#pragma once

#ifndef _FRUITS_H_
#define _FRUITS_H_

#include <utility>

class Fruits
{
	private:
	
	char image;
	int score;
	int x,y;

	void setCoord();
	
	public:
	
	Fruits(char image,int score);
	std::pair<int,int> getCoord() const;
	char getImage() const;
	int getScore() const;
};

#endif
