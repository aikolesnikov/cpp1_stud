#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

using namespace std;

const int name_size = 12;
int students_ammount = 10;
const int subj_ammount = 4;


char NameMArr[5][10]={"Kolya","Vasya","Petya","Zhenya","Sasha"};
char NameWArr[5][10]={"Olya","Luda","Valya","Tanya","Katya"};
char SurnameMArr[5][20]={"Ivanov","Petrov","Sidorov","Vasechkin","Petechkin"};
char SurnameWArr[5][20]={"Ivanova","Petrova","Sidorova","Vasechkina","Petechkina"};


struct STUD {

    char name [name_size];
    char surname [name_size];
    char sex;
    int ArrMarks [subj_ammount];
    double avMark;
};

#endif // DATA_H_INCLUDED
