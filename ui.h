#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

using namespace std;

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

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // дескриптор консоли
int MenuIndex;
char menu_items[menu_size][30]={"Init students' records", "View students' list", "Save students' records", "Process list", "Delete students' records"};
char status_str[status_len] = "Use arrows for navigation, Enter for activation and Esc for exit.";


void GotoXY(int x, int y);
void ShowHideCursor(int state);
void PrintMenu (int MenuIndex);
void PrintStatus(char *);


//-----------------------------------------------------------------------------------'

void PrintStatus(char * str){
    GotoXY(1,24);
    SetConsoleTextAttribute(hConsole, (WORD) ((Black<< 4) | DarkGray)); // setting back standard colors
    cout << str;
}

void PrintMenu (int MenuIndex){

    system("cls");
    GotoXY(0,0);

    for (int j=1; j<=menu_size; ++j){
        if (j==MenuIndex) {
            SetConsoleTextAttribute(hConsole, (WORD) ((LightGray << 4) | Cyan));
        }
        else {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black<< 4) | White));
        }
        cout << menu_items[j-1] << endl;
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



#endif // UI_H_INCLUDED
