#pragma once
#include "Enums.h"
class Coordinates
{
private:
	int x_coordinate_;
	int y_coordinate_;
public:
	//Connstructors
	Coordinates(int x_coordinate = 0, int y_coordinate = 0);
	//Setters
	void SetXCoordinate(int x_coordinate);
	void SetYCoordinate(int y_coordinate);
	//Getters
	int GetXCoordinate() const;
	int GetYCoordinate() const;
	~Coordinates();
};

