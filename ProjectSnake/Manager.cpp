#include "stdafx.h"
#include "Manager.h"
#include "Apple.h"
#include "HealthApple.h"
#include "Trap.h"
#include <fstream>
#include <string>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>


Manager::Manager()
{
	LoadData();
	SetScore(0);
	SetHighScore(0);
	if(scores_.size()>0)
		SetHighScore(scores_.begin()->first);
	SetScreenSize(kMaxWidth, kMaxHeight);
	player_ = new Player();
	player_->SetSymbol('O','X');
	pickup_delay_time_ = 10;
}

void Manager::SetScore(int score)
{
	score_ = score >= 0 ? score : 0;
}

void Manager::SetHighScore(int high_score)
{
	high_score_ = high_score > high_score_ ? high_score : high_score_;
}

void Manager::IncreaseScore(int increase)
{
	if (increase <= 0) return;
	score_ += increase;
}

void Manager::DecreaseScore(int decrease)
{
	if (decrease <= 0) return;
	score_ -= decrease;
}

void Manager::AddScore(int score, string name)
{
	scores_.insert(make_pair(score, name));
}

void Manager::SetScreenSize(int width, int height)
{
	width += 10;
	height += 10;
	_COORD coord;
	coord.X = width;
	coord.Y = height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = height - 1;
	Rect.Right = width - 1;

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(handle, &cursor_info);
	cursor_info.bVisible = false;
	SetConsoleScreenBufferSize(handle, coord);
	SetConsoleWindowInfo(handle, TRUE, &Rect);
	SetConsoleCursorInfo(handle, &cursor_info);
}

int Manager::GetScore() const
{
	return score_;
}

int Manager::GetHighScore() const
{
	return high_score_;
}

void Manager::SaveData()
{
	ofstream data("data.txt");
	for (auto score : scores_)
	{
		data << score.first << " " << score.second << endl;
	}
}

void Manager::LoadData()
{
	ifstream data("data.txt");
	string name, score_string;
	int score;
	while (data >> score_string)
	{
		data >> name;
		score = stoi(score_string);
		high_score_ = score > high_score_ ? score : high_score_;
		scores_.insert(make_pair(score, name));
	}
}

void Manager::ShowOptions(vector<string> vec) const
{
	int i = 1;
	for (auto v : vec)
		cout << i++ << "-" << v << endl;
}

int Manager::WelcomeMenu()
{
	system("CLS");
	cout << "Welcome to Snake!\nPlease enter the number of \nthe option you want : ";
	vector<string> menu_options = { "Play", "Scores", "About", "Exit" };
	ShowOptions(menu_options);
	int choice; cin >> choice; return choice;
}

void Manager::Play()
{
	ClearScreen();
	int direction;
	GetReadyToPlay();
	bool game_finished = false;
	int pickups_counter = 0;
	while (!game_finished)
	{
		ClearScreen();
		PlayerUpdate();
		game_finished = CheckTouch() || player_->IsDead();
		if (game_finished) return;
		game_grid_.ResetGrid();
		game_grid_.DrawBody(player_);
		game_grid_.DrawPickups(pickups_);
		game_grid_.PrintGrid();
		PrintScoreAndHealth();
		Sleep(100);
		pickups_counter++;
		if (pickups_counter >= pickup_delay_time_)
		{
			AddRandomPickup();
			pickups_counter = 0;
		}
	}
}

void Manager::About()
{
	system("CLS");
	cout << "Welcome to snake.\nA game developed by Omar Hadhoud\n as an OOP project for practice!\n";
	cin.get();
	cin.get();
}

void Manager::HighScores()
{
	system("CLS");
	int i = 1;
	for(auto it: scores_)
		cout << i << "-" << it.second << " (" << it.first << ")\n";
	cout << "Press any key to return!";
	cin.get();
	cin.get();
}

void Manager::ClearScreen()
{
	COORD coord; coord.X = 0; coord.Y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, coord);
}

void Manager::GetReadyToPlay()
{
	system("CLS"); 
	for (auto p : pickups_)
		delete p;
	pickups_.clear();
	this->game_grid_.StartGame();
}

int Manager::GetDirection() const
{
	int key_pressed = 0;
	if (_kbhit())
	{

		key_pressed = _getch();
		key_pressed = _getch();
	}
	if (key_pressed == 75 && player_->GetDirectionFacing()!=Right)
		player_->SetDirectionFacing(Left);
	else if (key_pressed == 77 && player_->GetDirectionFacing() != Left)
		player_->SetDirectionFacing(Right);
	else if (key_pressed == 80 && player_->GetDirectionFacing() != Up)
		player_->SetDirectionFacing(Down);
	else if (key_pressed == 72 && player_->GetDirectionFacing() != Down)
		player_->SetDirectionFacing(Up);
	return player_->GetDirectionFacing();
}


void Manager::PlayerUpdate()
{
	int direction = GetDirection();
	player_->Move(direction);
}

bool Manager::CheckTouch()
{
	int x_pos = player_->GetHead()->GetXCoordinate();
	int y_pos = player_->GetHead()->GetYCoordinate();
	if (x_pos >= kMaxWidth || x_pos <= 0 || y_pos <= 0 || y_pos >= kMaxHeight)
	{
		GameOver();
		return true;
	}
	for (int i = 1; i < player_->GetLength(); ++i)
		if (x_pos == player_->GetPoint(i)->GetXCoordinate() && y_pos == player_->GetPoint(i)->GetYCoordinate())
		{
			GameOver(); return true;
		}
	for (auto p : pickups_)
	{
		if (p->Execute(player_))
		{
			Pickup* tmp_pickup = p;
			pickups_.erase(find(pickups_.begin(), pickups_.end(), p));
			Apple* is_apple = dynamic_cast<Apple*>(tmp_pickup);
			if (is_apple) IncreaseScore(1);
			delete tmp_pickup;
		}
		if (player_->IsDead())
		{
			GameOver();
			return true;
		}
	}
	return false;
}

void Manager::PrintScoreAndHealth() const
{
	cout << "Score : " << score_ << endl;
	cout << "High Score : " << high_score_ << endl;
	cout << "Heatlh : " << player_->GetHealth() << endl;
	cout << "Length : " << player_->GetLength() << endl;
}

void Manager::AddRandomPickup()
{
	int random_number;
	Pickup* pickup;
	srand(time(NULL));
	random_number = (rand() % 10) + 1;
	switch (random_number)
	{
	case 1:
	case 4:
	case 5:
	case 6:
	case 7:
		pickup = new Apple();
		break;
	case 2:
	case 8:
		pickup = new HealthApple();
		break;
	case 3:
	case 9:
	case 10:
		pickup = new Trap();
		break;
	default:
		pickup = new Apple();
		break;
	}
	pickup->RandomizePosition();
	AddPickup(pickup);
}

void Manager::AddPickup(Pickup * pickup)
{	
	if(game_grid_.AddPoint(pickup))
		pickups_.push_back(pickup);
}

void Manager::GameOver()
{
	game_grid_.Clean();
	delete player_;
	player_ = new Player();
	player_->SetSymbol('O', 'X');
	system("CLS");
	cout << "Game Over!\n Your score is : " << score_ << endl;
	cout << "Please enter your name to save in highscores : ";
	string name; cin >> name;
	scores_.insert(make_pair(score_, name));
	cout << "Press any key to return !\n";
	cin.ignore();
	cin.get();
}


Manager::~Manager()
{
	SaveData();
	if(player_!=nullptr)
		delete player_;
	for (auto p : pickups_)
		delete p;
}
