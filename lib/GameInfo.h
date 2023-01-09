#pragma once

#ifndef _GAMEINFO_H_
#define _GAMEINFO_H_

#include <string>
#include <vector>

class GameInfo
{
    private:

    std::vector<std::vector<std::string>> info;
    int x,y;

    public:

    GameInfo(std::vector<std::vector<std::string>> info,int x,int y);
    void change(const std::vector<std::vector<std::string>>& chg_info);
    void draw();
};

#endif
