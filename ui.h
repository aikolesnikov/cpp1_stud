#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include <Windows.h>

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

const int status_len = 80;
const int menu_size = 5;

// глобальные переменные лучше сделать локальными
extern HANDLE hConsole; // дескриптор консоли
extern int MenuIndex;

const char menu_items[menu_size][30]={"Init students' records", "View students' list", "Save students' records", "Process list", "Delete students' records"};
const char status_str[status_len] = "Use arrows for navigation, Enter for activation and Esc for exit.";


void GotoXY(int x, int y);
void ShowHideCursor(int state);
void PrintMenu (int MenuIndex);
void PrintStatus(const char *);


//-----------------------------------------------------------------------------------'
// реализация функций должна быть в файле .срр

#endif // UI_H_INCLUDED
