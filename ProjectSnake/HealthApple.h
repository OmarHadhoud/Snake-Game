#pragma once
#include "Pickup.h"
class HealthApple :
	public Pickup
{
private:
	int health_value_;
public:
	HealthApple(int x_coordinate, int y_coordinate);
	HealthApple(int health_value = 5);
	HealthApple(int x_cooridnate, int y_coordinate, int health_value);
	//Setters
	void SetHealthValue(int health_value);
	//Getters
	int GetHealthValue() const;
	virtual bool Execute(Player* &player);
	~HealthApple();
};

