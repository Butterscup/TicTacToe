#include <iostream>
#include "TicTacToeBoard.h"
using namespace std;

int main()
{
	TicTacToeBoard board;
	char currentPlayer = 'X';
	string coordinate;

	cout << "###################################################" << endl;
	cout << "## Welcome to Tic-Tac-Toe: Command-line Edition! ##" << endl;
	cout << "###################################################" << endl << endl;

	do
	{
		cout << "Player " << currentPlayer << ", it's your turn! Here's the board!" << endl;
		board.printBoard();
		cout << "Pick a coordinate: ";
		cin >> coordinate;
		cout << endl;
		if (!cin.good())
		{
			cerr << "Something went wrong! Sorry :(" << endl;
			return 1;
		}

		if (coordinate.length() != 2)
		{
			cout << "############" << endl;
			cout << "## Error! ##" << endl;
			cout << "############" << endl;
			cout << "The coordinate should be two letters in length. For example: a1" << endl;
			cout << "Please try again!" << endl << endl;
			continue;
		}

		switch (board.drawLetter(coordinate[0], coordinate[1], currentPlayer))
		{
		case 0:
			switch (currentPlayer)
			{
			case 'X':
				currentPlayer = 'O';
				continue;
			case 'O':
				currentPlayer = 'X';
				continue;
			default:
				cerr << "Something went wrong! Sorry :(" << endl;
				return 1;
			}

		case 1:
			cout << "############" << endl;
			cout << "## Error! ##" << endl;
			cout << "############" << endl;
			cout << "Invalid coordinate given! Try again with something like this: a1" << endl << endl;
			continue;

		case 2:
			cout << "############" << endl;
			cout << "## Error! ##" << endl;
			cout << "############" << endl;
			cout << "That coordinate is already taken! Please try another." << endl << endl;
			continue;

		default:
			cerr << "Something went wrong! Sorry :(" << endl;
			return 1;
		}
	} while (board.getWinner() == ' ');

	switch (currentPlayer)
	{
	case 'X':
		currentPlayer = 'O';
		break;

	case 'O':
		currentPlayer = 'X';
		break;

	default:
		cerr << "Something went wrong! Sorry :(" << endl;
		return 1;
	}

	cout << "####################" << endl;
	cout << "## Player " << currentPlayer << " wins! ##" << endl;
	cout << "####################" << endl;

	board.printBoard();
	
	return 0;
}
