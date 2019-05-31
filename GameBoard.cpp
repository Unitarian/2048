#include "GameBoard.h"
#include "iostream"
#include "conio.h"
 #include <cstdlib>
 #include<math.h>
using namespace std;

GameBoard::GameBoard(int r, int c): Board(r,c)
{

}

GameBoard::~GameBoard()
{
	
}

void GameBoard:: Render(int score)
{		 
	Board:: Render(score);
	system("cls");
	cout<<"************************************************"<<endl;
	cout<<"***** 2048 Game Developed by Umair Maqsood *****"<<endl;
	cout<<"************************************************"<<endl;
	cout<<"SCORE: "<<score<<endl<<endl;
	char board[17][29];
	for(int i = 0; i < 17; i++)
	{
		for(int j = 0; j < 29; j++)
		{
			if( i%4 == 0 || j%7 == 0 )
			{
				board[i][j] = '.';
			}
			else
			{
                board[i][j] = ' ';
			}
	    }
	}
	for(int i = 0; i < 17; i++)
	{
		for(int j = 0; j < 29; j++)
		{
			switch (i)
			{
			case 2 :
				{
					switch (j)
					{
					case 2:
						{
							int digits = GetNumberOfDigits( this->grid[0][0]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[0][0];
							j += digits-1;
						}
						break;
					case 9:
						{
							int digits = GetNumberOfDigits( this->grid[0][1]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[0][1];
							j += digits-1;
						}
						break;
					case 16:
						{
							int digits = GetNumberOfDigits( this->grid[0][2]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[0][2];
							j += digits-1;
						}
						break;
					case 23:
						{
							int digits = GetNumberOfDigits( this->grid[0][3]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[0][3];
							j += digits-1;
						}
						break;
					default:	
						cout<<board[i][j];
						break;
					}
				}
				break;


			case 6 :
				{
					switch (j)
					{
					case 2:
						{
							int digits = GetNumberOfDigits( this->grid[1][0]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[1][0];
							j += digits-1;
						}
						break;
					case 9:
						{
							int digits = GetNumberOfDigits( this->grid[1][1]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[1][1];
							j += digits-1;
						}
						break;
					case 16:
						{
							int digits = GetNumberOfDigits( this->grid[1][2]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[1][2];
							j += digits-1;
						}
						break;
					case 23:
						{
							int digits = GetNumberOfDigits( this->grid[1][3]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[1][3];
							j += digits-1;
						}
						break;
					default:	
						cout<<board[i][j];
						break;
					}
				}
				break;

			case 10 :
				{
					switch (j)
					{
					case 2:
						{
							int digits = GetNumberOfDigits( this->grid[2][0]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[2][0];
							j += digits-1;
						}
						break;
					case 9:
						{
							int digits = GetNumberOfDigits( this->grid[2][1]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[2][1];
							j += digits-1;
						}
						break;
					case 16:
						{
							int digits = GetNumberOfDigits( this->grid[2][2]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[2][2];
							j += digits-1;
						}
						break;
					case 23:
						{
							int digits = GetNumberOfDigits( this->grid[2][3]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[2][3];
							j += digits-1;
						}
						break;
					default:	
						cout<<board[i][j];
						break;
					}
				}
				break;

			case 14 :
				{
					switch (j)
					{
					case 2:
						{
							int digits = GetNumberOfDigits( this->grid[3][0]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[3][0];
							j += digits-1;
						}
						break;
					case 9:
						{
							int digits = GetNumberOfDigits( this->grid[3][1]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[3][1];
							j += digits-1;
						}
						break;
					case 16:
						{
							int digits = GetNumberOfDigits( this->grid[3][2]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[3][2];
							j += digits-1;
						}
						break;
					case 23:
						{
							int digits = GetNumberOfDigits( this->grid[3][3]);
							if (digits == 0)
							{
								cout<<board[i][j];
								continue;
							}
							cout<< this->grid[3][3];
							j += digits-1;
						}
						break;
					default:	
						cout<<board[i][j];
						break;
					}
				}
				break;
			default:
				cout<<board[i][j];
				break;
			}
		}
		cout<<endl;
	}
}

unsigned GameBoard:: GetNumberOfDigits(unsigned i)
{
	int value = (i != EMPTY_VALUE) ? (int) log10 ((double) i) + 1 : 0;
    return value;
}