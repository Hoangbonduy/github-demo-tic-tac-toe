#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <time.h>
#include "AI.h"
#include "Performance.h"
#include "Vietnamese.h"
using namespace std;
#define _WIN32_WINNT 0x0601
bool English = true; // You can change the default langugage
char board[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char player = 'X';
int Run() {
    //EnterVietnamese();
	srand(time(NULL));
    manhinhchinh: // main menu
	menu();
	if (!English) wcout << L"Nhập lựa chọn của bạn vào đây: ";
	else if (English) wcout << L"Enter your selection in here: ";
	long long next;
	wcin >> next;
	while (next != 1 && next != 2 && next != 3 && next != 4 && next != 5 && next != 6)
	{
		if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
		else if (English) wcout << endl << L"You are wrong. Please try again: ";
		///////////////////////////////////////////////
		wcin >> next;
	}
	if (next == 1)
	{
		system("cls");
	choilai:
		int count = 0;
		while (true)
		{
			draw();
			count++;
			char check = checkwin();
			if (check == 'X')
			{
				if (!English) wcout << L"X thắng" << endl;
				else if (English) wcout << "X win" << endl;
				/////////////////////////////////////
				long long EndGameSelecction;
				if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
				else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";

				wcin >> EndGameSelecction;
				while (EndGameSelecction != 1 && EndGameSelecction != 0)
				{
					if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
					else if (English) wcout << endl << L"You are wrong. Please try again: ";
					wcin >> EndGameSelecction;
				}
				if (EndGameSelecction == 1)
				{
					count = 0;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							board[i][j] = ' ';
						}
					}
					player = 'X';
					system("cls");
					goto choilai;
				}
				else if (EndGameSelecction == 0) {
					system("cls");
					goto manhinhchinh;
				}
				/////////////////////////////////////////////
			}
			else if (check == 'O')
			{
				if (!English) wcout << L"O thắng" << endl;
				else if (English) wcout << "O win" << endl;
				//////////////////////////////////
				long long EndGameSelecction;
				if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
				else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";
				wcin >> EndGameSelecction;
				while (EndGameSelecction != 1 && EndGameSelecction != 0)
				{
					if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
					else if (English) wcout << endl << L"You are wrong. Please try again: ";
					wcin >> EndGameSelecction;
				}
				if (EndGameSelecction == 1)
				{
					count = 0;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							board[i][j] = ' ';
						}
					}
					player = 'X';
					system("cls");
					goto choilai;
				}
				else if (EndGameSelecction == 0) {
					system("cls");
					goto manhinhchinh;
				}
				/////////////////////////////////////////////
			}
			else if (count == 10)
			{
				if (!English) wcout << L"Trận hòa" << endl;
				else if (English) wcout << "It's a draw" << endl;
				/////////////////////////////////////
				long long EndGameSelecction;
				if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
				else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";
				wcin >> EndGameSelecction;
				while (EndGameSelecction != 1 && EndGameSelecction != 0)
				{
					if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
					else if (English) wcout << endl << L"You are wrong. Please try again: ";
					wcin >> EndGameSelecction;
				}
				if (EndGameSelecction == 1)
				{
					count = 0;
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							board[i][j] = ' ';
						}
					}
					player = 'X';
					system("cls");
					goto choilai;
				}
				else if (EndGameSelecction == 0) exit(0);
				/////////////////////////////////////////////
			}
			select();
			change();
			system("cls");
		}
	}
	if (next == 2)
	{
		system("cls");

		/*
		if (English == false) {
			wcout << L"Đang ra mắt" << endl;
			wcout << L"Bấm phím bất kỳ để quay trở lại màn hình chính: ";
		}
		else {
			wcout << L"Comming soon" << endl;
			wcout << L"Enter any thing to go back to the main menu: ";
		}
		wstring fake;
		wcin >> fake;
		system("cls");
		goto manhinhchinh;
		*/

		if (!English) {
			wcout << endl << endl << endl << L"\t\t\t\Bạn chọn X hay O (1 là X, 2 là O, X luôn luôn đi trước): ";
		}
		else if (English) {
			wcout << endl << endl << endl << L"\t\t\t\You choose X or O (1 is X, 2 is O, X always go first): ";
		}
		long long ans;
		wcin >> ans;
		while (ans != 1 && ans != 2) {
			if (!English) {
				wcout << endl << L"Vui lòng nhập lại: ";
			}
			else wcout << endl << "Please enter again: ";
		}
		if (ans == 1) {
			system("cls");
		    choilai2:
			int count = 0;
			while (true) {
				draw();
				char check = checkwin();
				if (check == 'X')
				{
					if (!English) wcout << L"X thắng" << endl;
					else if (English) wcout << "X win" << endl;
					/////////////////////////////////////
					long long EndGameSelecction;
					if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
					else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";

					wcin >> EndGameSelecction;
					while (EndGameSelecction != 1 && EndGameSelecction != 0)
					{
						if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
						else if (English) wcout << endl << L"You are wrong. Please try again: ";
						wcin >> EndGameSelecction;
					}
					if (EndGameSelecction == 1)
					{
						count = 0;
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[i][j] = ' ';
							}
						}
						player = 'X';
						system("cls");
						goto choilai2;
					}
					else if (EndGameSelecction == 0) {
						system("cls");
						goto manhinhchinh;
					}
					/////////////////////////////////////////////
				}
				else if (check == 'O')
				{
					if (!English) wcout << L"O thắng" << endl;
					else if (English) wcout << "O win" << endl;
					//////////////////////////////////
					long long EndGameSelecction;
					if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
					else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";
					wcin >> EndGameSelecction;
					while (EndGameSelecction != 1 && EndGameSelecction != 0)
					{
						if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
						else if (English) wcout << endl << L"You are wrong. Please try again: ";
						wcin >> EndGameSelecction;
					}
					if (EndGameSelecction == 1)
					{
						count = 0;
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[i][j] = ' ';
							}
						}
						player = 'X';
						system("cls");
						goto choilai2;
					}
					else if (EndGameSelecction == 0) {
						system("cls");
						goto manhinhchinh;
					}
					/////////////////////////////////////////////
				}
				else if (count == 10)
				{
					if (!English) wcout << L"Trận hòa" << endl;
					else if (English) wcout << "It's a draw" << endl;
					/////////////////////////////////////
					long long EndGameSelecction;
					if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
					else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";
					wcin >> EndGameSelecction;
					while (EndGameSelecction != 1 && EndGameSelecction != 0)
					{
						if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
						else if (English) wcout << endl << L"You are wrong. Please try again: ";
						wcin >> EndGameSelecction;
					}
					if (EndGameSelecction == 1)
					{
						count = 0;
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[i][j] = ' ';
							}
						}
						player = 'X';
						system("cls");
						goto choilai2;
					}
					else if (EndGameSelecction == 0) exit(0);
					/////////////////////////////////////////////
				}
				select();
				change();
				///////Best Move///////////
				Move BestMove = findBestMove(board);
				board[BestMove.row][BestMove.col] = player;
				///////Best Move///////////
				change();
				system("cls");
			}
		}
		else if (ans == 2) {
			system("cls");
		    choilai3:
			int count = 0;
			while (true) {
				draw();
				char check = checkwin();
				if (check == 'X')
				{
					if (!English) wcout << L"X thắng" << endl;
					else if (English) wcout << "X win" << endl;
					/////////////////////////////////////
					long long EndGameSelecction;
					if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
					else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";

					wcin >> EndGameSelecction;
					while (EndGameSelecction != 1 && EndGameSelecction != 0)
					{
						if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
						else if (English) wcout << endl << L"You are wrong. Please try again: ";
						wcin >> EndGameSelecction;
					}
					if (EndGameSelecction == 1)
					{
						count = 0;
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[i][j] = ' ';
							}
						}
						player = 'X';
						system("cls");
						goto choilai3;
					}
					else if (EndGameSelecction == 0) {
						system("cls");
						goto manhinhchinh;
					}
					/////////////////////////////////////////////
				}
				else if (check == 'O')
				{
					if (!English) wcout << L"O thắng" << endl;
					else if (English) wcout << "O win" << endl;
					//////////////////////////////////
					long long EndGameSelecction;
					if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
					else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";
					wcin >> EndGameSelecction;
					while (EndGameSelecction != 1 && EndGameSelecction != 0)
					{
						if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
						else if (English) wcout << endl << L"You are wrong. Please try again: ";
						wcin >> EndGameSelecction;
					}
					if (EndGameSelecction == 1)
					{
						count = 0;
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[i][j] = ' ';
							}
						}
						player = 'X';
						system("cls");
						goto choilai3;
					}
					else if (EndGameSelecction == 0) {
						system("cls");
						goto manhinhchinh;
					}
					/////////////////////////////////////////////
				}
				else if (count == 10)
				{
					if (!English) wcout << L"Trận hòa" << endl;
					else if (English) wcout << "It's a draw" << endl;
					/////////////////////////////////////
					long long EndGameSelecction;
					if (!English) wcout << L"Trận đấu đã kết thúc. Bạn có muốn chơi tiếp? Gõ 1 là có còn 0 là không: ";
					else if (English) wcout << "The game is over. Do you want to play again? Enter 1 is yes and 0 is no: ";
					wcin >> EndGameSelecction;
					while (EndGameSelecction != 1 && EndGameSelecction != 0)
					{
						if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
						else if (English) wcout << endl << L"You are wrong. Please try again: ";
						wcin >> EndGameSelecction;
					}
					if (EndGameSelecction == 1)
					{
						count = 0;
						for (int i = 0; i < 3; i++)
						{
							for (int j = 0; j < 3; j++)
							{
								board[i][j] = ' ';
							}
						}
						player = 'X';
						system("cls");
						goto choilai3;
					}
					else if (EndGameSelecction == 0) exit(0);
					/////////////////////////////////////////////
				}
				///////Best Move///////////
				Move BestMove = findBestMove(board);
				board[BestMove.row][BestMove.col] = player;
				///////Best Move///////////
				change();
				select();
				change();
				system("cls");
			}
		}
		if (next == 3)
		{
			system("cls");
			//////////////////////////
			if (!English)
			{
				wcout << L" - Giới thiệu: " << endl;
				wcout << L"+) Tic-tac-toe là một trò chơi phổ biến dùng viết trên bàn cờ giấy có chín ô, 3x3.\n";
				wcout << L"+) Hai người chơi, người dùng ký hiệu O, người kia dùng ký hiệu X, lần lượt điền ký hiệu của mình vào các ô.\n";
				wcout << L"+) Người thắng là người thể tạo được đầu tiên một dãy ty ký hiệu của mình, ngang dọc hay chéo đều được.\n";
			}
			else if (English)
			{
				wcout << L"Tic-tac-toe (American English), noughts and crosses (British English), or Xs and Os is a paper-and-pencil game for two players, X and O, who take turns marking the spaces in a 3×3 grid.\n";
				wcout << L"The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row is the winner.\n";
			}
			////////////////////////////
			if (!English)
			{
				wcout << L" - Hướng dẫn: " << endl;
				wcout << L"+) Nhập tọa độ của điểm mà bạn muốn đánh." << endl;
				wcout << L"+) Ví dụ:\n";
			}
			else if (English)
			{
				wcout << L" - How to play: " << endl;
				wcout << L"+) Enter the coordinates of the point you want to play." << endl;
				wcout << L"+) Example:\n";
			}
			wcout << "    0     1     2  \n";
			wcout << "  " << "     |     |     |\n";
			wcout << "0 " << "     |     |     |\n";
			wcout << "  " << "_____|_____|_____|\n";
			wcout << "  " << "     |     |     |\n";
			wcout << "1 " << "     |     |     |\n";
			wcout << "  " << "_____|_____|_____|\n";
			wcout << "  " << "     |     |     |\n";
			wcout << "2 " << "     |  *  |     |\n";
			wcout << "  " << "_____|_____|_____|\n";
			if (!English)
			{
				wcout << L"+) Nếu Bạn muốn đánh vào điểm có dấu * thì nhập: 2 1\n";
				wcout << L"+) Kết quả sẽ thành: " << endl;
			}
			else if (English)
			{
				wcout << L"+) If You want to play in point which have *, enter 2 1\n";
				wcout << L"+) The result is: " << endl;
			}
			wcout << "    0     1     2  \n";
			wcout << "  " << "     |     |     |\n";
			wcout << "0 " << "     |     |     |\n";
			wcout << "  " << "_____|_____|_____|\n";
			wcout << "  " << "     |     |     |\n";
			wcout << "1 " << "     |     |     |\n";
			wcout << "  " << "_____|_____|_____|\n";
			wcout << "  " << "     |     |     |\n";
			wcout << "2 " << "     |  X  |     |\n";
			wcout << "  " << "_____|_____|_____|\n";
			////////////////////////////
			if (English == true) {
				wcout << "Type anything to go back to the main menu: ";
			}
			else {
				wcout << L"Bấm phím bất kỳ để quay về màn hình chính: ";
			}
			wstring temp;
			wcin >> temp;
			system("cls");
			goto manhinhchinh;
		}
		if (next == 4)
		{
			system("cls");
			////////////////////////////////
			if (!English)
			{
				wcout << L"Phiên bản: 1.0.00" << endl;
				wcout << L"Lịch sử các phiên bản: " << endl;
				wcout << L"+) Phiên bản 1.0.00: " << endl;
				wcout << L"  - Phiên bản đầu tiên." << endl;
			}
			else if (English)
			{
				wcout << L"Version: 1.0.00" << endl;
				wcout << L"Version history: " << endl;
				wcout << L"+) Version 1.0.00: " << endl;
				wcout << L"   - The first version." << endl;
			}
			//////////////////////////////////
			if (English == true) {
				wcout << "Type anything to go back to the main menu: ";
			}
			else {
				wcout << L"Bấm phím bất kỳ để quay về màn hình chính: ";
			}
			wstring temp;
			wcin >> temp;
			system("cls");
			goto manhinhchinh;
		}
		if (next == 5)
		{
			if (English == true)
			{
				system("cls");
				wcout << "1 - Vietnamese\n";
				wcout << "2 - Back to the main menu\n";
				wcout << "Which languages do you want to change: ";
				long long selection_language;
				wcin >> selection_language;
				while (selection_language != 1 && selection_language != 2)
				{
					wcout << endl << L"You are wrong. Please try again: ";
					wcin >> selection_language;
				}
				if (selection_language == 1) English = false;
				if (selection_language == 2)
				{
					system("cls");
					goto manhinhchinh;
				}
				wcout << L"Chuyển ngôn ngữ thành công.\n";
				wcout << L"Gõ bất cứ thứ gì để trở về màn hình chính: ";
				wstring temp;
				wcin >> temp;
				system("cls");
				goto manhinhchinh;
			}
			if (English == false)
			{
				system("cls");
				wcout << L"1 - Tiếng Anh\n";
				wcout << L"2 - Quay trở về màn hình chính\n";
				wcout << L"Nhập ngôn ngữ mà bạn muốn chọn: ";
				long long selection_language;
				wcin >> selection_language;
				while (selection_language != 1 && selection_language != 2)
				{
					wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
					wcin >> selection_language;
				}
				if (selection_language == 1) English = true;
				if (selection_language == 2)
				{
					system("cls");
					goto manhinhchinh;
				}
				wcout << "Change the language successfully.\n";
				wcout << "Type anything to go back the main menu: ";
				wstring temp;
				wcin >> temp;
				system("cls");
				goto manhinhchinh;
			}
		}
		if (next == 6) {
			system("cls");
			exit(0);
		}
		return 0;
	}
}
