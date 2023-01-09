#ifndef SINGLEPLAYER
#pragma once
#endif
 
#include "TanksMap/TanksMap.h" 
#include "Tank/Tank.h" 
#include "TanksMenu/TanksMenu.h" 
#include "PeacesNation/PeacesNation.h" 
#include "Ai/Ai.h" 
#include "TanksScore/TanksScore.h" 
#include "TanksStatement/TanksStatement.h" 
#include "TanksWorld/TanksWorld.h" 
#include "./../lib/Painter.h" 
#include "./../lib/Cursor.h" 
#include "./../lib/KeyBoard.h" 
#include "./../lib/GameSettings.h" 
#include <vector>
#include <string>
#include <thread>
#include <ctime>
#include <unistd.h>

namespace tanks
{

void startGame()
{
	Cursor::hide();
	srand(time(NULL));
	GameSettings::addSettings({
				     {"map_width",30},
				     {"map_height",20},
				     {"move_map_x",5},
				     {"move_map_y",5},
				     {"speed_player",30000},
				     {"speed_enemy",1000000},
				     {"total_winners",10},
				     {"amount_enemies",4},
			             });
	bool want_play = true;
	int move_map_y = GameSettings::get("move_map_y");
	int move_map_x = GameSettings::get("move_map_x");
	int map_width  = GameSettings::get("map_width");
	int map_height = GameSettings::get("map_height");
	int amount_enemies = GameSettings::get("amount_enemies");
	int game_speed = GameSettings::get("speed_player");
	TanksMap map(map_width,map_height);
	Tank player(map_width / 2,map_height / 2,'-');
	TanksMenu menu;
	std::pair<int,int> score_coord = TanksScore::getCoord();
	std::pair<int,int> world_coord = TanksWorld::getCoord();
	std::pair<int,int> space_coord = { 0,move_map_y }; 
	std::vector<std::string> image_score;
	std::vector<std::string> image_world;
	std::vector<std::string> space_image_before_map(map_height,std::string(move_map_x,' '));
	std::vector<Tank*> enemy;
	PeacesNation::makeNewTanks(enemy,player,amount_enemies);
	std::thread ai_thread(Ai::moveEnemies);
#ifdef SINGLEPLAYER
	std::thread keyboard_thread(Keyboard::run);
#endif
	menu.run(want_play);
	while(want_play)
	{
		if(TanksStatement::playerIsDefeated())
		{
			TanksScore::writeRecord();
			PeacesNation::restartLiberationWar(enemy,player);
			menu.run(want_play);
		}
		if(enemy.size() != amount_enemies)
		{
			PeacesNation::makeNewTank(enemy,player);
		}
		if(Keyboard::pressedKeyIs(KEY_ESCAPE))
		{
			Ai::stopEnemiesMove();
			while(!Keyboard::pressedKeyIs(KEY_ESCAPE))
			{
				usleep(100);
			}
			Ai::resumeEnemiesMove();
		}
		else if(Keyboard::pressedKeyIs(KEY_SPACE))
		{
			player.fire();
		}
		else if(Keyboard::pressedKeysIs(KEY_D,KEY_d) && TanksStatement::playerCanMove(enemy,player,"RIGHT"))
		{
			player.goRight();
		}
		else if(Keyboard::pressedKeysIs(KEY_A,KEY_a) && TanksStatement::playerCanMove(enemy,player,"LEFT"))
		{
			player.goLeft();
		}
		else if(Keyboard::pressedKeysIs(KEY_W,KEY_w) && TanksStatement::playerCanMove(enemy,player,"UP"))
		{
			player.goUp();
		}
		else if(Keyboard::pressedKeysIs(KEY_S,KEY_s) && TanksStatement::playerCanMove(enemy,player,"DOWN"))
		{
			player.goDown();
		}
		else if(Keyboard::pressedKeysIs(KEY_R,KEY_r) && TanksStatement::playerCanMove(enemy,player,"REVERSE"))
		{
			player.reverse();
		}
		image_world = TanksWorld::getImage(map,enemy,player);
		image_score = TanksScore::getImage();
		Painter::drawVector(space_image_before_map,space_coord);
  		Painter::drawVector(image_world,world_coord,LIGHT_YELLOW_FOREGROUND,DARK_GREY_BACKGROUND);
		Painter::drawVector(image_score,score_coord,DARK_RED_FOREGROUND,BLACK_BACKGROUND);
		PeacesNation::burnDefeatedEnemies(enemy,player);
		TanksWorld::moveProjectile(enemy,player);
		Ai::update(enemy,player);
		usleep(game_speed);
	}
#ifdef SINGLEPLAYER
	Painter::clearScreen();
	Keyboard::terminate();
	keyboard_thread.detach();
#endif
	Ai::turnOff();
	ai_thread.join();
}
} // end namespace 

#ifdef SINGLEPLAYER
int main()
{
	tanks::startGame();
}
#endif
