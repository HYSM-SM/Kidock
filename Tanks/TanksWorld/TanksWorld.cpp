#include "TanksWorld.h"
#include "./../Projectile/Projectile.h"
#include "./../TanksStatement/TanksStatement.h"
#include "./../../lib/GameSettings.h"

void TanksWorld::moveProjectile(std::vector<Tank*>& enemies,Tank& player)
{
        enemies.push_back(&player);
        Projectile* projectile;
        for(auto tank: enemies)
        {
	        projectile = tank->getProjectile();
	        if(projectile != nullptr)
	        {
		        projectile->goAhead();
		        if(TanksStatement::escapeFromMap(projectile->getCoord()))
			{
			        tank->destroyProjectile();
			}
	        }
	}
	enemies.pop_back();
}

std::vector<std::string> TanksWorld::getImage(TanksMap& map,std::vector<Tank*>& enemies,Tank& player)
{
	std::vector<std::string> image_world = map.getImage();
	enemies.push_back(&player);
	std::pair<int,int> coord;
	Projectile* projectile  = nullptr;
	int x,y;
	for(auto tank: enemies)
	{
		for(auto coord: tank->getCoord())
		{
			x = coord.first;
			y = coord.second;
			image_world[y][x] = tank->getImage();
		}
		projectile = tank->getProjectile();
		if(projectile != nullptr)
		{
			coord = projectile->getCoord();
			x = coord.first;
			y = coord.second;
			image_world[y][x] = projectile->getImage();
		}
	}
	enemies.pop_back();
	return image_world;
}

std::pair<int,int> TanksWorld::getCoord()
{
	int y = GameSettings::get("move_map_y");
	int x = GameSettings::get("move_map_x");
	return { x,y };
}
