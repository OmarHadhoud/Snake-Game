#include "stdafx.h"
#include "StaticBody.h"
#include "Enums.h"
#include <vector>
#include <map>

StaticBody::StaticBody()
{
	this->SetLength(2);
	body_ = new DirectedPoint[2];
	head_ = body_;
	tale_ = &body_[1];
	tale_ = static_cast<DirectedPoint*>(tale_);
	tale_->SetRightOf(head_);
}

StaticBody::StaticBody(char symbol)
{
	this->SetLength(2);
	body_ = new DirectedPoint[2];
	head_ = body_;
	tale_ = &body_[1];
	tale_->SetRightOf(head_);
	tale_ = static_cast<DirectedPoint*>(tale_);
	SetSymbol(symbol);
}

StaticBody::StaticBody(int x_coordinate, int y_coordinate)
{
	this->SetLength(2);
	body_ = new DirectedPoint[2];
	body_[0].SetXCoordinate(x_coordinate);
	body_[0].SetYCoordinate(y_coordinate);
	head_ = body_;
	tale_ = &body_[1];
	tale_ = static_cast<DirectedPoint*>(tale_);
	tale_->SetRightOf(head_);
}

StaticBody::StaticBody(int x_coordinate, int y_coordinate, int length)
{
	this->SetLength(length);
	body_ = new DirectedPoint[length];
	body_[0].SetXCoordinate(x_coordinate);
	body_[0].SetYCoordinate(y_coordinate);
	head_ = body_;
	tale_ = &body_[length-1];
	tale_ = static_cast<DirectedPoint*>(tale_);
	Point* temp = &body_[1];
	temp = static_cast<DirectedPoint*>(temp);
	Point* prev = &body_[0];
	prev = static_cast<DirectedPoint*>(prev);
	while (temp != tale_)
	{
		temp->SetRightOf(prev);
		temp++;
		prev++;
	}
	tale_->SetRightOf(prev);
}

StaticBody::StaticBody(int length)
{
	this->SetLength(length);
	body_ = new DirectedPoint[length];
	head_ = body_;
	tale_ = &body_[length - 1];
	tale_ = static_cast<DirectedPoint*>(tale_);
	Point* temp = &body_[1];
	temp = static_cast<DirectedPoint*>(temp);
	Point* prev = &body_[0];
	prev = static_cast<DirectedPoint*>(prev);
	while (temp != tale_)
	{
		temp->SetRightOf(prev);
		temp++;
		prev++;
	}
	tale_->SetRightOf(prev);
}

void StaticBody::SetLength(int length)
{
	length_ = length > 1 ? length : 2;
}

void StaticBody::SetHead(Point * head)
{
	head_ = head;
}

void StaticBody::SetTale(Point * tale)
{
	tale_ = tale;
}

void StaticBody::SetSymbol(char symbol)
{
	for (int i = 0; i < length_; ++i)
		body_[i].SetSymbol(symbol);
}

void StaticBody::SetHeadSymbol(char symbol)
{
	head_->SetSymbol(symbol);
}

int StaticBody::GetLength() const
{
	return length_;
}

Point * StaticBody::GetHead() const
{
	return head_;
}

Point * StaticBody::GetTale() const
{
	return tale_;
}

Point * StaticBody::GetPoint(int number) const
{
	return &body_[number];
}

void StaticBody::AddPoint()
{
	int x_coordinate = head_->GetXCoordinate();
	int y_coordinate = head_->GetYCoordinate();
	int length = this->GetLength() + 1;
	this->Clean();
	StaticBody(x_coordinate, y_coordinate, length);
}

void StaticBody::AddPoints(int number_of_points)
{
	int x_coordinate = head_->GetXCoordinate();
	int y_coordinate = head_->GetYCoordinate();
	int length = this->GetLength() + number_of_points;
	this->Clean();
	StaticBody(x_coordinate, y_coordinate, length);
}

void StaticBody::RemovePoint()
{
	int x_coordinate = head_->GetXCoordinate();
	int y_coordinate = head_->GetYCoordinate();
	int length = this->GetLength() - 1;
	this->Clean();
	StaticBody(x_coordinate, y_coordinate, length);
}

void StaticBody::RemovePoints(int number_of_points)
{
	int x_coordinate = head_->GetXCoordinate();
	int y_coordinate = head_->GetYCoordinate();
	int length = this->GetLength() - number_of_points;
	this->Clean();
	StaticBody(x_coordinate, y_coordinate, length);
}

void StaticBody::Rotate(int dir)
{
	Point* temp = &body_[1];
	Point* prev = &body_[0];
	if (dir == ClockWise)
	{
		while (true)
		{
			temp->RotateClockwiseOf(prev);
			if (temp == tale_) break;
			temp++;
			prev++;
		}
	}
	else if (dir == AntiClockWise)
	{
		while (true)
		{
			temp->RotateAntiClockwiseOf(prev);
			if (temp == tale_) break;
			temp++;
			prev++;
		}
	}
}

void StaticBody::RotateNumberOfTimes(int direction, int number_of_times)
{
	number_of_times %= 4;
	while (number_of_times--)
		Rotate(direction);
}

void StaticBody::UpdateLength(int new_length)
{
	std::vector<std::pair<int, int>> old_coordinates;
	for (int i = 0; i < length_; ++i)
		old_coordinates.push_back(std::make_pair(body_[i].GetXCoordinate(), body_[i].GetYCoordinate()));
	SetLength(new_length);
	int x_coordinate = body_[0].GetXCoordinate(); int y_coordinate = body_[0].GetYCoordinate();
	Clean();
	this->StaticBody::StaticBody(x_coordinate, y_coordinate, length_);
	for (int i = 0; i < length_ - 1; ++i)
		body_[i].SetXCoordinate(old_coordinates[i].first), body_[i].SetYCoordinate(old_coordinates[i].second);
	int dx = body_[length_ - 2].GetXCoordinate() - body_[length_ - 3].GetXCoordinate();
	int dy = body_[length_ - 2].GetYCoordinate() - body_[length_ - 3].GetYCoordinate();
	body_[length_ - 1].SetXCoordinate(body_[length_ - 2].GetXCoordinate() - dx);
	body_[length_ - 1].SetYCoordinate(body_[length_ - 2].GetYCoordinate() - dy);
}


void StaticBody::Clean()
{
	if(body_!=nullptr)
		delete[] body_;
	body_ = nullptr;
}

StaticBody::~StaticBody()
{
	Clean();
}
