#pragma once

#ifndef _PAINTER_H_
#define _PAINTER_H_

#include <string>
#include <vector>
#include <utility>

#define CLEAR 0
#define BLACK_FOREGROUND 30
#define DARK_RED_FOREGROUND 31
#define DARK_GREEN_FOREGROUND 32
#define DARK_YELLOW_FOREGROUND 33
#define DARK_NAVY_BLUE_FOREGROUND 34
#define DARK_PURPLE_FOREGROUND 35
#define DARK_BLUE_FOREGROUND 36
#define LIGHT_GREY_FOREGROUND 37
#define DARK_GREY_FOREGROUND 90
#define RED_FOREGROUND 91
#define GREEN_FOREGROUND 92
#define LIGHT_YELLOW_FOREGROUND 93
#define NAVY_BLUE_FOREGROUND 94
#define PURPLE_FOREGROUND 95
#define BLUE_FOREGROUND 96
#define WHITE_FOREGROUND 97
#define BLACK_BACKGROUND 40
#define DARK_RED_BACKGROUND 41
#define DARK_GREEN_BACKGROUND 42
#define DARK_YELLOW_BACKGROUND 43
#define DARK_NAVY_BLUE_BACKGROUND 44
#define DARK_PURPLE_BACKGROUND 45
#define DARK_BLUE_BACKGROUND 46
#define LIGHT_GREY_BACKGROUND 47
#define DARK_GREY_BACKGROUND 100
#define RED_BACKGROUND 101
#define GREEN_BACKGROUND 102
#define LIGHT_YELLOW_BACKGROUND 103
#define NAVY_BLUE_BACKGROUND 104
#define PURPLE_BACKGROUND 105
#define BLUE_BACKGROUND 106
#define WHITE_BACKGROUND 107

class Painter
{
    public:

    static void drawString(const std::string& str,int x,int y,int c_f = WHITE_FOREGROUND,int c_b = BLACK_BACKGROUND);
    static void drawString(const std::string& str,std::pair<int,int> coord,int c_f = WHITE_FOREGROUND,int c_b = BLACK_BACKGROUND);
    static void drawVector(const std::vector<std::string>& image,int x,int y,int c_f = WHITE_FOREGROUND,int c_b = BLACK_BACKGROUND);
    static void drawVector(const std::vector<std::string>& image,std::pair<int,int> coord,int c_f = WHITE_FOREGROUND,int c_b = BLACK_BACKGROUND);
    static void clearScreen();
};

#endif
