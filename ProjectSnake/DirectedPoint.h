#pragma once
#include "Point.h"
class DirectedPoint :
	public Point
{
private:
	
public:
	DirectedPoint();
	DirectedPoint(int x_coordinate, int y_coordinate);
	//Setters
	
	//Getters
	
	//Movement
	void Move();
	void MoveRight(int distance);
	void MoveLeft(int distance);
	void MoveUp(int distance);
	void MoveDown(int distance);
	~DirectedPoint();
};

