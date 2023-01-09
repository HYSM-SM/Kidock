#ifndef SINGLEPLAYER
#pragma once
#endif

#include "SnakeMap/SnakeMap.h"
#include "Snake/Snake.h"
#include "Fruits/Fruits.h"
#include "SnakeStatement/SnakeStatement.h"
#include "SnakeScore/SnakeScore.h"
#include "SnakeMenu/SnakeMenu.h"
#include "SnakeWorld/SnakeWorld.h"
#include "./../lib/Cursor.h"
#include "./../lib/GameSettings.h"
#include "./../lib/KeyBoard.h"
#include "./../lib/Painter.h"
#include <vector>
#include <string>
#include <thread>
#include <ctime>
#include <unistd.h>

namespace snake
{

void startGame()
{
	Cursor::hide();
	srand(time(NULL));
	GameSettings::addSettings({ 
			{"map_width",40},
			{"map_height",25},
			{"move_map_x",10},
			{"move_map_y",0},
			{"game_speed",50000},
			{"total_winners",10}});
	bool want_play = true;
	int map_width  = GameSettings::get("map_width");
	int map_height = GameSettings::get("map_height");
	int space_width  = GameSettings::get("move_map_x");
 	int space_y      = GameSettings::get("mvoe_map_y");
	int game_speed = GameSettings::get("game_speed");
	SnakeMap map(map_width,map_height);
	Snake snake;
	Fruits* fruit = SnakeWorld::getFruit();
	SnakeMenu menu;
	std::pair<int,int> score_coord = SnakeScore::getCoord();
	std::pair<int,int> world_coord = SnakeWorld::getCoord();
	std::pair<int,int> space_coord = { 0,space_y };
	std::vector<std::string> image_score;
	std::vector<std::string> image_world;
	std::vector<std::string> space_image_before_map(map_height,std::string(space_width,' '));
	std::string head_direction = "UP";
#ifdef SINGLEPLAYER
	std::thread keyboard_thread(Keyboard::run);
#endif
	menu.run(want_play);
	while(want_play)
	{
		if(SnakeStatement::snakeAteFruit(snake,fruit))
		{
			SnakeScore::increaseBy(fruit->getScore());
			delete fruit;
			fruit = SnakeWorld::getFruit();
			snake.growUp();
		}
		else if(SnakeStatement::snakeAteSnake(snake))
		{
			SnakeScore::writeRecord();
			SnakeWorld::restartGame(snake,fruit);
			menu.run(want_play);
			head_direction = "UP";
		}		
		if(Keyboard::pressedKeyIs(KEY_ESCAPE))
		{
			while(!Keyboard::pressedKeyIs(KEY_ESCAPE))
			{
				usleep(100);
			}
		}
		if(Keyboard::pressedKeysIs(KEY_W,KEY_w))
		{
			if(head_direction != "DOWN")
			{
				head_direction = "UP";
			}
		}
		else if(Keyboard::pressedKeysIs(KEY_S,KEY_s)) 
		{
			if(head_direction != "UP")
			{
				head_direction = "DOWN";
			}
		}
		else if(Keyboard::pressedKeysIs(KEY_A,KEY_a))
		{
			if(head_direction != "RIGHT")
			{
				head_direction = "LEFT";
			}
		}
		else if(Keyboard::pressedKeysIs(KEY_D,KEY_d)) 
		{
			if(head_direction != "LEFT")
			{
				head_direction = "RIGHT";
			}
		}
		snake.goDirection(head_direction);
		image_world = SnakeWorld::getImage(map,snake,fruit);
		image_score = SnakeScore::getImage();
		Painter::drawVector(space_image_before_map,space_coord);
		Painter::drawVector(image_world,world_coord,BLACK_FOREGROUND,DARK_GREEN_BACKGROUND);
		Painter::drawVector(image_score,score_coord,DARK_RED_FOREGROUND,BLACK_BACKGROUND);
		usleep(game_speed);
	}
#ifdef SINGLEPLAYER
	Painter::clearScreen();
	Keyboard::terminate();
	keyboard_thread.detach();
#endif
}

}// end namespace snake
#ifdef SINGLEPLAYER
int main()
{
	snake::startGame();
}
#endif

