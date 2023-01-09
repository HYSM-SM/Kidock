#include "MainMenu.h"
#include "KeyBoard.h"
#include "Painter.h"
#include "GameRecords.h"
#include "KeyBoard.h"
#include <vector>
#include <unistd.h>

MainMenu::MainMenu(Menu* menu,std::string& file_score,std::vector<std::string>& control)
{
	this->menu = menu;
	this->control = control;
	this->file_score = file_score;
}

std::string MainMenu::run(bool& want_play)
{
	Painter::clearScreen();
	menu->print();
	while(true)
	{
		usleep(1);
		if(Keyboard::pressedKeysIs(KEY_W,KEY_w))
		{
			menu->increaseActiveSelect();
			menu->print();
		}
		else if(Keyboard::pressedKeysIs(KEY_S,KEY_s))
		{
			menu->decreaseActiveSelect();
			menu->print();
		}
		else if(Keyboard::pressedKeyIs(KEY_ENTER))
		{
			active_select = menu->getActiveSelect();
			if(active_select == "Start")
			{
				want_play = true;
				Painter::clearScreen();
				return "Start";
			}
			else if(active_select == "Records")
			{
				GameRecords records(file_score);
				std::vector<std::string> file = records.getWinnerTableData();
				Painter::clearScreen();
				menu->print();
				Painter::drawVector(file,0,menu->getSize(),BLACK_FOREGROUND,WHITE_BACKGROUND);
			}
			else if(active_select == "Control")
			{
				Painter::clearScreen();
				menu->print();
				Painter::drawVector(control,0,menu->getSize(),BLACK_FOREGROUND,WHITE_BACKGROUND);
			}
			else if(active_select == "Exit")
			{
				want_play = false;
				Painter::clearScreen();
				return "Exit";
			}
			else
			{
				Painter::clearScreen();
				return active_select;
			}
		}
	}
}
