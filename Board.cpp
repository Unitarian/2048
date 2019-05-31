#include "Board.h"
#include "iostream"
#include "conio.h"
using namespace std;

Board::Board(int r, int c)
{
	this->rowCount = r;
	this->columnCount = c;

	this->grid = new int*[this->rowCount];
	
	for(int i = 0; i < this->rowCount; i++)
	{
		this->grid[i] = new int[this->columnCount];

		for (int j = 0; j < this->columnCount; j++)
		{
			this->grid[i][j] = EMPTY_VALUE;
		}
	}
}


Board::~Board()
{
	for(int i = 0; i < this->rowCount; i++)
	{
		delete[] this->grid[i];
	}
	delete[] this->grid;
}

void Board:: Render(int score)
{
	//cout<<"This is GameBoard-> Render(). Score: "<<score<<endl;
}
