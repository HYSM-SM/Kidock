#pragma once

#ifndef _RACEMENU_H_
#define _RACEMENU_H_

#include "./../../lib/Menu.h"
#include "./../../lib/MainMenu.h"
#include <vector>
#include <string>

class RaceMenu
{
	private:

	MainMenu* main_menu;
	Menu* menu;	
	std::vector<std::string> control;

	public:

	RaceMenu();
	void run(bool& want_play);
};

#endif
