#pragma once
#include "Coordinates.h"
class Point :
	public Coordinates
{
private:
	char symbol_;
	int x_direction_;
	int y_direction_;
	int x_speed_;
	int y_speed_;
public:
	//Constructors
	Point();
	Point(int x_coordinate, int y_coordinates = 0);
	Point(char symbol);
	Point(int x_coordinate, int y_coordinate, char symbol);
	//Setters
	void SetSymbol(char symbol = ' ');
	void SetRightOf(Point* other);
	void SetLeftOf(Point* other);
	void SetUpsideOf(Point* other);
	void SetDownwardsOf(Point* other);
	void RotateClockwiseOf(Point* other);
	void RotateAntiClockwiseOf(Point* other); 
	void SetXDirection(int direction);
	void SetYDirection(int direction);
	void SetXSpeed(int speed);
	void SetYSpeed(int speed);
	void SetDirection(int x_direction, int y_direction);
	//Getters
	char GetSymbol() const;
	int GetXDirection() const;
	int GetYDirection() const;
	int GetXSpeed() const;
	int GetYSPeed() const;
	//Movement Functions
	void Move();
	void MoveRight(int distance);
	void MoveLeft(int distance);
	void MoveUp(int distance);
	void MoveDown(int distance);
	~Point();
};

