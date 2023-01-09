#pragma once

#ifndef _SNAKEMAP_H_
#define _SNAKEMAP_H_

#include <vector>
#include <string>

class SnakeMap
{
	private:

	std::vector<std::string> map;
	int width,height;

	public:

	SnakeMap(int width,int height);
	std::vector<std::string> getImage() const;
};

#endif
