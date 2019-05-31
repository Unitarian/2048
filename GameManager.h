#pragma once
#include "GameBoard.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class GameManager
{
public:
	int score;
	GameBoard* GameBoardInstance;
	GameManager();
	~GameManager();
	void PlayGame();
	bool GameOver();
private:
	void GenerateNumberAtRandomPosition();
	int GetValueAtIndex(int i, int j);
	void SetValueAtIndex(int i, int j, int value);

	bool Move_Up();
	bool Move_Down();
	bool Move_Right();
	bool Move_Left();

	bool Check_GameOver();
};