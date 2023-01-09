#pragma once

#ifndef _GAMERECORDS_H_
#define _GAMERECORDS_H_

#include <string>
#include <vector>

class GameRecords
{
	private:

	std::vector<std::string> file_data;
	std::string file_name;

	bool fileExist();

	public:

	GameRecords(std::string file_name);
	void setData(std::vector<std::string> new_data);
	void sortData(int(*convert)(std::string data));
	void addData(std::string data);
	void deleteDuplicate();
	void rewrite(int total_line = -1);
	std::vector<std::string> getWinnerTableData();
};

#endif
