#include "SnakeMenu.h"
#include "./../SnakeScore/SnakeScore.h"

SnakeMenu::SnakeMenu()
{
	control.push_back("Moved:        WASD  ");
	control.push_back("Pause-Resume: Escape");
	menu = new Menu({"Start","Records","Control","Exit"},0,0);
	std::string score_file = SnakeScore::getRecordsFileName();
	main_menu = new MainMenu(menu,score_file,control);
}

void SnakeMenu::run(bool& want_play)
{
	main_menu->run(want_play);
}
