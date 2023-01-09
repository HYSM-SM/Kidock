#include "./../Tank/Tank.h"
#include "./../../lib/GameSettings.h"

//for help see CoordsTanks.txt or CoordsTanks.png
void Tank::rotateUp(std::string next_direction,std::vector<std::pair<int,int>>& new_coord)
{
        if(next_direction == "RIGHT")
	{
		new_coord[0].first  = coord[0].first - 1;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[0].first;
		new_coord[1].second = coord[0].second;
		new_coord[2].first  = coord[2].first;
		new_coord[2].second = coord[2].second;
		new_coord[3].first  = coord[3].first;
		new_coord[3].second = coord[3].second;
		new_coord[4].first  = coord[4].first;
		new_coord[4].second = coord[4].second;
		new_coord[5].first  = coord[4].first + 1;
	   	new_coord[5].second = coord[4].second;
	}
	else if(next_direction == "LEFT")
	{
		new_coord[0].first  = coord[0].first;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[0].first + 1;
		new_coord[1].second = coord[0].second;
		new_coord[2].first  = coord[1].first;
		new_coord[2].second = coord[1].second;
		new_coord[3].first  = coord[2].first;
		new_coord[3].second = coord[2].second;
		new_coord[4].first  = coord[4].first + 1;
		new_coord[4].second = coord[4].second;
		new_coord[5].first  = coord[5].first;
		new_coord[5].second = coord[5].second;
	}
	else if(next_direction == "DOWN")
	{
		new_coord[0].first  = coord[0].first - 1;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[0].first + 1;
		new_coord[1].second = coord[0].second;
		new_coord[2].first  = coord[1].first;
		new_coord[2].second = coord[1].second;
		new_coord[3].first  = coord[2].first;
		new_coord[3].second = coord[2].second;
		new_coord[4].first  = coord[3].first;
		new_coord[4].second = coord[3].second;
		new_coord[5].first  = coord[4].first + 1;
		new_coord[5].second = coord[4].second;
	}
}

void Tank::rotateDown(std::string next_direction,std::vector<std::pair<int,int>>& new_coord)
{
	if(next_direction == "UP")
	{
		new_coord[0].first  = coord[0].first + 1;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[2].first;
		new_coord[1].second = coord[2].second;
		new_coord[2].first  = coord[3].first;
		new_coord[2].second = coord[3].second;
		new_coord[3].first  = coord[4].first;
		new_coord[3].second = coord[4].second;
		new_coord[4].first  = coord[5].first - 1;
		new_coord[4].second = coord[5].second;
		new_coord[5].first  = coord[5].first + 1;
		new_coord[5].second = coord[5].second;
	}
	else if(next_direction == "RIGHT")
	{
		new_coord[0].first  = coord[0].first;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[0].first + 1;
		new_coord[1].second = coord[0].second;
		new_coord[2].first  = coord[3].first;
		new_coord[2].second = coord[3].second;
		new_coord[3].first  = coord[4].first;
		new_coord[3].second = coord[4].second;
		new_coord[4].first  = coord[5].first - 1;
		new_coord[4].second = coord[5].second;
		new_coord[5].first  = coord[5].first;
		new_coord[5].second = coord[5].second;
	}
	else if(next_direction == "LEFT")
	{
		new_coord[0].first  = coord[0].first + 1;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[1].first;
		new_coord[1].second = coord[1].second;
		new_coord[2].first  = coord[2].first;
		new_coord[2].second = coord[2].second;
		new_coord[3].first  = coord[3].first;
		new_coord[3].second = coord[3].second;
		new_coord[4].first  = coord[5].first;
		new_coord[4].second = coord[5].second;
		new_coord[5].first  = coord[5].first + 1;
		new_coord[5].second = coord[5].second;
	}
}

void Tank::rotateRight(std::string next_direction,std::vector<std::pair<int,int>>& new_coord)
{
	if(next_direction == "UP")
	{
		new_coord[0].first  = coord[1].first;
		new_coord[0].second = coord[1].second;
		new_coord[1].first  = coord[2].first - 1;
		new_coord[1].second = coord[2].second;
		new_coord[2].first  = coord[2].first;
		new_coord[2].second = coord[2].second;
		new_coord[3].first  = coord[3].first;
		new_coord[3].second = coord[3].second;
		new_coord[4].first  = coord[4].first;
		new_coord[4].second = coord[4].second;
		new_coord[5].first  = coord[5].first + 1;
		new_coord[5].second = coord[5].second;
	}
	else if(next_direction == "DOWN")
	{
		new_coord[0].first  = coord[0].first;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[1].first + 1;
		new_coord[1].second = coord[1].second;
		new_coord[2].first  = coord[2].first - 1;
		new_coord[2].second = coord[2].second;
		new_coord[3].first  = coord[2].first;
		new_coord[3].second = coord[2].second;	
		new_coord[4].first  = coord[3].first;
		new_coord[4].second = coord[3].second;
		new_coord[5].first  = coord[5].first;
		new_coord[5].second = coord[5].second;
	}
	else if(next_direction == "LEFT")
	{
		new_coord[0].first  = coord[1].first;
		new_coord[0].second = coord[1].second;
		new_coord[1].first  = coord[1].first + 1;
		new_coord[1].second = coord[1].second;
		new_coord[2].first  = coord[2].first - 1;
		new_coord[2].second = coord[2].second;
		new_coord[3].first  = coord[2].first;
		new_coord[3].second = coord[2].second;
		new_coord[4].first  = coord[5].first;
		new_coord[4].second = coord[5].second;
		new_coord[5].first  = coord[5].first + 1;
		new_coord[5].second = coord[5].second;
	}
}

void Tank::rotateLeft(std::string next_direction,std::vector<std::pair<int,int>>& new_coord)
{
	if(next_direction == "UP")
	{
		new_coord[0].first  = coord[0].first;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[2].first;
		new_coord[1].second = coord[2].second;
		new_coord[2].first  = coord[3].first;
		new_coord[2].second = coord[3].second;
		new_coord[3].first  = coord[3].first + 1;
		new_coord[3].second = coord[3].second;
		new_coord[4].first  = coord[4].first - 1;
		new_coord[4].second = coord[4].second;
		new_coord[5].first  = coord[5].first;
		new_coord[5].second = coord[5].second;
	}
	else if(next_direction == "DOWN")
	{
		new_coord[0].first  = coord[0].first - 1;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[1].first;
		new_coord[1].second = coord[1].second;
		new_coord[2].first  = coord[2].first;
		new_coord[2].second = coord[2].second;
		new_coord[3].first  = coord[3].first;
		new_coord[3].second = coord[3].second;
		new_coord[4].first  = coord[3].first + 1;
		new_coord[4].second = coord[3].second;
		new_coord[5].first  = coord[4].first;
		new_coord[5].second = coord[4].second;
	}
	else if(next_direction == "RIGHT")
	{
		new_coord[0].first  = coord[0].first - 1;
		new_coord[0].second = coord[0].second;
		new_coord[1].first  = coord[0].first;
		new_coord[1].second = coord[0].second;
		new_coord[2].first  = coord[3].first;
		new_coord[2].second = coord[3].second;
		new_coord[3].first  = coord[3].first + 1;
		new_coord[3].second = coord[3].second;
		new_coord[4].first  = coord[4].first - 1;
		new_coord[4].second = coord[4].second;
		new_coord[5].first  = coord[4].first;
		new_coord[5].second = coord[4].second;
	}
}

void Tank::rotate(std::string next_direction)
{
	std::vector<std::pair<int,int>> new_coord(coord.size(),{0,0});
	if(current_muzzle_direction == "UP") 
	{
		rotateUp(next_direction,new_coord);
	}
	else if(current_muzzle_direction == "DOWN") 
	{
		rotateDown(next_direction,new_coord);
	}
	else if(current_muzzle_direction == "RIGHT") 
	{
		rotateRight(next_direction,new_coord);
	}
	else if(current_muzzle_direction == "LEFT") 
	{
		rotateLeft(next_direction,new_coord);
	}
	coord = new_coord;	
}

void Tank::move(std::string direction,int x,int y)
{
	if(current_muzzle_direction != direction)
	{
		rotate(direction);
		current_muzzle_direction = direction;
		return;
	}
	for(int i = 0; i < coord.size(); i++)
	{
		coord[i].first  += x;
		coord[i].second += y;
	}
	current_muzzle_direction = direction;
}

std::vector<std::pair<int,int>> Tank::getInitializedTankCoord(int x,int y) const
{
	std::vector<std::pair<int,int>> new_coord;
	new_coord.push_back({x + 1,y});
	new_coord.push_back({x,y + 1});
	new_coord.push_back({x + 1,y + 1});
	new_coord.push_back({x + 2,y + 1});
	new_coord.push_back({x,y + 2});
	new_coord.push_back({x + 2,y + 2});
	return new_coord;
}

Tank::Tank(int x,int y,char appearance,std::string direction): appearance(appearance)
{
	width  = 3;
	height = 3;
	tank_projectile = nullptr;
	coord = getInitializedTankCoord(x,y);
	current_muzzle_direction = "UP";
	if(direction != "UP")
	{
		rotate(direction);
	}
	current_muzzle_direction = direction;
}

void Tank::goUp()
{
	if(coord[0].second == 1) 
	{
		return; // end map
	}
	move("UP",0,-1);
}

void Tank::goDown()
{
	if(coord[5].second == GameSettings::get("map_height") - 2)
	{
		return; // end map
	}
	move("DOWN",0,1);
}

void Tank::goLeft()
{
	if(coord[2].first == 1) 
	{
		return; // end map
	}
	move("LEFT",-1,0);
}

void Tank::goRight()
{
	if(coord[3].first == GameSettings::get("map_width") - 2)
	{
		return; // end map
	}
	move("RIGHT",1,0);
}

void Tank::goTo(std::string direction)
{
	if(direction == "UP") 
	{
		goUp();
	}
	else if(direction == "DOWN") 
	{
		goDown();
	}
	else if(direction == "RIGHT") 
	{
		goRight();
	}
	else if(direction == "LEFT") 
	{
		goLeft();
	}
}

void Tank::goOppositeDirection()
{
	if(current_muzzle_direction == "UP") 
	{
		goDown();
	}
	else if(current_muzzle_direction == "DOWN") 
	{
		goUp();
	}
	else if(current_muzzle_direction == "RIGHT") 
	{
		goLeft();
	}
	else if(current_muzzle_direction == "LEFT") 
	{
		goRight();
	}
}

void Tank::goRandDirection()
{
	int direction = rand() % 4;
	if(direction == 0) 
	{
		goUp();
	}
	else if(direction == 1) 
	{
		goDown();
	}
	else if(direction == 2) 
	{
		goRight();
	}
	else if(direction == 3) 
	{
		goLeft();
	}
}

void Tank::reverse()
{
	int step;
	int map_width = GameSettings::get("map_width") - 2;
	int map_height = GameSettings::get("map_height") - 2;
	if(current_muzzle_direction == "UP" || current_muzzle_direction == "LEFT") 
	{
		step = 1;
	}
	else if(current_muzzle_direction == "DOWN" || current_muzzle_direction == "RIGHT") 
	{
		step = -1;
	}
	std::vector<std::pair<int,int>> new_coord = coord;
	for(int i = 0; i < coord.size(); i++)
	{
		if(current_muzzle_direction == "UP" || current_muzzle_direction == "DOWN")
		{
			new_coord[i].second += step;
		}
		else if(current_muzzle_direction == "RIGHT" || current_muzzle_direction == "LEFT")
		{
			new_coord[i].first += step;
		}
		if(coord[i].first == 1 && current_muzzle_direction == "RIGHT")
		{
			return;
		}
		else if(coord[i].second == 1 && current_muzzle_direction == "DOWN")
		{
			return;
		}
		else if(coord[i].first == map_width && current_muzzle_direction == "LEFT")
		{
			return;
		}
		else if(coord[i].second == map_height && current_muzzle_direction == "UP")
		{
			return;
		}
	}
	coord = new_coord;
}

void Tank::fire()
{
	if(tank_projectile != nullptr) 
	{
		return;
	}
	std::pair<int,int> coord_projectile;
	if(current_muzzle_direction == "UP")
	{
		coord_projectile = { coord[0].first,coord[0].second - 1 };
	}
	else if(current_muzzle_direction == "DOWN")
	{
		coord_projectile = { coord[5].first,coord[5].second + 1};
	}
	else if(current_muzzle_direction == "RIGHT")
	{
		coord_projectile = { coord[3].first + 1, coord[3].second};
	}
	else if(current_muzzle_direction == "LEFT")
	{
		coord_projectile = { coord[2].first - 1,coord[2].second };
	}
	tank_projectile = new Projectile(coord_projectile,current_muzzle_direction);
}

std::vector<std::pair<int,int>> Tank::getCoord() const
{ 
	return coord;
}

std::pair<int,int> Tank::getCoordMuzzle() const
{
	if(current_muzzle_direction == "UP") 
	{
		return coord[0];
	}
	else if(current_muzzle_direction == "DOWN") 
	{
		return coord[5];
	}
	else if(current_muzzle_direction == "RIGHT") 
	{
		return coord[3];
	}
	else if(current_muzzle_direction == "LEFT") 
	{
		return coord[2];
	}
	return {0,0};
}

std::string Tank::getMuzzleDirection() const
{
	return current_muzzle_direction;
}

Projectile* Tank::getProjectile() const
{ 
	return tank_projectile; 
}

char Tank::getImage() const
{	
	return appearance; 
}

int Tank::getWidth() const
{
	return width;
}

int Tank::getHeight() const
{
	return height;
}

bool operator==(const Tank& tank,std::pair<int,int> coord_object)
{
	std::vector<std::pair<int,int>> coords = tank.getCoord();
	for(auto tank_coord: coords)
	{
		if(coord_object == tank_coord) 
		{
			return true;
		}
	}
	return false;
}

bool operator==(const Tank& first_tank,const Tank& second_tank)
{
	std::vector<std::pair<int,int>> first_coord = first_tank.getCoord();
	std::vector<std::pair<int,int>> second_coord = second_tank.getCoord();
	for(auto coord_first_tank: first_coord)
	{
		for(auto coord_second_tank: second_coord)
		{
			if(coord_first_tank == coord_second_tank) 
			{
				return true;
			}
		}
	}
	return false;
}

void Tank::resetData()
{
	int x = GameSettings::get("map_width") / 2;
	int y = GameSettings::get("map_height") / 2;
	coord = getInitializedTankCoord(x,y);
	current_muzzle_direction = "UP";
	destroyProjectile();
}


void Tank::destroyProjectile()
{
	if(tank_projectile != nullptr)
	{
		delete tank_projectile;
		tank_projectile = nullptr;
	}
}

Tank::~Tank()
{
	coord.clear();
	current_muzzle_direction.clear();
}
