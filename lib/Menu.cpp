#include "Menu.h"
#include "Painter.h"

Menu::Menu(std::vector<std::string> menu,int x,int y): menu(menu),x(x),y(y) 
{ 
	active_select = 0;
}

void Menu::increaseActiveSelect()
{
	if(active_select > 0) 
	{
		active_select -= 1;
	}
}

void Menu::decreaseActiveSelect()
{
	if(active_select < menu.size() - 1) 
	{
		active_select += 1;
	}
}

void Menu::print()
{
	for(int i = 0; i < menu.size(); i++)
	{
		if(i == active_select) 
		{
			Painter::drawString(menu[i],x,y + i,BLACK_FOREGROUND,WHITE_BACKGROUND); 
		}
		else
		{
			Painter::drawString(menu[i],x,y + i);
		}
	}
}

size_t Menu::getSize() 
{ 
	return menu.size();
}

std::string Menu::getActiveSelect()
{
	return menu[active_select];
}
