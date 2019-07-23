#pragma once
#include "Pickup.h"
class Trap :
	public Pickup
{
private : 
	int damage_value_;
public:
	Trap(int x_coordinate, int y_coordinate);
	Trap(int damage_value = 10);
	Trap(int x_coordinate, int y_coordinate, int damage_value);
	//Setters
	void SetDamageValue(int damage_value);
	//Getters
	int GetDamageValue() const;
	virtual bool Execute(Player* &player);
	~Trap();
};

