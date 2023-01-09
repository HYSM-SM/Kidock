#include "PeacesNation.h"
#include "./../Projectile/Projectile.h"
#include "./../TanksStatement/TanksStatement.h"
#include "./../TanksScore/TanksScore.h"
#include "./../../lib/GameSettings.h"
#include <utility>

void PeacesNation::makeNewTank(std::vector<Tank*>& enemies,Tank& player)
{
	int amount_enemies = GameSettings::get("amount_enemies");
	if(enemies.size() > amount_enemies)
	{
		enemies.resize(amount_enemies);
		return;
	}
	enemies.push_back(&player);
	int begin_x = 2;
	int end_x = GameSettings::get("map_width") - enemies.front()->getWidth();
	int begin_y = 2;
	int end_y = GameSettings::get("map_height") - enemies.front()->getHeight();
	int x,y;
	Tank* new_tank = nullptr;
	while(new_tank == nullptr)
	{
		x = begin_x + rand() % (end_x - begin_x);
		y = begin_y + rand() % (end_y - begin_y);
		new_tank = new Tank(x,y,'x');
		new_tank->goRandDirection();
		for(auto tank: enemies)
		{
			if(*tank == *new_tank)
			{
				delete new_tank;
				new_tank = nullptr;
				break;
			}
		}
	}
	enemies.pop_back();
	enemies.push_back(new_tank);
}

void PeacesNation::makeNewTanks(std::vector<Tank*>& enemies,Tank& player,int amount)
{
	for(int i = 0; i < amount; i++)
	{
		makeNewTank(enemies,player);
	}
}

void PeacesNation::burnDefeatedEnemies(std::vector<Tank*>& enemies,Tank& player)
{
	enemies.push_back(&player);
	Projectile* projectile;
	std::vector<std::pair<int,int>> coord_projectiles;
	for(auto tank: enemies)
	{
		projectile = tank->getProjectile();
		if(projectile == nullptr) 
		{
			continue;
		}
		coord_projectiles.push_back(projectile->getCoord());
	}
	int index_player_tank = enemies.size() - 1;
	int index_player_projectile = coord_projectiles.size() - 1;
	for(int tank_index = 0; tank_index < enemies.size(); tank_index++)
	{
		for(int projectile_index = 0; projectile_index < coord_projectiles.size(); projectile_index++)
		{
			if(*enemies[tank_index] == coord_projectiles[projectile_index])
			{
				if(tank_index == index_player_tank)
				{
					TanksStatement::setFlag("player_defeated",true);
					return;
				}
				if(TanksStatement::projectileExist(player) &&  projectile_index == index_player_projectile)
				{
					TanksScore::increase();
				}
				enemies.erase(enemies.begin() + tank_index);
				break;
			}
		}
	}
	enemies.pop_back();
}

void PeacesNation::restartLiberationWar(std::vector<Tank*>& enemies,Tank& player)
{
	TanksStatement::resetFlags();
	player.resetData();
	TanksScore::reset();
	enemies.clear();
	makeNewTanks(enemies,player,GameSettings::get("amount_enemies"));
}
