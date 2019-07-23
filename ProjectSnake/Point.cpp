#include "stdafx.h"
#include "Point.h"
#include <algorithm>
using namespace std;

Point::Point()
{
	this->SetXCoordinate(0);
	this->SetYCoordinate(0);
	this->SetSymbol(' ');
	this->SetXDirection(0);
	this->SetYDirection(0);
	this->SetXSpeed(0);
	this->SetYSpeed(0);
}

Point::Point(int x_coordinate, int y_coordinate) : Coordinates(x_coordinate,y_coordinate)
{
	this->SetSymbol(' ');
	this->SetXDirection(0);
	this->SetYDirection(0);
	this->SetXSpeed(0);
	this->SetYSpeed(0);
}

Point::Point(char symbol) : Coordinates(0,0)
{
	this->SetSymbol(symbol);
	this->SetXDirection(0);
	this->SetYDirection(0);
	this->SetXSpeed(0);
	this->SetYSpeed(0);
}

Point::Point(int x_coordinate, int y_coordinate, char symbol) : Coordinates(x_coordinate, y_coordinate)
{
	this->SetSymbol(symbol);
	this->SetXDirection(0);
	this->SetYDirection(0);
	this->SetXSpeed(0);
	this->SetYSpeed(0);
}

void Point::SetSymbol(char symbol)
{
	symbol_ = symbol;
}

void Point::SetRightOf(Point * other)
{
	this->SetXCoordinate(other->GetXCoordinate() + 1);
	this->SetYCoordinate(other->GetYCoordinate());
}

void Point::SetLeftOf(Point * other)
{
	this->SetXCoordinate(other->GetXCoordinate() - 1);
	this->SetYCoordinate(other->GetYCoordinate());
}

void Point::SetUpsideOf(Point * other)
{
	this->SetXCoordinate(other->GetXCoordinate());
	this->SetYCoordinate(other->GetYCoordinate() - 1);
}

void Point::SetDownwardsOf(Point * other)
{
	this->SetXCoordinate(other->GetXCoordinate());
	this->SetYCoordinate(other->GetYCoordinate()+1);
}

void Point::RotateClockwiseOf(Point * other)
{
	if (this->GetXCoordinate() > other->GetXCoordinate())
	{
		this->SetDownwardsOf(other);
	}
	else if (this->GetXCoordinate() < other->GetXCoordinate())
	{
		this->SetUpsideOf(other);
	}
	else if (this->GetYCoordinate() > other->GetYCoordinate())
	{
		this->SetLeftOf(other);
	}
	else if(this->GetYCoordinate() < other->GetYCoordinate())
	{
		this->SetRightOf(other);
	}
}

void Point::RotateAntiClockwiseOf(Point * other)
{
	if (this->GetXCoordinate() > other->GetXCoordinate())
	{
		this->SetUpsideOf(other);
	}
	else if (this->GetXCoordinate() < other->GetXCoordinate())
	{
		this->SetDownwardsOf(other);
	}
	else if (this->GetYCoordinate() > other->GetYCoordinate())
	{
		this->SetRightOf(other);
	}
	else if (this->GetYCoordinate() < other->GetYCoordinate())
	{
		this->SetLeftOf(other);
	}
}

char Point::GetSymbol() const
{
	return symbol_;
}
void Point::SetXDirection(int direction)
{
	x_direction_ = direction >= 1 ? 1 : -1;
	if (!direction) x_direction_ = 0;
}

void Point::SetYDirection(int direction)
{
	y_direction_ = direction <= 1 ? 1 : -1;
	if (!direction) y_direction_ = 0;
}

void Point::SetXSpeed(int speed)
{
	x_speed_ = std::max(0, speed);
}

void Point::SetYSpeed(int speed)
{
	y_speed_ = std::max(0, speed);
}

void Point::SetDirection(int x_direction, int y_direction)
{
	this->SetXDirection(x_direction);
	this->SetYDirection(y_direction);
}

int Point::GetXDirection() const
{
	return x_direction_;
}

int Point::GetYDirection() const
{
	return y_direction_;
}

int Point::GetXSpeed() const
{
	return x_speed_;
}

int Point::GetYSPeed() const
{
	return y_speed_;
}


void Point::Move()
{
	if (x_speed_ > 1)
		this->MoveRight(x_speed_);
	else
		this->MoveLeft(-1 * x_speed_);
	if (y_speed_ > 1)
		this->MoveUp(y_speed_);
	else
		this->MoveDown(-1 * y_speed_);
}

void Point::MoveRight(int distance)
{
	SetDirection(1, 0);
}

void Point::MoveLeft(int distance)
{
	SetDirection(-1, 0);
}

void Point::MoveUp(int distance)
{
	SetDirection(0, 1);
}

void Point::MoveDown(int distance)
{
	SetDirection(0, -1);
}
Point::~Point()
{
}
