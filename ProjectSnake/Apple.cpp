#include "stdafx.h"
#include "Apple.h"


Apple::Apple() : Pickup()
{
	this->SetSymbol('*');
}

Apple::Apple(int x_coordinate, int y_cooridnate) : Pickup(x_coordinate, y_cooridnate)
{
	this->SetSymbol('*');

}

bool Apple::Execute(Player * &player)
{
	if (player->GetHead()->GetXCoordinate() == GetXCoordinate() && player->GetHead()->GetYCoordinate() == GetYCoordinate())
	{
		player->IncreaseLength();
		return true;
	}
	return false;
}


Apple::~Apple()
{
}
