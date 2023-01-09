#pragma once

#ifndef _TANK_H_
#define _TANK_H_

#include "./../Projectile/Projectile.h"
#include <string>
#include <vector>
#include <utility>

class Tank
{
	private:

	Projectile* tank_projectile;
	std::vector<std::pair<int,int>> coord;
	std::string current_muzzle_direction;
	char appearance;
	int width,height;

	void rotateUp(std::string next_direction,std::vector<std::pair<int,int>>& new_coord);
	void rotateDown(std::string next_direction,std::vector<std::pair<int,int>>& new_coord);
	void rotateRight(std::string next_direction,std::vector<std::pair<int,int>>& new_coord);
	void rotateLeft(std::string next_direction,std::vector<std::pair<int,int>>& new_coord);
	void rotate(std::string next_direction);
	void move(std::string direction,int x,int y);
	std::vector<std::pair<int,int>> getInitializedTankCoord(int x,int y) const;
	
	public:

	Tank(int x,int y,char appearance = 'x',std::string direction = "UP");
	void goUp();
	void goDown();
	void goLeft();
	void goRight();
	void goTo(std::string direction);
	void goOppositeDirection();
	void goRandDirection();
	void reverse();
	void fire();
	std::vector<std::pair<int,int>> getCoord() const;
	std::pair<int,int> getCoordMuzzle() const;
	std::string getMuzzleDirection() const;
	Projectile* getProjectile() const;
	char getImage()  const;
	int  getWidth()  const;
	int  getHeight() const;
	friend bool operator==(const Tank& tank,std::pair<int,int> coord_object);
	friend bool operator==(const Tank& first_tank,const Tank& second_tank);
	void resetData();
	void destroyProjectile();
	~Tank();
};

#endif
