#include "Timer.h"
#include "./../../lib/GameSettings.h"
#include "./../../lib/GameRecords.h"
#include <unistd.h>

int Timer::getTimeInSeconds(std::string time)
{
	int sec  = stoi(time.substr(0,2));
	int min  = stoi(time.substr(3,2)) * 60;
	int hour = stoi(time.substr(6,2)) * 3600;
	return sec + min + hour;
}

std::string Timer::getImageTime()
{
	std::string time;
	if(seconds == -1)
	{
		time += "00";
	}
	else
	{
		time = (seconds > 9) ? std::to_string(seconds) : "0" + std::to_string(seconds);
	}
	time += ":";
	time += (minutes > 9) ? std::to_string(minutes) : "0" + std::to_string(minutes) ;
	time += ":";
	time += (hours > 9) ? std::to_string(hours) : "0" + std::to_string(hours);
	return time;
}

void Timer::run()
{
	int one_seconds = 1000000;
	player_play_game = true;
	while(player_play_game)
	{
		if(timer_running)
		{
			if(minutes > 59)
			{
				minutes = 0;
				hours++;
			}
			if(hours > 23)
			{
				hours = 0;
			}
			usleep(one_seconds);
			seconds++;
			if(seconds > 59)
			{
				seconds = 0;
				minutes++;
			}
		}
	}
}

void Timer::start()
{
	timer_running = true;
}

void Timer::stop()
{
	timer_running = false;
}

void Timer::writeRecord()
{
	GameRecords records(records_file);
	records.addData(getImageTime());
	records.sortData(&getTimeInSeconds);
	records.deleteDuplicate();
	records.rewrite(GameSettings::get("total_winners"));
}

void Timer::clear()
{
	seconds = -1;
	minutes = 0;
	hours   = 0;
}

std::vector<std::string> Timer::getImage()
{
	std::vector<std::string> timer = 
	{
		" ________ ",
		"|s  m  h |",
		">" + getImageTime() + "<",
		"|__/  \\__|"
	};
	return timer;
}

std::string Timer::getRecordsFileName()
{ 
	return records_file; 
}

int Timer::getSeconds()
{
       	return seconds; 
}

int Timer::getMinutes()
{ 
	return minutes; 
}

int Timer::getHours()
{ 
	return hours; 
}

void Timer::turnOff()
{
	player_play_game = false;
	timer_running = false;
	clear();
}
