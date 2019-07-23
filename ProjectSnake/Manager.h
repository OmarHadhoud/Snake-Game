#pragma once
#include "Grid.h"
#include "Player.h"
#include "Pickup.h"
#include <vector>

class Manager
{
private:
	Grid game_grid_;
	int score_;
	int high_score_;
	multimap<int, string, std::greater<int>> scores_;
	Player *player_;
	vector<Pickup*> pickups_;
	int pickup_delay_time_;
public:
	//Constructors
	Manager();
	//Setters
	void SetScore(int score);
	void SetHighScore(int high_score);
	void IncreaseScore(int increase);
	void DecreaseScore(int decrease);
	void AddScore(int score, string name);
	void SetScreenSize(int width = kMaxWidth, int height=kMaxHeight);
	//Getters
	int GetScore() const;
	int GetHighScore() const;
	//Saving&Loading
	void SaveData();
	void LoadData();
	//Menu functions
	void ShowOptions(vector<string> vec) const;
	int WelcomeMenu();
	void Play();
	void About();
	void HighScores();
	void ClearScreen();
	//Other functions
	//PlayMode
	void GetReadyToPlay();
	int GetDirection() const;
	void PlayerUpdate();
	bool CheckTouch();
	void PrintScoreAndHealth() const;
	void AddRandomPickup();
	void AddPickup(Pickup* pickup);
	void GameOver();
	//Destructors
	~Manager();
};

