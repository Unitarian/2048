#pragma once
#include "board.h"


class GameBoard : public Board
{
public:
	GameBoard(int r, int c);
	~GameBoard();
	void Render(int score);
	unsigned GetNumberOfDigits (unsigned i);
};