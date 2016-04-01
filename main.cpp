#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <iomanip>

#include "process.h"
#include "ui.h"
#include "data.h"
#include "custom.h"

using namespace std;


int main() {

   srand(time(0));

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
