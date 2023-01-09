#pragma once

#ifndef _TANKSMAP_H_
#define _TANKSMAP_H_

#include <string>
#include <vector>

class TanksMap
{
	private:

	std::vector<std::string> map;
	int width,height;

	public:

	TanksMap(int width,int height);
	std::vector<std::string> getImage() const; 
};

#endif
