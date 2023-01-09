#pragma once

#ifndef _RACEWORLD_H_
#define _RACEWORLD_H_

#include "./../Car/Car.h"
#include "./../RaceMap/RaceMap.h"
#include <vector>
#include <string>

class RaceWorld 
{
    public:

    static std::vector<std::string> getImage(RaceMap& map,std::vector<Car*> enemy,Car* player);
    static std::pair<int,int> getCoord();
};

#endif
