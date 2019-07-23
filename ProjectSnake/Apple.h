#pragma once
#include "Pickup.h"
class Apple :
	public Pickup
{
public:
	Apple();
	Apple(int x_coordinate, int y_cooridnate);
	virtual bool Execute(Player* &player);
	~Apple();
};

