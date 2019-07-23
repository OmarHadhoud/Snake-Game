#include "stdafx.h"
#include "Player.h"
#include <algorithm>
#include "Enums.h"

Player::Player(int health) : MovingBody(kMaxWidth/2, kMaxHeight/2)
{
	SetHealth(health);
	direction_facing_ = Left;
}

void Player::SetHealth(int health)
{
	health_ = health;
	if (health < 0) health_ = 0;
	health_ = std::min(health_, MAX_HEALTH);
}

void Player::SetSymbol(char symbol, char head_symbol)
{
	StaticBody::SetSymbol(symbol);
	SetHeadSymbol(head_symbol);
}

void Player::IncreaseLength()
{
	this->UpdateLength(this->GetLength() + 1);
	this->SetSymbol('O', 'X');
}

void Player::SetDirectionFacing(int direction)
{
	direction_facing_ = direction;
}


int Player::GetHealth() const
{
	return health_;
}

int Player::GetDirectionFacing() const
{
	return direction_facing_;
}

void Player::IncreaseHealth(int increase)
{
	SetHealth(GetHealth() + increase);
}

void Player::DecreaseHealth(int decrease)
{
	SetHealth(GetHealth() - decrease);
}

bool Player::IsDead() const
{
	return health_ == 0;
}

void Player::Move(int direction)
{
	char temp;
	temp = tale_->GetSymbol();
	tale_->SetSymbol(head_->GetSymbol());
	head_->SetSymbol(temp);
	switch (direction) 
	{
	case Up:
		direction_facing_ = Up;;
		tale_->SetUpsideOf(head_);
		break;
	case Down:
		direction_facing_ = Down;
		tale_->SetDownwardsOf(head_);
		break;
	case Right:
		direction_facing_ = Right;
		tale_->SetRightOf(head_);
		break;
	case Left:
		direction_facing_ = Left;
		tale_->SetLeftOf(head_);
		break;
	}
	std::swap(body_[0],body_[length_-1]);
	MovePoints();
	tale_ = GetPoint(length_-1);
}
void Player::MovePoints()
{
	Point tmp = *tale_;
	for (int i = length_-1; i > 1; --i)
	{
		body_[i] = body_[i - 1];
	}
	body_[1] = tmp;
}
Player::~Player()
{
}
