#include "stdafx.h"
#include "Trap.h"



Trap::Trap(int x_coordinate, int y_coordinate) : Pickup(x_coordinate,y_coordinate)
{
	this->SetSymbol('#');
}

Trap::Trap(int damage_value) : Pickup()
{
	this->SetDamageValue(damage_value);
	this->SetSymbol('#');
}

Trap::Trap(int x_coordinate, int y_coordinate, int damage_value) : Pickup(x_coordinate, y_coordinate)
{
	this->SetDamageValue(damage_value);
	this->SetSymbol('#');
}

void Trap::SetDamageValue(int damage_value)
{
	damage_value_ = damage_value > 0 ? damage_value : 1;
}

int Trap::GetDamageValue() const
{
	return damage_value_;
}

bool Trap::Execute(Player * &player)
{
	if (player->GetHead()->GetXCoordinate() == GetXCoordinate() && player->GetHead()->GetYCoordinate() == GetYCoordinate())
	{
		player->DecreaseHealth(damage_value_);
		return true;
	}
	return false;
}


Trap::~Trap()
{
}
