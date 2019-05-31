#pragma once

#define EMPTY_VALUE -99

class Board
{
public:
	int rowCount;
	int columnCount;
	int** grid;

	Board(int r, int c);
	~Board();
	
	// Render Board Grid
	virtual void Render(int score);
private:

};