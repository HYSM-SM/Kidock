#include "Painter.h"
#include "Cursor.h"
#include <iostream>

void Painter::drawString(const std::string& str,int x,int y,int c_f,int c_b)
{
     Cursor::move(x,y);
     std::cout << "\x1b[" << c_f << ";" << c_b << "m" << str << "\x1b[" << CLEAR << "m";
     Cursor::move(0,0);
}

void Painter::drawString(const std::string& str,std::pair<int,int> coord,int c_f,int c_b)
{
    drawString(str,coord.first,coord.second,c_f,c_b);
}

void Painter::drawVector(const std::vector<std::string>& image,int x,int y,int c_f,int c_b)
{
    for(int i = 0; i < image.size(); i++)
    {
          Cursor::move(x,y + i);
          std::cout << "\x1b[" << c_f << ";" << c_b << "m" << image[i] << "\x1b[" << CLEAR << "m";
    }
    Cursor::move(0,0);
}

void Painter::drawVector(const std::vector<std::string>& image,std::pair<int,int> coord,int c_f,int c_b)
{
    drawVector(image,coord.first,coord.second,c_f,c_b);
}

void Painter::clearScreen()
{
    int screen_width = 190;
    int screen_height = 50;
    std::string clear(screen_width,' ');
    for(int i = 0; i < screen_height; i++)
    {
	    std::cout << clear;
	    Cursor::move(0,i);
    }
    Cursor::move(0,0);
}