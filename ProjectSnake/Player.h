#pragma once
#include "MovingBody.h"
#define MAX_HEALTH  20
class Player :
	public MovingBody
{
private:
	int health_;
	int direction_facing_;
public:
	Player(int health = MAX_HEALTH);
	//Setters
	void SetHealth(int health);
	void SetSymbol(char symbol, char head_symbol);
	void IncreaseLength();
	void SetDirectionFacing(int direction);
	//Getters
	int GetHealth() const;
	int GetDirectionFacing() const;
	//Other
	void IncreaseHealth(int increase);
	void DecreaseHealth(int decrease);
	bool IsDead() const;
	//Movement
	virtual void Move(int direction);
	void MovePoints();
	~Player();
};

