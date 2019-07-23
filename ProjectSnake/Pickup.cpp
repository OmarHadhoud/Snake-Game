#include "stdafx.h"
#include "Pickup.h"


Pickup::Pickup() : DirectedPoint()
{
	this->time_to_be_destroyed_ = _CRT_INT_MAX;
}

Pickup::Pickup(int x_coordinate, int y_coordinate) : DirectedPoint(x_coordinate,y_coordinate)
{
	this->time_to_be_destroyed_ = _CRT_INT_MAX;
}

Pickup::Pickup(int time) : DirectedPoint()
{
	SetTimeToBeDestroyed(time);
}

Pickup::Pickup(int x_coordinate, int y_coordinate, int time) : DirectedPoint(x_coordinate, y_coordinate)
{
	SetTimeToBeDestroyed(time);
}

void Pickup::SetTimeToBeDestroyed(int time)
{
	this->time_to_be_destroyed_ = time > 0 ? time : _CRT_INT_MAX;
}

void Pickup::RandomizePosition()
{
	int x_pos; int y_pos;
	srand(time(NULL));
	x_pos = rand() % kMaxWidth;
	if (x_pos == 0) x_pos++;
	y_pos = rand() % kMaxHeight;
	if (y_pos == 0) y_pos++;
	this->SetXCoordinate(x_pos);
	this->SetYCoordinate(y_pos);
}

int Pickup::GetTimeToBeDestroyed() const
{
	return time_to_be_destroyed_;
}


Pickup::~Pickup()
{
}
