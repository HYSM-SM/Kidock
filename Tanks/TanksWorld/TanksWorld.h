#pragma once

#ifndef _TANKSWORLD_H_
#define _TANKSWORLD_H_

#include "./../Tank/Tank.h"
#include "./../TanksMap/TanksMap.h"
#include <utility>
#include <vector>
#include <string>

class TanksWorld
{
	public:

	static void moveProjectile(std::vector<Tank*>& enemies,Tank& player);
	static std::vector<std::string> getImage(TanksMap& map,std::vector<Tank*>& enemies,Tank& player);
	static std::pair<int,int> getCoord();
};

#endif
