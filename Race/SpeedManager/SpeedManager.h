#pragma once

#ifndef _SPEEDMANAGER_H_
#define _SPEEDMANAGER_H_

class SpeedManager
{
	private:

	inline static int game_speed = 0;

	public:

	static void setSpeed(int speed);
        static void increaseSpeed();
	static int getGameSpeed();
	static int getCarSpeed();
};

#endif
