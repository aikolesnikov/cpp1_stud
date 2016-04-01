#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

using namespace std;

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
            switch (MenuIndex){
                case 1:
                    system("cls");
                    cout << "You have chosen " << "Menu" << MenuIndex << endl;
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    cout << "You have chosen " << "Menu" << MenuIndex << endl;
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    cout << "You have chosen " << "Menu" << MenuIndex << endl;
                    system("pause");
                    break;

            }
        return 13;
    }
    return 1;
}


#endif // PROCESS_H_INCLUDED
