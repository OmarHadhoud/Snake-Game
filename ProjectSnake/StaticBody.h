#pragma once
#include "Point.h"
#include "DirectedPoint.h"
#include <vector>
class StaticBody
{
protected:
	int length_;
	Point *body_ = nullptr;
	Point *head_;
	Point *tale_;
public:
	StaticBody();
	StaticBody(char symbol);
	StaticBody(int x_coordinate, int y_coordinate);
	StaticBody(int x_coordinate, int y_coordinate, int length);
	StaticBody(int length);
	//Setters
	void SetLength(int length);
	void SetHead(Point* head);
	void SetTale(Point* tale);
	void SetSymbol(char symbol);
	void SetHeadSymbol(char symbol);
	//Getters
	int GetLength() const;
	Point* GetHead() const;
	Point* GetTale() const;
	Point* GetPoint(int number) const;
	//Other functions
	void AddPoint();
	void AddPoints(int number_of_points);
	void RemovePoint();
	void RemovePoints(int number_of_points);
	void Rotate(int dir);
	void RotateNumberOfTimes(int direction, int number_of_times);
	void UpdateLength(int new_length);
	//Destructors & clean
	void Clean();
	~StaticBody();
};

