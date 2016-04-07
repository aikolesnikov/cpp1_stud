#include <Windows.h>
#include <iostream>
#include "ui.h"
using namespace std;


void PrintStatus(const char * str) {
	GotoXY(1, 24);
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | DarkGray)); // setting back standard colors
	cout << str;
}

void PrintMenu(int MenuIndex) {

	system("cls");
	GotoXY(0, 0);

	for (int j = 1; j <= menu_size; ++j) {
		if (j == MenuIndex) {
			SetConsoleTextAttribute(hConsole, (WORD)((LightGray << 4) | Cyan));
		}
		else {
			SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
		}
		cout << menu_items[j - 1] << endl;
	}
}

void GotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(hConsole, coord);
}

void ShowHideCursor(int state)
{
	CONSOLE_CURSOR_INFO info;
	// info.dwSize = 100;
	info.bVisible = state;
	SetConsoleCursorInfo(hConsole, &info);
}
