#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <time.h>
using namespace std;
char board[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char player = 'X';
void draw()
{
	wcout << "    0     1     2  \n";
	wcout << "  " << "     |     |     |\n";
	wcout << "0 " << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |\n";
	wcout << "  " << "_____|_____|_____|\n";
	wcout << "  " << "     |     |     |\n";
	wcout << "1 " << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |\n";
	wcout << "  " << "_____|_____|_____|\n";
	wcout << "  " << "     |     |     |\n";
	wcout << "2 " << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |\n";
	wcout << "  " << "_____|_____|_____|\n";
}
void select()
{
	if (false) wcout << L"Lượt của người chơi " << "[" << player << "]" << L" (cột, hàng): ";
	else if (true) wcout << L"Turn of the player " << "[" << player << "]" << L" (row, line): ";
	///////////////////////////////////////////////
	long long choosex, choosey;
	wcin >> choosex >> choosey;
	while ((choosex != 0 && choosex != 1 && choosex != 2) || (choosey != 0 && choosey != 1 && choosey != 2))
	{
		if (false) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
		else if (true) wcout << endl << L"You are wrong. Please try again: ";
		////////////////////////////////////////
		wcin >> choosex >> choosey;
	}
	while (board[choosex][choosey] == 'X' || board[choosex][choosey] == 'O')
	{
		if (false) wcout << endl << L"Ô này đã đánh. Vui lòng nhập lại: ";
		else if (true) wcout << endl << L"This have X or O. Please try again: ";
		//////////////////////////////////
		wcin >> choosex >> choosey;
	}
	board[choosex][choosey] = player;
}
void change()
{
	if (player == 'X')
		player = 'O';
	else player = 'X';
}
char checkwin()
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		return 'X';
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		return 'X';
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') // column
		return 'X';
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') // column
		return 'X';
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') // column
		return 'X';
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		return 'X';
	if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
		return 'X';
	///////////////////////////
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		return 'O';
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		return 'O';
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') // column
		return 'O';
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') // column
		return 'O';
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') // column
		return 'O';
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		return 'O';
	if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
		return 'O';
	return '?';
}