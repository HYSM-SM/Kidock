#include "GameInfo.h"
#include "Cursor.h"
#include <iostream>

GameInfo::GameInfo(std::vector<std::vector<std::string>> info,int x,int y): info(info),x(x),y(y) 
{}

void GameInfo::draw()
{
   int current_y = 0;
   int size_perv_vector = 0;
    for(int i = 0; i < info.size(); i++)
    {
	    for(int j = 0; j < info[i].size(); j++)
	    {
		    current_y = y + j + size_perv_vector;
		    Cursor::move(x,current_y);
		    std::cout << info[i][j] << std::endl;
	    }
	    size_perv_vector += info[i].size();
    }
}

void GameInfo::change(const std::vector<std::vector<std::string>>& chg_info)
{
 	info = chg_info;
}
