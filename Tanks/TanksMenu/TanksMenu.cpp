#include "TanksMenu.h"
#include "./../TanksScore/TanksScore.h"

TanksMenu::TanksMenu()
{
        control.push_back("Move:         WASD  ");
	control.push_back("Fire:         Space ");
	control.push_back("Reverse:      R     ");
        control.push_back("Pause-Resume: Escape");
        menu = new Menu({"Start","Records","Control","Exit"},0,0);
        std::string score_file = TanksScore::getRecordsFileName();
 	main_menu = new MainMenu(menu,score_file,control);
}

void TanksMenu::run(bool& want_play)
{
        main_menu->run(want_play);
}
