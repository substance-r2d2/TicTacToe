#include <iostream>
#include <string>
#include "TicTacToe.h"

using namespace std;

void main()
{
	string player1, player2;
	cout << "Enter player 1 symbol : ";
	cin >> player1;
	cout << "Enter player 2 symbol : ";
	cin >> player2;
	TicTacToe game(player1[0],player2[0]);
	game.printBoard();
	cout << "PLAYER 1's turn" << endl;

	while (true)
	{
		int row, column;
		do
		{
			cout << "Enter Row : " ;
			cin >> row;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(256,'\n');
				cout << "GIVEN ROW IS NOT A NUMBER, ENTER ROW AGAIN" << endl;
				cin >> row;
			}
			cout << "Enter Column : ";
			cin >> column;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(256, '\n');
				cout << "GIVEN COLUMN IS NOT A NUMBER, ENTER COLUMN AGAIN" << endl;
				cin >> column;
			}
		} while (!game.processMove(row, column));
		game.printBoard();
		if (game.checkWin())
			break;
		else
			game.updateCurrentPlayer();
	}

	system("PAUSE");
}
