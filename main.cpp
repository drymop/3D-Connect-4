#include<iomanip>
#include<iostream>

#include "Board.h"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using connect4_3d::BoardState;

void draw(const BoardState& state);

int main(int argc, char const *argv[])
{

	BoardState state;
	state.curr_player = 0;
	state.boards[0] = state.boards[1] = 0;

	while (!connect4_3d::isWinning(state))
	{
		draw(state);
		cout << "Player " << (state.curr_player + 1) << " move: ";
		int move;
		cin >> move;
		state = connect4_3d::move(state, move);
	}
	draw(state);
	cout << "Player " << (2 - state.curr_player) << " wins!" << endl;

	return 0;
}

void draw(const BoardState& state)
{
	for (int h = 3; h >= 1; h--)
	{
		for (int r = 3; r >= 0; r--)
		{
			int offset = 2 * r + 1;
			cout << setw(offset + 1) << "";
			cout << "-----------------" << endl;
			cout << setw(offset) << "";
			for (int c = 0; c < 4; c++)
			{
				cout << "/";
				if (state.boards[0] >> (h*16+r*4+c) & 1UL)
					cout << " x ";
				else if (state.boards[1] >> (h*16+r*4+c) & 1UL)
					cout << " o ";
				else
					cout << "   ";
			}
			cout << "/" << endl;
		}
		cout << "-----------------" << endl;	
	}

	for (int r = 3; r >= 0; r--)
	{
		int offset = 2 * r + 1;
		cout << setw(offset + 1) << "";
		cout << "-----------------" << setw(10) << "" << "-----------------" << endl;

		cout << setw(offset) << "";
		for (int c = 0; c < 4; c++)
		{
			cout << "/";
			if (state.boards[0] >> (r*4+c) & 1UL)
				cout << " x ";
			else if (state.boards[1] >> (r*4+c) & 1UL)
				cout << " o ";
			else
				cout << "   ";
		}
		cout << "/" << setw(10) << "";

		for (int c = 0; c < 4; c++)
		{
			cout << "/" << setw(2) << (r*4+c) << " ";
		}
		cout << "/" << endl;
	}
	cout << "-----------------" << setw(10) << "" << "-----------------" << endl;
}