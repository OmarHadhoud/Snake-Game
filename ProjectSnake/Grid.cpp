#include "stdafx.h"
#include "Grid.h"
#include "Pickup.h"
#include <iostream>
#include <Windows.h>

Grid::Grid()
{
	height_ = kMaxHeight;
	width_ = kMaxWidth;
	borders[0] = borders[1] = borders[2] = borders[3] = nullptr;
	SetGrid(' ');
}

void Grid::CreateBorders()
{
	borders[0] = new StaticBody(0, 0, kMaxWidth);
	borders[1] = new StaticBody(0, 1, kMaxHeight-2);
	borders[1]->Rotate(ClockWise);
	borders[2] = new StaticBody(kMaxWidth-1, 1, kMaxHeight-2);
	borders[2]->Rotate(ClockWise);
	borders[3] = new StaticBody(0, kMaxHeight-1, kMaxWidth);
	borders[0]->SetSymbol('=');
	borders[3]->SetSymbol('=');
	borders[1]->SetSymbol('|');
	borders[2]->SetSymbol('|');
}

void Grid::DrawBorders()
{
	if (borders[0] == nullptr) return;
	int x_coordinate, y_coordinate;
	Point* point;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < borders[i]->GetLength(); ++j)
		{
			AddPoint(borders[i]->GetPoint(j));
		}
	}
}

void Grid::DrawBody(StaticBody * body)
{
	for (int i = 0; i < body->GetLength(); ++i)
		AddPoint(body->GetPoint(i));
}

void Grid::DrawPoint(Point * point)
{
	AddPoint(point);
}

void Grid::DrawPickups(vector<Pickup*> points)
{
	for (auto point : points)
		DrawPoint(point);
}

void Grid::StartGame()
{
	Clean();
	CreateBorders();
	ResetGrid();
}

void Grid::SetPlayer(Point * player)
{
	player_ = player;
}

Point * Grid::GetPlayer() const
{
	return player_;
}


void Grid::SetGrid(char symbol)
{
	for (int i = 0; i < height_; ++i)
	{
		for (int j = 0; j < width_; ++j)
		{
			if (game_map_[i][j]!= nullptr && game_map_[i][j]->GetSymbol() == ' ')
				delete game_map_[i][j];
			game_map_[i][j] = new Point(j, i, symbol);
		}
	}	

}

void Grid::ResetGrid()
{
	SetGrid();
	DrawBorders();
}

bool Grid::AddPoint(Point * point)
{
	int x_coordinate = point->GetXCoordinate();
	int y_coordinate = point->GetYCoordinate();
	if (game_map_[y_coordinate][x_coordinate]->GetSymbol() != ' ')
		return false;
	delete game_map_[y_coordinate][x_coordinate];
	game_map_[y_coordinate][x_coordinate] = point;
	return true;
}

void Grid::PrintGrid() const
{
	for (int i = 0; i < height_; ++i)
	{
		for (int j = 0; j < width_; ++j)
		{
			cout << game_map_[i][j]->GetSymbol();
 		}
		cout << "\n";
	}
}


void Grid::Clean()
{
	delete borders[0]; borders[0] = nullptr;
	delete borders[1]; borders[1] = nullptr;
	delete borders[2]; borders[2] = nullptr;
	delete borders[3]; borders[3] = nullptr;
	for (int i = 1; i < height_-1; ++i)
	{
		for (int j = 1; j < width_-1; ++j)
			if(game_map_[i][j]!=nullptr && game_map_[i][j]->GetSymbol()==' ')
				delete game_map_[i][j], game_map_[i][j] = nullptr;
	}
}

Grid::~Grid()
{
	Clean();
}
