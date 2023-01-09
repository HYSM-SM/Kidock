#pragma once

#ifndef _AI_H_
#define _AI_H_

#include "./../Tank/Tank.h"
#include <vector>

class Ai
{
	private:

	inline static Tank* ai_player = nullptr;
	inline static std::vector<Tank*> ai_enemies = {};
	inline static bool enemies_can_move = true;
	inline static bool player_play_game = true;

	public:

	static void update(std::vector<Tank*>& enemies,Tank& player);
	static void moveEnemies();
	static void stopEnemiesMove();
	static void resumeEnemiesMove();
	static void turnOff();
};

#endif
