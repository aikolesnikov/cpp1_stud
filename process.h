#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

#include "ui.h"
#include "custom.h"

#define MTOP if (MenuIndex==1) {MenuIndex=menu_size;} else {MenuIndex-=1;}; break;
#define MDOWN if (MenuIndex==menu_size) {MenuIndex=1;} else {MenuIndex+=1;}; break;
#define MLEFT
#define MRIGHT

using namespace std;

int esc_condition;

int ChooseAction();
int DoAction(int act);

int ChooseAction()
{
        int key_code = _getch();
        if (key_code==27)
            return 1;
        else {
            switch (key_code){
                case 'w': MTOP      // w 119
                case 'a': MLEFT     // a 97
                case 's': MDOWN     // s 115
                case 'd': MRIGHT    // d 100
                case 13 :
                    return 13;
                    break;
                case 224:
                    key_code = _getch();
                    if ( key_code == 72) {MTOP}
                    if ( key_code == 80) {MDOWN}
                    if ( key_code == 75) {MLEFT}
                    if ( key_code == 77) {MRIGHT}
                }
            }
            return 0;
}


int DoAction(int a)
{
    if (a==1) return 0;
    if (a==13) {
            system("cls");
            switch (MenuIndex){
                case 1:
                    InitStudents();
                    break;
                case 2:
                    PrintStudents();
                    break;
                case 3:
                    SaveListOfStudents();
                    break;
                case 4:
                    ProcessListOfStudents();
                    break;
                case 5:
                    DeleteListOfStudents();
                    break;
            }
            system("pause");
            return 13;
    }
    return 1;
}

void DoClearing(){
    if (students_init_flag==1){
        cout << "clearing..";
        delete[] pStArr;
    }
    else
        cout << "nothing to clear";
}


#endif // PROCESS_H_INCLUDED
