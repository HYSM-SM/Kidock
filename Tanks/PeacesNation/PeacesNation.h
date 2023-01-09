#pragma once

#ifndef PEACESNATION_H_
#define PEACESNATION_H_

#include "./../Tank/Tank.h"
#include <vector>

class PeacesNation
{
	public:

	static void makeNewTank(std::vector<Tank*>& enemies,Tank& player);
	static void makeNewTanks(std::vector<Tank*>& enemies,Tank& player,int amount);
	static void burnDefeatedEnemies(std::vector<Tank*>& enemies,Tank& player);
	static void restartLiberationWar(std::vector<Tank*>& enemies,Tank& player);
};

#endif
