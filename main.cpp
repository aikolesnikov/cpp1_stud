#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "ui.h"
#include "proc.h"

using namespace std;


int main() {

   esc_condition = 0;
   MenuIndex = 1;

   PrintMenu(MenuIndex);
   PrintStatus(status_str);

   while (DoAction(ChooseAction())) {
        PrintMenu(MenuIndex);
        PrintStatus(status_str);
   }

   // DoClearing();
   system("cls");

   return 0;
}
