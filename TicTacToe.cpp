#include "TicTacToe.h"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe(char _playerOneSymbol, char _playerTwoSymbol) :playerSymbols{ {_playerOneSymbol},{_playerTwoSymbol} }
{
	currentPlayerTurn = 0;
	filledPositions = 0;
	clearBoard();
}


TicTacToe::~TicTacToe()
{
}

void TicTacToe::clearBoard()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			board[i][j] = ' ';
		}
	}
}

void TicTacToe::printBoard()
{
	cout << std::endl;
	cout << "-----------------\n";
	cout << " * | 1 | 2 | 3 |\n";
	for (int i = 0; i < 3;++i)
	{
		cout << "-----------------\n";
		cout << " "<<i+1 << " | " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " | " << endl;
	 }
	cout << "-----------------\n";
}

bool TicTacToe::processMove(int _row,int _column)
{
	_row -= 1;
	_column -= 1;

	if (_row > 2 || _row < 0)
	{
		cout << "INVALID ROW! " << endl;
		return false;
	}

	if (_column > 2 || _column < 0)
	{
		cout << "INVALID COLUMN! " << endl;
		return false;
	}

	if (board[_row][_column] == ' ')
	{
		board[_row][_column] = playerSymbols[currentPlayerTurn];
		++filledPositions;
		return true;
	}
	cout << "THERE IS ALREADY AN ELEMENT AT THE POSITION" << endl;
	return false;
}

void TicTacToe::updateCurrentPlayer()
{
	currentPlayerTurn = (currentPlayerTurn == 1) ? 0 : 1;
	cout << "Player " << currentPlayerTurn + 1 << "'s turn" << endl;
}

bool TicTacToe::checkWin()
{
	for (int i = 0; i < 3; ++i)
	{
		if (checkRow(i) >= 3)
			return true;
		if (checkColumn(i) >= 3)
			return true;
	}
	if (checkDiagonal() >= 3)
		return true;

	return false;
}

int TicTacToe::checkRow(int row)
{
	char _currentPlayer = playerSymbols[currentPlayerTurn];
	int connected = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (board[row][i] == _currentPlayer)
			++connected;
		else if (board[row][i] == ' ')
			return connected;
	}
	return connected;
}

int TicTacToe::checkColumn(int column)
{
	char _currentPlayer = playerSymbols[currentPlayerTurn];
	int connected = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (board[i][column] == _currentPlayer)
			++connected;
		else if (board[i][column] == ' ')
			return connected;
	}
	return connected;
}

int TicTacToe::checkDiagonal()
{
	char _currentPlayer = playerSymbols[currentPlayerTurn];
	if ((board[0][0] == _currentPlayer) && (board[1][1] == _currentPlayer) && (board[2][2] == _currentPlayer))
		return 3;

	if ((board[0][2] == _currentPlayer) && (board[1][1] == _currentPlayer) && (board[2][0] == _currentPlayer))
		return 3;

	return 0;
}
