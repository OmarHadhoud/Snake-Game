#pragma once
#include "StaticBody.h"
class MovingBody : public StaticBody
{
public:
	//Constructors
	MovingBody();
	MovingBody(char symbol);
	MovingBody(int x_coordinate, int y_coordinate);
	MovingBody(int x_coordinate, int y_coordinate, int length);
	MovingBody(int length);
	//Movement
	virtual void MoveX(int direction, int dist = 1);
	virtual void MoveY(int direction, int dist = 1);
	virtual void Move(int x_direction, int y_direction, int dist = 1);
	virtual void Move(int direction);
	~MovingBody();
};

