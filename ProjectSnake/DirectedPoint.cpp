#include "stdafx.h"
#include "DirectedPoint.h"
#include <algorithm>

DirectedPoint::DirectedPoint() : Point()
{
}

DirectedPoint::DirectedPoint(int x_coordinate, int y_coordinate) : Point(x_coordinate,y_coordinate)
{
	this->SetDirection(0, 0);
	this->SetXSpeed(0);
	this->SetYSpeed(0);
}



DirectedPoint::~DirectedPoint()
{
}
