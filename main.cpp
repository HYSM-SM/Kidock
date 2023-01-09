#include "Race/main.cpp"
#include "Snake/main.cpp"
#include "Tanks/main.cpp"
#include "lib/Menu.h"
#include "lib/Painter.h"
#include "lib/KeyBoard.h"
#include "lib/GameSettings.h"
#include <iostream>
#include <vector>
#include <string>
#include <thread>

std::vector<std::string> image_race = 
{
	"|     |     |",
	"|  |        |",
	"|~~x~~|     |",
	"|  |        |",
	"| / \\ |     |",
	"|           |",
	"|     |     |",
	"|           |",
	"|     | |   |",
	"|     ~~+~~ |",
	"|     | |   |",
	"|      / \\  |"
};

std::vector<std::string> image_snake =
{
         "--------------------------------",
	 "|                              |",
	 "|                              |",
	 "|                              |",
	 "|                              |",
	 "|              xxxx            |",
	 "|              x  x            |",
	 "|              x  xxx>    @    |",
	 "|              x               |",
	 "|                              |",
	 "|                              |",
	 "--------------------------------"
};

std::vector<std::string> image_tanks = 
{
	"-----------------------",
	"|         xx          |",
	"|        xx           |",
	"|         xx          |",
	"|                     |",
	"|                     |",
	"|                     |",
	"|--          x        |",
	"| --  *     xxx       |",
	"|--         x x       |",
	"|                     |",
	"|                 x x |",
	"|                 xxx |",
	"|                  x  |",
	"|                     |",
	"-----------------------"
};

std::vector<std::string> image_exit = 
{       
	" ____             ____", 
	"|    |  \\     /  |    ",
	"|___/    \\   /   |____",
	"|   \\     \\ /    |    ",
	"|____|     |     |____"
};
 
void drawGameImage(std::string active_select,bool& print_image_game)
{
	std::vector<std::string> image;
	int color_foreground,color_background;
	if(active_select == "Race")
	{
		color_foreground = WHITE_FOREGROUND;
		color_background = DARK_RED_BACKGROUND;
		image = image_race;
	}
	else if(active_select == "Snake")
	{
		color_foreground = BLACK_FOREGROUND;
		color_background = DARK_GREEN_BACKGROUND;
		image = image_snake;
	}
	else if(active_select == "Tanks")
	{
		color_foreground = LIGHT_YELLOW_FOREGROUND;
		color_background = DARK_GREY_BACKGROUND;
		image = image_tanks;
	}
	else if(active_select == "Exit")
	{
		color_foreground = DARK_RED_FOREGROUND;
		color_background = BLACK_BACKGROUND;
		image = image_exit;
	}
	Painter::drawVector(image,7,0,color_foreground,color_background);
	print_image_game = false;
}

void startGame(std::string active_select,bool& wanna_play)
{
	if(active_select == "Race")
	{
		race::startGame();
	}
	else if(active_select == "Snake")
	{
		snake::startGame();
	}
	else if(active_select == "Tanks")
	{
		tanks::startGame();
	}
	else if(active_select == "Exit")
	{
		wanna_play = false;
	}
}

int main()
{
	Cursor::hide();
	system("clear");
	std::thread keyboard_thread(Keyboard::run);
	Menu menu({"Race","Snake","Tanks","Exit"},0,0);
	menu.print();
	std::string active_select = "";
	bool print_image_game = true,wanna_play = true;
	while(wanna_play)
	{
		usleep(1);
		active_select = menu.getActiveSelect();
		if(Keyboard::pressedKeysIs(KEY_S,KEY_s))
		{
			menu.decreaseActiveSelect();
			menu.print();
		}
		else if(Keyboard::pressedKeysIs(KEY_W,KEY_w))
		{
			menu.increaseActiveSelect();
			menu.print();
		}	
		if(print_image_game)
		{
			Painter::clearScreen();
			menu.print();
			drawGameImage(active_select,print_image_game);
		}
		if(active_select != menu.getActiveSelect())
		{
			print_image_game = true;
		}
		if(Keyboard::pressedKeyIs(KEY_ENTER))
		{
			startGame(active_select,wanna_play);
			GameSettings::reset();
			Painter::clearScreen();
			menu.print();
			drawGameImage(active_select,print_image_game);
		}
	}
	Painter::clearScreen();
	Keyboard::terminate();
	keyboard_thread.detach();
}
