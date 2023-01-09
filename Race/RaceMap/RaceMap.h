#pragma once

#ifndef _RACEMAP_H_
#define _RACEMAP_H_

#include <vector>
#include <string>

class RaceMap
{
    private:
    
    int width,height;
    std::vector<std::string> image_map;
    bool need_animation;
    
    void animate();

    public:

    RaceMap(int width,int height,bool animation = true);
    std::vector<std::string> getImage();
};

#endif
