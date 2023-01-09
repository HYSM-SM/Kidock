#include "RaceMenu.h"
#include "./../Timer/Timer.h"
#include "./../SpeedManager/SpeedManager.h"
#include "./../../lib/GameSettings.h"

RaceMenu::RaceMenu()
{
        control.push_back("Pause-Resume: Escape ");
        control.push_back("Move car:     Any key");
        menu = new Menu({"Start","Mode max speed","Records","Control","Exit"},0,0);
        std::string score_file = Timer::getRecordsFileName();
        main_menu = new MainMenu(menu,score_file,control);
}

void RaceMenu::run(bool& want_play)
{
	std::string mode = main_menu->run(want_play);
	if(mode == "Start")
	{
		SpeedManager::setSpeed(GameSettings::get("min_speed"));
	}
	else if(mode == "Mode max speed")
	{
		SpeedManager::setSpeed(GameSettings::get("max_speed"));
	}
}
