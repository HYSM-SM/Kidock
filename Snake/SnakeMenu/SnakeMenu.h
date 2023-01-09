#pragma once

#ifndef _SNAKEMENU_H_
#define _SNAKEMENU_H_

#include "./../../lib/Menu.h"
#include "./../../lib/MainMenu.h"
#include <vector>
#include <string>

class SnakeMenu
{
	private:

	MainMenu* main_menu;
	Menu* menu;	
	std::vector<std::string> control;

	public:
	
	SnakeMenu();
	void run(bool& want_play);
};

#endif
