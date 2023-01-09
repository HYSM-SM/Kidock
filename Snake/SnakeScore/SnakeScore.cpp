#include "SnakeScore.h"
#include "./../../lib/GameSettings.h"
#include "./../../lib/GameRecords.h"

void SnakeScore::increaseBy(int fruit_score)
{
	score = std::to_string(stoi(score) + fruit_score);
}

void SnakeScore::writeRecord()
{
	GameRecords records(filename_records);
	records.addData(score);
	records.sortData([](std::string data) { return stoi(data); } );
	records.deleteDuplicate();
	records.rewrite(GameSettings::get("total_winners"));
}

std::vector<std::string> SnakeScore::getImage() 
{
       static std::vector<std::string> table_scores = 
       {
	       "---------------",
	       "|    Score    |",
	       "|~~~~~~~~~~~~~|",
	       "|             |",
	       "---------------"
       };
       if(need_clear_score_line)
       {
	       std::string clear_score(table_scores[3].size() - 2,' ');
	       table_scores[3].replace(1,table_scores[3].size() - 2,clear_score);
	       need_clear_score_line = false;
       }
       std::string current_score = score;
       int middle_line = table_scores[3].size() / 2;
       table_scores[3].replace(middle_line,current_score.size(),current_score);
       return table_scores;
}

std::string SnakeScore::getRecordsFileName()
{ 
	return filename_records;
}

std::pair<int,int> SnakeScore::getCoord()
{
	int x = GameSettings::get("map_width");
	x += GameSettings::get("move_map_x");
	int y = GameSettings::get("map_height");
	y += GameSettings::get("move_map_y");
	y /= 2;
	return {x,y};
}

void SnakeScore::reset()
{
	score = "0";
	need_clear_score_line = true;
}
