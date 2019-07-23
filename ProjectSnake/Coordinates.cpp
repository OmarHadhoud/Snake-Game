#include "stdafx.h"
#include "Coordinates.h"


Coordinates::Coordinates(int x_coordinate, int y_coordinate)
{
	SetXCoordinate(x_coordinate);
	SetYCoordinate(y_coordinate);
}

void Coordinates::SetXCoordinate(int x_coordinate)
{
	x_coordinate_ = x_coordinate >= 0 ? x_coordinate : 0;
}

void Coordinates::SetYCoordinate(int y_coordinate)
{
	y_coordinate_ = y_coordinate >= 0 ? y_coordinate : 0;
}

int Coordinates::GetXCoordinate() const
{
	return x_coordinate_;
}

int Coordinates::GetYCoordinate() const
{
	return y_coordinate_;
}

Coordinates::~Coordinates()
{
}
