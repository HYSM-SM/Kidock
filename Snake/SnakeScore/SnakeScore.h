#pragma once

#ifndef _SNAKESCORE_H_
#define _SNAKESCORE_H_

#include <vector>
#include <string>
#include <utility>

class SnakeScore
{
	private:

	inline static std::string score = "0";
	inline static std::string filename_records = "snake_records.txt";
	inline static bool need_clear_score_line = false;

	public:
	
	static void increaseBy(int fruit_score);
	static void writeRecord();
	static std::vector<std::string> getImage();
	static std::string getRecordsFileName();
	static std::pair<int,int> getCoord();
	static void reset();
};

#endif
