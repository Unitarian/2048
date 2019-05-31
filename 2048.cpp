// 2048.cpp : Defines the entry point for the console application.

#include "iostream"
#include "conio.h"
#include "GameBoard.h"
#include "GameManager.h"
using namespace std;

int main()
{
	bool playingGame = true;
	do
	{
		GameManager GameInstance = GameManager();
		GameInstance.PlayGame();
		playingGame = GameInstance.GameOver();
	} while (playingGame);
	return 1;
}
