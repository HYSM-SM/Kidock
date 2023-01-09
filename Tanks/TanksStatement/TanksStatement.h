#pragma once

#ifndef _TANKSSTATEMENT_H_
#define _TANKSSTATEMENT_H_

#include "./../Tank/Tank.h"
#include <vector>
#include <string>
#include <utility>

class TanksStatement
{
	private:

	inline static bool player_defeated = false;

	public:

	static bool escapeFromMap(std::pair<int,int> coord);
	static bool tankDirectionCanBeChanged(Tank* tank);
	static bool projectileExist(Tank& tank);
	static bool enemyCannotMove(std::vector<Tank*>& enemies,int index,Tank& player);
	static bool playerCanMove(std::vector<Tank*>& enemies,Tank& player,std::string direction);
	static bool playerIsDefeated();
	static void setFlag(std::string name_flag,bool state_flag);
	static void resetFlags();
};

#endif
