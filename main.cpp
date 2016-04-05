#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>


#include "stud.h"
#include "ui.h"

using namespace std;

// global
int students_ammount = 10;
int students_init_flag = 0;
STUD *pStArr;
int MenuIndex = 0;
HANDLE hConsole = NULL; // дескриптор консоли
int esc_condition=0;


int main() {

   srand(time(0));
   // инициализация
   hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
   pStArr = new STUD[students_ammount];
   //

   esc_condition = 0;
   MenuIndex = 1;

   PrintMenu(MenuIndex);
   PrintStatus(status_str);

   while (DoAction(ChooseAction())) {
        PrintMenu(MenuIndex);
        PrintStatus(status_str);
   }

   system("cls");
   DoClearing();


   return 0;
}
