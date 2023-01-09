#include "Cursor.h"
#include <iostream>

void Cursor::move(int x,int y) 
{ 
	std::cout << "\033[" << y + 1 << ";" << x + 1 << "H"; 
}

void Cursor::hide() 
{ 
	system("tput civis");
}

void Cursor::show() 
{ 
	system("tput cnorm");
}
