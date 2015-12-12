#pragma once
class TicTacToe
{
private:
	char board[3][3];
	char playerSymbols[2];
	int currentPlayerTurn;
	int filledPositions;
public:
	TicTacToe(char _playerOneSymbol,char _playerTwoSymbol);
	~TicTacToe();
	void clearBoard();
	void printBoard();
	void updateCurrentPlayer();
	int checkRow(int row);
	int checkColumn(int column);
	int checkDiagonal();
	bool processMove(int row,int column);
	bool checkWin();
};

