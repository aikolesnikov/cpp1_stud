#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define MTOP if (MenuIndex==1) {MenuIndex=3;} else {MenuIndex-=1;};
#define MDOWN if (MenuIndex==3) {MenuIndex=1;} else {MenuIndex+=1;};
#define MLEFT
#define MRIGHT

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


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // дескриптор консоли
int MenuIndex;

void GotoXY(int x, int y);
void ShowHideCursor(int state);
void PrintMenu (int MenuIndex);
void PrintStatus();
void ChooseAction()


//-----------------------------------------------------------------------------------'

void PrintStatus(){
    GotoXY(1,24);
    SetConsoleTextAttribute(hConsole, (WORD) ((Black<< 4) | DarkGray)); // setting back standard colors
    cout << "Use arrows for navigation, Enter for activation and Esc for exit.";
}

void PrintMenu (int MenuIndex){

    system("cls");
    GotoXY(0,0);

    for (int j=1; j<=3; ++j){
        if (j==MenuIndex) {
            SetConsoleTextAttribute(hConsole, (WORD) ((LightGray << 4) | Cyan));
        }
        else {
            SetConsoleTextAttribute(hConsole, (WORD) ((Black<< 4) | White));
        }
        cout << "Menu" << j << endl;
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

void ChooseAction()
{
        int key_code = _getch();
        if (key_code==27)
            return;
        else {
            switch (key_code){
                case 'w': MTOP      // w 119
                case 'a': MLEFT     // a 97
                case 's': MDOWN     // s 115
                case 'd': MRIGHT    // d 100
                case 13 :
                    system("cls");
                    cout << "You have chosen " << "Menu" << MenuIndex << endl;
                    system("pause");
                    break;
                case 224:
                    key_code = _getch();
                    if ( key_code == 72) {MTOP}
                    if ( key_code == 80) {MDOWN}
                    if ( key_code == 75) {MLEFT}
                    if ( key_code == 77) {MRIGHT}
                }
            }
}


#endif // UI_H_INCLUDED
