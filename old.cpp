// this project is both in Vietnamese and English. The default language is English and you can change the language.
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <string>
using namespace std;
bool English = true;
/////////////////Tic tac toe main game////////////////////////////
void EnterVietnamese()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	SetConsoleTitleW(L"TIK TAC TOE");
	HANDLE hdlConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX consoleFont;
	consoleFont.cbSize = sizeof(consoleFont);
	GetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
	memcpy(consoleFont.FaceName, L"Consolas", sizeof(consoleFont.FaceName));
	SetCurrentConsoleFontEx(hdlConsole, FALSE, &consoleFont);
}
/////////////////////////////Menu/////////////////////////////////////
auto menu()
{
	if (!English)
	{
		wcout << L"Ngôn ngữ hiện tại đang là: Tiếng Việt" << endl;
		wcout << endl << endl << endl << L"\t\t\t	TIK TAC TOE" << endl;
		wcout << endl;
		wcout << L"\t\t\t\t    MENU" << endl;
		wcout << endl << L"\t\t\t\t1.Chơi" << endl;
		wcout << endl << L"\t\t\t\t2.Hướng dẫn và giới thiệu" << endl;
		wcout << endl << L"\t\t\t\t3.Phiên bản và lịch sử phiên bản" << endl;
		wcout << endl << L"\t\t\t\t4.Thay đổi ngôn ngữ" << endl;
		wcout << endl << L"\t\t\t\t5.Thoát" << endl;
	}
	else if (English)
	{
		wcout << "The current language is: English.\n";
		wcout << endl << endl << endl << L"\t\t\t	TIK TAC TOE" << endl;
		wcout << endl;
		wcout << L"\t\t\t\t    MENU" << endl;
		wcout << endl << L"\t\t\t\t1.Play" << endl;
		wcout << endl << L"\t\t\t\t2.How to play and Introduction" << endl;
		wcout << endl << L"\t\t\t\t3.Version and Version History" << endl;
		wcout << endl << L"\t\t\t\t4.Change language" << endl;
		wcout << endl << L"\t\t\t\t5.Exit" << endl;
	}
}
char board[3][3] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
char player = 'X';
void draw()
{
	wcout << "    0     1     2  \n";
	wcout << "  " <<"     |     |     |\n";
	wcout << "0 " <<"  "<< board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |\n";
	wcout << "  " <<"_____|_____|_____|\n";
	wcout << "  " <<"     |     |     |\n";
	wcout << "1 " << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |\n";
	wcout << "  " <<"_____|_____|_____|\n";
	wcout << "  " <<"     |     |     |\n";
	wcout << "2 " << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |\n";
	wcout << "  " <<"_____|_____|_____|\n";
}
void select()
{
	if (!English) wcout << L"Lượt của người chơi " << "[" << player << "]" << L" (cột, hàng): ";
	else if (English) wcout << L"Turn of the player " << "[" << player << "]" << L" (row, line): ";
	///////////////////////////////////////////////
	long long choosex, choosey;
	wcin >> choosex >> choosey;
	while ((choosex != 0 && choosex != 1 && choosex != 2) || (choosey != 0 && choosey != 1 && choosey != 2))
	{
		if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
		else if (English) wcout << endl << L"You are wrong. Please try again: ";
		////////////////////////////////////////
		wcin >> choosex >> choosey;
	}
	while (board[choosex][choosey] == 'X' || board[choosex][choosey] == 'O')
	{
		if (!English) wcout << endl << L"Ô này đã đánh. Vui lòng nhập lại: ";
		else if (English) wcout << endl << L"This have X or O. Please try again: ";
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
int main()
{
	EnterVietnamese();
	manhinhchinh: // main menu
	menu();
	if (!English) wcout << L"Nhập lựa chọn của bạn vào đây: ";
	else if (English) wcout << L"Enter your selection in here: ";
	long long next;
	wcin >> next;
	while (next != 1 && next != 2 && next != 3 && next != 4)
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
				else if (EndGameSelecction == 0) exit(0);
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
				else if (EndGameSelecction == 0) exit(0);
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
		if (!English) wcout << L"Bấm 1 để quay về màn hình chính, bấm 0 để thoát: ";
		else if (English) wcout << L"Enter 1 to go back to the main menu, enter 0 to exit: ";
		int a;
		wcin >> a;
		while (a != 1 && a != 0)
		{
			if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
			else if (English) wcout << endl << L"You are wrong. Please try again: ";
			wcin >> a;
		}
		system("cls");
		if (a == 1) goto manhinhchinh;
		if (a == 0) exit(0);
	}
	if (next == 3)
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
		if (!English) wcout << L"Bấm 1 để quay về màn hình chính, bấm 0 để thoát: ";
		else if (English) wcout << L"Enter 1 to go back to the main menu, enter 0 to exit: ";
		int a;
		wcin >> a;
		while (a != 1 && a != 0)
		{
			if (!English) wcout << endl << L"Bạn đã nhập sai. Vui lòng nhập lại: ";
			else if (English) wcout << endl << L"You are wrong. Please try again: ";
			wcin >> a;
		}
		system("cls");
		if (a == 1) goto manhinhchinh;
		if (a == 0) exit(0);
	}
	if (next == 4)
	{
		if (English == true)
		{
			system("cls");
			wcout << "1 - Vietnamese\n";
			wcout << "2 - Back to the main menu\n";
			wcout << "Which languages do you want to change: ";
			long long selection_language;
			wcin >> selection_language;
			while (selection_language != 1 && selection_language!=2)
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
	if (next == 5) exit(0);
	return 0;
}