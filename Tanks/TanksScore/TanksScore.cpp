#include "TanksScore.h"
#include "./../../lib/GameSettings.h"
#include "./../../lib/GameRecords.h"

void TanksScore::writeRecord()
{
	GameRecords records(filename);
	records.addData(getScore());
	records.sortData([](std::string data) { return stoi(data); } );
	records.deleteDuplicate();
	records.rewrite(GameSettings::get("total_winners"));
}

void TanksScore::increase() 
{ 
	score++;
}

std::vector<std::string> TanksScore::getImage()
{
	std::vector<std::string> table_scores = 
	{
		"~~~~~~~~~~~",
		"[  score  ]",
		"[         ]",
		"~~~~~~~~~~~"
	};
	std::string current_score = getScore();
	int middle_line = table_scores[2].size() / 2;
	table_scores[2].replace(middle_line,current_score.size(),current_score);
	return table_scores;
}

std::string TanksScore::getRecordsFileName()
{ 
	return filename;
}

std::pair<int,int> TanksScore::getCoord()
{
	int x = GameSettings::get("move_map_x");
	x += GameSettings::get("map_width") ;
	int y = GameSettings::get("move_map_y");
	y += GameSettings::get("map_height");
	y /= 4;
	return {x,y};
}

std::string TanksScore::getScore()
{
       	return std::to_string(score); 
}

void TanksScore::reset() 
{ 
	score = 0;
}
