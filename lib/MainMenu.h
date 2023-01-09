#pragma once

#ifndef _MAINMENU_H_
#define _MAINMENU_H_

#include <string>
#include "Menu.h"

class MainMenu
{
	private:

	Menu* menu;
	std::string active_select;
	std::string file_score;
	std::vector<std::string> control;

	public:

	MainMenu(Menu* menu,std::string& file_score,std::vector<std::string>& control);
	std::string run(bool& want_play);
};

#endif
