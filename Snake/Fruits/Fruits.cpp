#include "Fruits.h"
#include "./../../lib/GameSettings.h"

Fruits::Fruits(char image,int score):image(image),score(score)
{
	setCoord();
}

void Fruits::setCoord()
{
	x = 1 + rand() % (GameSettings::get("map_width") - 2);
	y = 1 + rand() % (GameSettings::get("map_height") - 2);
}

std::pair<int,int> Fruits::getCoord() const
{
	return {x,y};
}

char Fruits::getImage() const
{
	return image;
}

int Fruits::getScore() const
{
	return score;
}
