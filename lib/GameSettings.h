#pragma once

#ifndef _GAMESETTINGS_H_
#define _GAMESETTINGS_H_

#include <utility>
#include <vector>
#include <string>

class GameSettings
{
	private:

	inline static std::vector<std::pair<std::string,int>> settings;

	public:

	static void addSettings(const std::vector<std::pair<std::string,int>>& new_settings);
	static void addSettings(const std::pair<std::string,int>& new_setting);
	static int get(const std::string& name_settings);
	static void reset();
};

#endif
