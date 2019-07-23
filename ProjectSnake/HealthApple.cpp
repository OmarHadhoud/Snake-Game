#include "stdafx.h"
#include "HealthApple.h"



HealthApple::HealthApple(int x_coordinate, int y_coordinate) : Pickup(x_coordinate,y_coordinate)
{
	this->SetSymbol('+');
}


HealthApple::HealthApple(int health_value) : Pickup()
{
	this->SetHealthValue(health_value);
	this->SetSymbol('+');
}

HealthApple::HealthApple(int x_cooridnate, int y_coordinate, int health_value) : Pickup(x_cooridnate, y_coordinate)
{
	this->SetHealthValue(health_value);
	this->SetSymbol('+');
}

void HealthApple::SetHealthValue(int health_value)
{
	health_value_ = health_value > 0 ? health_value : 1;
}

int HealthApple::GetHealthValue() const
{
	return health_value_;
}

bool HealthApple::Execute(Player * &player)
{
	if (player->GetHead()->GetXCoordinate() == GetXCoordinate() && player->GetHead()->GetYCoordinate() == GetYCoordinate())
	{
		player->IncreaseHealth(health_value_);
		return true;
	}
	return false;
}

HealthApple::~HealthApple()
{
}
