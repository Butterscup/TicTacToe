#include <iostream>
#include "TicTacToeBoard.h"

TicTacToeBoard::TicTacToeBoard()
{
	for (size_t x = 0; x < 4; x++)
	{
		for (size_t y = 0; y < 4; y++)
		{
			board[x][y] = ' ';
		}
	}
}

TicTacToeBoard::~TicTacToeBoard()
{
}

// Attempts to draw a letter on the board
// returns 0 on success
// returns 1 on invalid coordinate
// returns 2 if coordinate is already occupied
int TicTacToeBoard::drawLetter(char x, char y, char letter)
{
	switch (x)
	{
	case 'a':
	case 'b':
	case 'c':
		x = x - 'a' + 1;
		switch (y)
		{
		case '1':
		case '2':
		case '3':
			y = y - '1' + 1;
			if (board[y][x] != ' ')
			{
				return 2;
			}
			else
			{
				board[y][x] = letter;
				return 0;
			}
			
		default:
			return 1;
		}

	default:
		return 1;
	}
}

void TicTacToeBoard::printBoard()
{
	using namespace std;

	cout << "  +-+-+-+" << endl;
	cout << "  |a|b|c|" << endl;
	cout << "+-+-+-+-+" << endl;
	cout << "|1|" << board[1][1] << "|" << board[1][2] << "|" << board[1][3] << "|" << endl;
	cout << "+-+-+-+-+" << endl;
	cout << "|2|" << board[2][1] << "|" << board[2][2] << "|" << board[2][3] << "|" << endl;
	cout << "+-+-+-+-+" << endl;
	cout << "|3|" << board[3][1] << "|" << board[3][2] << "|" << board[3][3] << "|" << endl;
	cout << "+-+-+-+-+" << endl;
}

char TicTacToeBoard::getWinner()
{
	if (board[1][1] != ' ')
	{
		if (board[1][1] == board[1][2] && board[1][1] == board[1][3])
		{
			return board[1][1];
		}
		if (board[1][1] == board[2][1] && board[1][1] == board[3][1])
		{
			return board[1][1];
		}
		if (board[1][1] == board[2][2] && board[1][1] == board[3][3])
		{
			return board[1][1];
		}
	}

	if (board[2][1] != ' ')
	{
		if (board[2][1] == board[2][2] && board[2][1] == board[2][3])
		{
			return board[2][1];
		}
	}

	if (board[3][1] != ' ')
	{
		if (board[3][1] == board[3][2] && board[3][1] == board[3][3])
		{
			return board[3][1];
		}
		if (board[3][1] == board[2][2] && board[3][1] == board[1][3])
		{
			return board[3][1];
		}
	}

	if (board[1][2] != ' ')
	{
		if (board[1][2] == board[2][2] && board[1][2] == board[3][2])
		{
			return board[1][2];
		}
	}

	if (board[1][3] != ' ')
	{
		if (board[1][3] == board[2][3] && board[1][3] == board[3][3])
		{
			return board[1][3];
		}
	}

	return ' ';
}
