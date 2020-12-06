#include <algorithm>
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <time.h>
using namespace std;
struct Move
{
	int row, col;
};

char playerx = 'X', opponent = 'O';

bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] == ' ')
				return true;
	return false;
}

int evaluate(char b[3][3])
{
	for (int row = 0; row < 3; row++)
	{
		if (b[row][0] == b[row][1] &&
			b[row][1] == b[row][2])
		{
			if (b[row][0] == playerx)
				return +10;
			else if (b[row][0] == opponent)
				return -10;
		}
	}

	for (int col = 0; col < 3; col++)
	{
		if (b[0][col] == b[1][col] &&
			b[1][col] == b[2][col])
		{
			if (b[0][col] == playerx)
				return +10;

			else if (b[0][col] == opponent)
				return -10;
		}
	}

	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == playerx)
			return +10;
		else if (b[0][0] == opponent)
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == playerx)
			return +10;
		else if (b[0][2] == opponent)
			return -10;
	}

	return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	if (score == 10)
		return score;

	if (score == -10)
		return score;

	if (isMovesLeft(board) == false)
		return 0;

	if (isMax)
	{
		int best = -1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = playerx;

					best = max(best, minimax(board, depth + 1, !isMax));

					board[i][j] = ' ';
				}
			}
		}
		return best;
	}

	else
	{
		int best = 1000;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '_')
				{
					board[i][j] = opponent;

					best = min(best,
						minimax(board, depth + 1, !isMax));

					board[i][j] = ' ';
				}
			}
		}
		return best;
	}
}

Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
			{
				board[i][j] = playerx;

				int moveVal = minimax(board, 0, false);

				board[i][j] = ' ';

				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}
	return bestMove;
}