#include "./../TanksStatement/TanksStatement.h"
#include "./../../lib/GameSettings.h"

bool TanksStatement::escapeFromMap(std::pair<int,int> coord)
{
	int begin_x = 1,begin_y = 1;
	int end_x = GameSettings::get("map_width") - 2;
	int end_y = GameSettings::get("map_height") - 2;
	int x = coord.first;
	int y = coord.second;
	if(x <= begin_x || x >= end_x)
	{
		return true;
	}
	else if(y <= begin_y || y >= end_y)
	{
		return true;
	}
	return false;
}

bool TanksStatement::tankDirectionCanBeChanged(Tank* tank)
{
	return escapeFromMap(tank->getCoordMuzzle());
}

bool TanksStatement::projectileExist(Tank& tank)
{
	return tank.getProjectile() != nullptr;
}
	
bool TanksStatement::enemyCannotMove(std::vector<Tank*>& enemies,int index,Tank& player)
{
	std::vector<Tank*> tanks = enemies;
	if(index < 0 || index > enemies.size()) 
	{
		return false;
	}
	tanks.push_back(&player);
	for(int i = 0; i < tanks.size(); i++)
	{
		if(i == index) 
		{
			continue;
		}
		if(*tanks[index] == *tanks[i])
		{
			tanks.pop_back();
			return true;
		}
	}
	tanks.pop_back();
	return false;
}

bool TanksStatement::playerCanMove(std::vector<Tank*>& enemies,Tank& player,std::string direction)
{
	Tank tank = player;
	if(direction == "REVERSE") 
	{
		tank.reverse();
	}
	else 
	{
		tank.goTo(direction);
	}
	for(int i = 0; i < enemies.size(); i++)
	{
		if(*enemies[i] == tank) 
		{
			return false;
		}
	}
	return true;
}

bool TanksStatement::playerIsDefeated()
{
	return player_defeated;
}

void TanksStatement::setFlag(std::string name_flag,bool state_flag)
{
	if(name_flag == "player_defeated")
	{
		player_defeated = state_flag;
	}
}

void TanksStatement::resetFlags()
{
 	player_defeated = false;
}	
