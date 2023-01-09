#include "RaceMap.h"

RaceMap::RaceMap(int width,int height,bool need_animation):width(width),height(height),need_animation(need_animation)
{
	image_map = std::vector<std::string>(height,std::string(width,' '));
	int middle_row = image_map.front().size() / 2;
	bool is_even_row;
	for(int i = 0; i < height; i++)
	{
		image_map[i].front() = '|';
		image_map[i].back()  = '|';
		is_even_row = (i % 2 == 0);
		if(is_even_row)
		{
			image_map[i][middle_row] = '|';
		}
	}
}

void RaceMap::animate()
{
	std::string row = image_map.front();
	image_map.erase(image_map.begin());
        image_map.push_back(row);
}

std::vector<std::string> RaceMap::getImage()
{
	if(need_animation)
	{
		animate();
	}
	return image_map;
}
