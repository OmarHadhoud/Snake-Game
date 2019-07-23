#pragma once
#include "Enums.h"
#include "Point.h"
#include "StaticBody.h"
#include "Pickup.h"
#include <map>
#include <string>
using namespace std;

class Grid
{
private:
	Point *game_map_[kMaxHeight][kMaxWidth];
	int width_;
	int height_;
	Point *player_;
	Point *pickups_[kMaxHeight*kMaxWidth];
	StaticBody* borders[4];
public:
	//Constructors
	Grid();
	//Setters
	void SetPlayer(Point* player);
	//Getters
	Point* GetPlayer() const;
	//Other Functions
	void SetGrid(char symbol = ' ');
	void ResetGrid();
	void CreateBorders();
	void DrawBorders();
	void DrawBody(StaticBody* body);
	void DrawPoint(Point* point);
	void DrawPickups(vector<Pickup*> points);
	void StartGame();
	bool AddPoint(Point* point);
	void PrintGrid() const;
	//Destructos & Cleaners
	void Clean();
	~Grid();
};

