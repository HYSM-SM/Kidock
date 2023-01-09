#pragma once

#ifndef _CAR_H_
#define _CAR_H_

#include <vector>
#include <string>
#include <utility>

class Car
{
    private:

    std::vector<std::pair<int,int>> coord_car;
    std::string image_car;
    int car_width;
    int car_height;

    void initializeImage(char image_driver);
    void initializeCoord(int x,int y);
    void move(int horizontal_move,int vertical_move);

    public:
	
    Car(int x,int y,char image_driver);
    void appearAt(int x,int y);
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    std::vector<std::pair<int,int>> getCoord() const;
    std::string getImage() const;
    int getHeight() const;
    int getWidth() const;
    bool operator==(Car& second_car);
};

#endif
