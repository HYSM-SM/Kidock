#pragma once

#ifndef _TANKSSCORE_H_
#define _TANKSSCORE_H_

#include <string>
#include <vector>
#include <utility>

class TanksScore
{
	private:

	inline static std::string filename = "tanks_records.txt";
	inline static int score = 0;

	public:

	static void writeRecord();
	static void increase();
	static std::vector<std::string> getImage();
	static std::string getRecordsFileName();
	static std::pair<int,int> getCoord();
	static std::string getScore();
	static void reset();
};

#endif
