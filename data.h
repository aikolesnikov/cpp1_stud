#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

using namespace std;

const int name_size = 50;
const int students_ammount = 20;
const int subj_ammount = 10;

struct STUD {

    char name [name_size];
    char surname [name_size]
    int ArrMarks [subj_ammount];
    double avMark;
};

#endif // DATA_H_INCLUDED
