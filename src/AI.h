#include "AI.cpp"

bool isMovesLeft(char board[3][3]);

int evaluate(char b[3][3]);

int minimax(char board[3][3], int depth, bool isMax);

Move findBestMove(char board[3][3]);