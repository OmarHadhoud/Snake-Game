#include "stdafx.h"
#include "MovingBody.h"
#include "DirectedPoint.h"

MovingBody::MovingBody() : StaticBody()
{
}

MovingBody::MovingBody(char symbol) : StaticBody(symbol)
{
}

MovingBody::MovingBody(int x_coordinate, int y_coordinate) : StaticBody(x_coordinate,y_coordinate)
{
}

MovingBody::MovingBody(int x_coordinate, int y_coordinate, int length) : StaticBody(x_coordinate, y_coordinate, length)
{
}

MovingBody::MovingBody(int length) : StaticBody(length)
{
}

void MovingBody::MoveX(int direction, int distance)
{
	for (int i = 0; i < length_; ++i)
	{
		if (direction > 0)
			body_[i].MoveRight(distance);
		else if(direction < 0)
			body_[i].MoveLeft(distance);
	}
}

void MovingBody::MoveY(int direction, int distance)
{
	for (int i = 0; i < length_; ++i)
	{
		if (direction > 0)
			body_[i].MoveUp(distance);
		else if(direction < 0)
			body_[i].MoveDown(distance);
	}
}

void MovingBody::Move(int x_direction, int y_direction, int distance)
{
	MoveX(x_direction, distance);
	MoveY(y_direction, distance);
}

void MovingBody::Move(int direction)
{
	switch (direction)
	{
	case Right:
		Move(1, 0);
		break;
	case Left:
		Move(-1, 0);
		break;
	case Up:
		Move(0, 1);
		break;
	case Down:
		Move(0, -1);
		break;
	}
}


MovingBody::~MovingBody()
{
}
