#pragma once

#ifndef _TANKSMENU_H_
#define _TANKSMENU_H_

#include "./../../lib/Menu.h"
#include "./../../lib/MainMenu.h"
#include <vector>
#include <string>

class TanksMenu
{
        private:

	MainMenu* main_menu;
	Menu* menu;
	std::vector<std::string> control;

	public:

	TanksMenu();
	void run(bool& want_play);
};

#endif
