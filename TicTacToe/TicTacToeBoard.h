#pragma once
#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

class TicTacToeBoard
{
public:
	TicTacToeBoard();
	~TicTacToeBoard();

private:
	char board[4][4];

private:

public:
	void printBoard();
	int drawLetter(char x, char y, char letter);
	char getWinner();
};

#endif // !TIC_TAC_TOE_BOARD_H
