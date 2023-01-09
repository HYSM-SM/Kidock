#pragma once

#ifndef _TIMER_H_
#define _TIMER_H_

#include <string>
#include <vector>

class Timer
{
	private:

	inline static std::string records_file = "race_records.txt";
	inline static size_t seconds = -1,minutes = 0,hours = 0;
	inline static bool timer_running = false;
	inline static bool player_play_game = true;

	static int getTimeInSeconds(std::string time);
	static std::string getImageTime();

	public:
	
	static void run();
	static void start();
	static void stop();
	static void writeRecord();
	static void clear();
	static std::vector<std::string> getImage();
	static std::string getRecordsFileName();
	static int getSeconds();
	static int getMinutes();
	static int getHours();
	static void turnOff();
};

#endif
