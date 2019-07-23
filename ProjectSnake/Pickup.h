#pragma once
#include "DirectedPoint.h"
#include "Player.h"
#include <time.h>
//Include player
class Pickup :
	public DirectedPoint
{
private:
	int time_to_be_destroyed_;
public:
	Pickup();
	Pickup(int x_coordinate, int y_coordinate);
	Pickup(int time);
	Pickup(int x_coordinate, int y_coordinate, int time);
	//Setters
	void SetTimeToBeDestroyed(int time);
	void RandomizePosition();
	//Getters
	int GetTimeToBeDestroyed() const;
	//Execute functions
	virtual bool Execute(Player*&) = 0;
	~Pickup();
};

