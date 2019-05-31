#include "iostream"
#include "conio.h"
#include "GameManager.h"
 #include <cstdlib>
#include <list>

using namespace std;

GameManager::GameManager()
{
	score = 0;
	this->GameBoardInstance = new GameBoard(4,4);
	this->GameBoardInstance->Render(score);
}

GameManager::~GameManager()
{
}

void GameManager::PlayGame()
{
	int input = 0;
	bool isMoved ;
	
	GenerateNumberAtRandomPosition();
	GenerateNumberAtRandomPosition();

	while(true)
	{
		input=_getch();

		switch(input) 
		{
		case KEY_UP:
			isMoved = Move_Up();
			break;
		case KEY_DOWN:
			isMoved = Move_Down();
			break;
		case KEY_LEFT:
			isMoved = Move_Left();
			break;
		case KEY_RIGHT:
			isMoved = Move_Right();
			break;
		default:
			continue;
			break;
		}
		if (Check_GameOver())
		{
			break;
		}
		if (isMoved)
		{
			GenerateNumberAtRandomPosition();
		}
	
	}
}

bool GameManager::Move_Up()
{
	bool Ismoved = false;
	for (int j = 0; j <this->GameBoardInstance->columnCount; j++)
	{
		for (int i = 1; i < GameBoardInstance->rowCount  ; i++)
		{
			int cellValue = GetValueAtIndex(i,j);
			if (cellValue == EMPTY_VALUE)
			{
				continue;
			}
			int rw= i;
			while (rw > 0 &&
				GetValueAtIndex(rw-1,j) == EMPTY_VALUE 
				)
			{
				rw--;
				Ismoved = true;
			}
			if (rw == 0)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(rw,j,cellValue);
			}
			else if (GetValueAtIndex(rw-1,j) == cellValue)
			{
				score += cellValue*2;
				SetValueAtIndex(rw-1,j,cellValue*2);
				SetValueAtIndex(i,j,EMPTY_VALUE);
				Ismoved = true;
			}
			else if(rw != i)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(rw,j,cellValue);
			}
		}
	}
	return Ismoved;
}

bool GameManager::Move_Down()
{
	bool Ismoved = false;
	for (int j = 0; j <this->GameBoardInstance->columnCount; j++)
	{
		for (int i = this->GameBoardInstance->rowCount-2; i >= 0  ; i--)
		{
			int cellValue = GetValueAtIndex(i,j);
			if (cellValue == EMPTY_VALUE)
			{
				continue;
			}
			int rw= i;
			while (rw < this->GameBoardInstance->rowCount-1 &&
				GetValueAtIndex(rw+1,j) == EMPTY_VALUE 
				)
			{
				rw++;
				Ismoved = true;
			}
			if (rw == this->GameBoardInstance->rowCount-1)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(rw,j,cellValue);
			}
			else if (GetValueAtIndex(rw+1,j) == cellValue)
			{
				score += cellValue*2;
				SetValueAtIndex(rw+1,j,cellValue*2);
				SetValueAtIndex(i,j,EMPTY_VALUE);
				Ismoved = true;
			}
			else if (rw != i)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(rw,j,cellValue);
			}
		}
	}
	return Ismoved;
}

bool GameManager::Move_Right()
{
	bool Ismoved = false;
	for (int i = 0; i <this->GameBoardInstance->rowCount; i++)
	{
		for (int j = this->GameBoardInstance->columnCount-2; j >= 0  ; j--)
		{
			int cellValue = GetValueAtIndex(i,j);
			if (cellValue == EMPTY_VALUE)
			{
				continue;
			}
			int c= j;
			while (c < this->GameBoardInstance->columnCount-1 &&
				GetValueAtIndex(i,c+1) == EMPTY_VALUE )
			{
				c++;
				Ismoved = true;
			}
			if (c == this->GameBoardInstance->columnCount-1)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(i,c,cellValue);
			}
			else if (GetValueAtIndex(i,c+1) == cellValue)
			{
				score += cellValue*2;
				SetValueAtIndex(i,c+1,cellValue*2);
				SetValueAtIndex(i,j,EMPTY_VALUE);
				Ismoved = true;
			}
			else if (c != j)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(i,c,cellValue);
			}
		}
	}
	return Ismoved;
}

bool GameManager::Move_Left()
{
	bool Ismoved = false;
	for (int i = 0; i <this->GameBoardInstance->rowCount; i++)
	{
		for (int j = 1; j < this->GameBoardInstance->columnCount  ; j++)
		{
			int cellValue = GetValueAtIndex(i,j);
			if (cellValue == EMPTY_VALUE)
			{
				continue;
			}
			int c= j;
			while (c > 0 &&
				GetValueAtIndex(i,c-1) == EMPTY_VALUE )
			{
				c--;
				Ismoved = true;
			}
			if (c== 0)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(i,c,cellValue);
			}
			if (GetValueAtIndex(i,c-1) == cellValue)
			{
				score += cellValue*2;
				SetValueAtIndex(i,c-1,cellValue*2);
				SetValueAtIndex(i,j,EMPTY_VALUE);
				Ismoved = true;
			}
			else if ( c != j)
			{
				SetValueAtIndex(i,j,EMPTY_VALUE);
				SetValueAtIndex(i,c,cellValue);
			}
		}
	}
	return Ismoved;
}

void GameManager::GenerateNumberAtRandomPosition()
{
	int i,j;
	do
	{
		int r = rand() % 16;
		i = r/4;
		j = r%4;
	} while (this->GetValueAtIndex(i,j) != EMPTY_VALUE);

	int value = (rand() % 2 + 1) * 2; //gets Random value either 2 or 4
	this->GameBoardInstance->grid[i][j] = value;

	GameBoardInstance->Render(score);
}

int GameManager:: GetValueAtIndex(int i, int j)
{
	return this->GameBoardInstance->grid[i][j];
}

void GameManager:: SetValueAtIndex(int i, int j,int value)
{
	this->GameBoardInstance->grid[i][j] = value;
}

bool GameManager:: Check_GameOver()
{
	for (int i = 0; i < this->GameBoardInstance->rowCount; i++)
	{
		for (int j = 0; j < this->GameBoardInstance->columnCount; j++)
		{
			if (this->GameBoardInstance->grid[i][j] == EMPTY_VALUE)
			{
				return false;
			}
		}
	}
	return true;
}

bool GameManager:: GameOver()
{
	cout<<"GameOver!!"<<endl;
	cout<<"Play Again(Y/N)?"<<endl;
	char input = _getch();
	if(tolower(input) == 'y')
	{
		return true;
	}
	return false;
}