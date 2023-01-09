#include "TanksMap.h"

TanksMap::TanksMap(int width,int height): width(width),height(height)
{
	map.push_back(std::string(width,'-'));
	for(int i = 0; i < height - 2; i++)
	{
		map.push_back( "|" + std::string(width - 2,' ') + "|");
	}
	map.push_back(std::string(width,'-'));
}

std::vector<std::string> TanksMap::getImage() const
{ 
	return map;
}
