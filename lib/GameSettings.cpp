#include "GameSettings.h"

void GameSettings::addSettings(const std::vector<std::pair<std::string,int>>& new_settings)
{
	for(int i = 0; i < new_settings.size(); i++)
	{
		settings.push_back(new_settings[i]);
	}
}

void GameSettings::addSettings(const std::pair<std::string,int>& new_setting)
{
	settings.push_back(new_setting);
}

int GameSettings::get(const std::string& name_settings)
{
	for(int i = 0; i < settings.size(); i++)
	{
		if(settings[i].first == name_settings)
		{
			return settings[i].second;
		}
	}
	return 0;
}

void GameSettings::reset()
{
	settings.clear();
}
