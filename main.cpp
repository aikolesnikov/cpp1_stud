#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ui.h"

using namespace std;


int main() {

   // int esc_condition = 0;
   MenuIndex = 1;

   while (true) {

        PrintMenu(MenuIndex);
        PrintStatus();

        ChooseAction();

   }
    SetConsoleTextAttribute(hConsole, (WORD) ((Black<< 4) | White)); // setting back standard colors

   return 0;
}



// This variant of menu crashes in case of key_press_and_hold
/*
   while( !(_kbhit()) and !(esc_condition) )  {

        key_code = _getch();
        switch (key_code){
            case 'w': MTOP      // w 119
            case 'a': MLEFT     // a 97
            case 's': MDOWN     // s 115
            case 'd': MRIGHT    // d 100
            case 224:
                key_code = _getch();
                if ( key_code == 72) {MTOP}
                if ( key_code == 80) {MDOWN}
                if ( key_code == 75) {MLEFT}
                if ( key_code == 77) {MRIGHT}
                break;
            case 13 :
                system("cls");
                cout << "You have chosen " << "Menu" << MenuIndex << endl;
                system("pause");
                break;
            case 27: esc_condition = 1;
        }
        PrintMenu(MenuIndex);
   }

*/
