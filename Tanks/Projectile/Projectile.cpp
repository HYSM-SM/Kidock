#include "Projectile.h"

Projectile::Projectile(std::pair<int,int> coord,std::string direction,char appearance): coord(coord),appearance(appearance),direction(direction) 
{}

void Projectile::goAhead()
{
	if(direction == "UP")
	{	
		coord.second--;
	}
	else if(direction == "DOWN")
	{
		coord.second++;
	}
	else if(direction == "RIGHT")
	{
		coord.first++;
	}
	else if(direction == "LEFT")
	{
		coord.first--;
	}
}

char Projectile::getImage() const 
{ 
	return appearance; 
}

std::pair<int,int> Projectile::getCoord() const
{ 
	return coord; 
}
