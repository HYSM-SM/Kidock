#pragma once

#ifndef _MENU_H_
#define _MENU_H_

#include <vector>
#include <string>

class Menu
{
	private:

	std::vector<std::string> menu;
	int x,y;
	int active_select;

	public:

	Menu(std::vector<std::string> menu,int x,int y);
	void increaseActiveSelect();
	void decreaseActiveSelect();
	void print();
	size_t getSize();
	std::string getActiveSelect();
};

#endif
