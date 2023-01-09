#pragma once

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include <utility>
#include <string>

class Projectile
{
	private:

	std::pair<int,int> coord;
	std::string direction;
	char appearance;

	public:

	Projectile(std::pair<int,int> coord,std::string direction,char appearance = '*');
	void goAhead();
	char getImage() const;
	std::pair<int,int> getCoord() const;
};

#endif
