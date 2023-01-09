#include "GameRecords.h"
#include <fstream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>

bool GameRecords::fileExist()
{
    std::fstream file(file_name);
    bool exist = file.is_open();
    file.close();
    return exist;
}

GameRecords::GameRecords(std::string file_name):file_name(file_name) 
{
    if(fileExist())
    {
        std::fstream read(file_name);
        std::string line;
        while(getline(read,line))
        {
            if(!line.empty())
	    {
                file_data.push_back(line);
	    }
        }
        read.close();
    }
}

void GameRecords::setData(std::vector<std::string> new_data)
{
    file_data = new_data;
}

void GameRecords::sortData(int(*convert)(std::string data))
{
    if(file_data.size() > 1)
    {
	    sort(begin(file_data),end(file_data),[convert](std::string f,std::string s) { return convert(f) > convert(s); } );
    }
}

void GameRecords::addData(std::string data)
{
    file_data.push_back(data);
}

void GameRecords::deleteDuplicate()
{
    if(file_data.size() > 1)
    {
	    std::vector<std::string>::iterator it = unique(begin(file_data),end(file_data));
	    file_data.erase(it,end(file_data));
    }
}

void GameRecords::rewrite(int total_line)
{
    std::fstream write(file_name,std::ios::out);
    std::string file;
    if(total_line == -1 || total_line > file_data.size())
    {
              total_line = file_data.size();
    }
    for(int i = 0; i < total_line; i++)
    {
              file += file_data[i] + "\n";
    }
    write << file;
    write.close();
}

std::vector<std::string> GameRecords::getWinnerTableData()
{
    if(file_data.empty()) 
    {
	    return {};
    }
    int length_last_winner = log10(file_data.size());
    int length_current_winner = 0;
    int amount_space_after_record = file_data.front().size();
    int amount_space_after_winner;
    std::stringstream line_winner;
    std::vector<std::string> winner_table;
    for(int i = 0,winner = 1; i < file_data.size();i++,winner++)
    {
            length_current_winner = log10(winner);
	    amount_space_after_winner = length_last_winner - length_current_winner;
            std::string space_after_winner(amount_space_after_winner,' ');
            line_winner << "[" << std::setw(amount_space_after_record) << std::left << file_data[i] << ']' << winner;
            line_winner << space_after_winner;
            winner_table.push_back(line_winner.str());
            line_winner.str("");
    }
    return winner_table;
}
