#include "Ai.h"
#include "./../TanksStatement/TanksStatement.h"
#include "./../../lib/GameSettings.h"
#include <string>
#include <unistd.h>

void Ai::update(std::vector<Tank*>& enemies,Tank& player)
{
	ai_enemies = enemies;
	ai_player = &player;
}

void Ai::moveEnemies()
{
	std::string muzzleDirection;
	player_play_game = true;
	enemies_can_move = true;
	int move_speed = GameSettings::get("speed_enemy");
	while(player_play_game)
	{
		usleep(move_speed);
		if(enemies_can_move)
		{
			for(int i = 0; i < ai_enemies.size(); i++)
			{
				muzzleDirection = ai_enemies[i]->getMuzzleDirection(); 
				ai_enemies[i]->goTo(muzzleDirection);
	 			if(rand() % 3)
				{
					ai_enemies[i]->fire();
				}
				if(TanksStatement::tankDirectionCanBeChanged(ai_enemies[i]))
				{
					ai_enemies[i]->goRandDirection();
				}
				else if(TanksStatement::enemyCannotMove(ai_enemies,i,*ai_player))
				{
					ai_enemies[i]->reverse();
					ai_enemies[i]->fire();
					ai_enemies[i]->goOppositeDirection();
					muzzleDirection = ai_enemies[i]->getMuzzleDirection();
					ai_enemies[i]->goTo(muzzleDirection);
				}
			}
		}
	}
	ai_enemies.clear();
	ai_player = nullptr;
	enemies_can_move = false;
}

void Ai::stopEnemiesMove() 
{ 
	enemies_can_move = false;
}

void Ai::resumeEnemiesMove() 
{ 
	enemies_can_move = true;
}

void Ai::turnOff()
{
	player_play_game = false;
}
