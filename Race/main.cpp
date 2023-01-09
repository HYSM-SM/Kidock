#ifndef SINGLEPLAYER
#pragma once
#endif

#include "Timer/Timer.h"
#include "RaceMap/RaceMap.h"
#include "Car/Car.h"
#include "RaceMenu/RaceMenu.h"
#include "SpeedManager/SpeedManager.h"
#include "RaceStatement/RaceStatement.h"
#include "Action/Action.h"
#include "TrackOwner/TrackOwner.h"
#include "RaceWorld/RaceWorld.h"
#include "./../lib/KeyBoard.h"
#include "./../lib/Cursor.h"
#include "./../lib/GameSettings.h"
#include "./../lib/GameInfo.h"
#include "./../lib/Painter.h"
#include <vector>
#include <string>
#include <thread>
#include <unistd.h>

namespace race
{

void startGame()
{
    Cursor::hide();
    GameSettings::addSettings({
		    {"map_height",30}, 
		    {"map_width",13},
		    {"move_map_x",10},
		    {"move_map_y",2},
		    {"min_speed",100000},
		    {"max_speed",22000},
		    {"total_winners",10}});
    bool car_move_right = false;
    bool want_play = true;
    const int move_map_x = GameSettings::get("move_map_x");
    const int move_map_y = GameSettings::get("move_map_y");
    const int map_width  = GameSettings::get("map_width");
    const int map_height = GameSettings::get("map_height");
    const int info_x  = move_map_x + map_width ;
    const int info_y  = move_map_y + map_height / 4;
    RaceMap map(map_width,map_height);
    Car* player = TrackOwner::getPlayerCar();
    RaceMenu menu;
    std::pair<int,int> world_coord = RaceWorld::getCoord();
    std::pair<int,int> space_coord = { 0,move_map_y };
    std::vector<std::string> image_timer;
    std::vector<std::string> image_world;
    std::vector<std::string> space_image_before_map(map_height,std::string(move_map_x,' '));
    std::vector<std::string> image_speed;
    GameInfo info({},info_x,info_y);
    std::vector<Car*> enemy;
    enemy.push_back(TrackOwner::getEnemyCar());
    std::thread timer_thread(Timer::run);
#ifdef SINGLEPLAYER
    std::thread keyboard_thread(Keyboard::run);
#endif
    menu.run(want_play);
    Timer::start();
    while(want_play)
    {
	if(Keyboard::pressedKeyIs(KEY_ESCAPE))
	{
		Timer::stop();
		while(!Keyboard::pressedKeyIs(KEY_ESCAPE))
		{
		       	usleep(100);
		}
		Timer::start();
	}
	if(Keyboard::kbhit()) 
	{
		if(car_move_right)
		{
			Action::moveCar(player,&Car::goRight);
		}
		else
		{
			Action::moveCar(player,&Car::goLeft);
		}
		car_move_right = !car_move_right;
		Keyboard::clearKey();
	}
	Action::moveCars(enemy,&Car::goDown);
	SpeedManager::increaseSpeed();
	image_world = RaceWorld::getImage(map,enemy,player);
	image_timer = Timer::getImage();
	image_speed = { "Speed: " + std::to_string(SpeedManager::getCarSpeed()) + "  " };
	info.change( { image_timer,image_speed} );
	Painter::drawVector(image_world,world_coord,WHITE_FOREGROUND,DARK_RED_BACKGROUND);
	Painter::drawVector(space_image_before_map,space_coord);
	info.draw();
#ifndef GOD_MODE
       	if(RaceStatement::isGameOver(enemy,player)) 
	{
		Timer::stop();
		Timer::writeRecord();
		Timer::clear();
		TrackOwner::restartRace(player,enemy,car_move_right);
		menu.run(want_play);
		Timer::start();
	}
#endif
      	if(enemy.size() > 1 && RaceStatement::lastEnemyCarBehindTheMap(enemy.back()))
       	{
		TrackOwner::removeCar(enemy);
      	}
	else if(RaceStatement::canSpawnEnemyCar(enemy.front()))
      	{
		TrackOwner::addCar(enemy);
    	}
	usleep(SpeedManager::getGameSpeed());
    }
#ifdef SINGLEPLAYER
    Painter::clearScreen();
    Keyboard::terminate();
    keyboard_thread.detach();
#endif
    Timer::turnOff();
    timer_thread.join();
}

}// end namespace race

#ifdef SINGLEPLAYER
int main()
{
	race::startGame();
}
#endif
