#ifndef CUSTOM_H_INCLUDED
#define CUSTOM_H_INCLUDED

#include <cstdio>
#include "data.h"

using namespace std;

STUD *pStArr = new STUD [students_ammount];
int students_init_flag = 0;


void InitStudents();
void PrintStudents();
void SaveListOfStudents();
void ProcessListOfStudents();


void InitStudents(){
    if (students_init_flag==0){

        for (int i=0; i<students_ammount; ++i){

            if ((rand()%2+1)==1){
                strcpy(pStArr[i].name, NameMArr[rand()%5]);
                strcpy(pStArr[i].surname, SurnameMArr[rand()%5]);
                pStArr[i].sex='m';
                }
            else {
                strcpy(pStArr[i].name, NameWArr[rand()%5]);
                strcpy(pStArr[i].surname, SurnameWArr[rand()%5]);
                pStArr[i].sex='w';
                }
            pStArr[i].avMark = 0;
            for (int j=0; j<subj_ammount; ++j){
                pStArr[i].ArrMarks[j]=rand()%5+1;
                pStArr[i].avMark+=pStArr[i].ArrMarks[j];
            }
            pStArr[i].avMark /= subj_ammount;
        }

        cout << "You have created " << students_ammount << " students' records." << endl;
        students_init_flag = 1;
    }
    else
        cout << students_ammount << " have been created already. Use 'Delete' first." << endl;
}

void PrintStudents(){
    if (students_init_flag==1){
        for (int i=0; i<students_ammount; ++i){
            cout << setw(name_size) << pStArr[i].name << " " << setw(name_size) << pStArr[i].surname << ". Marks:";
            for (int j=0; j<subj_ammount; ++j){
                cout << " " << pStArr[i].ArrMarks[j];
            }
            cout << ". Average mark: " << pStArr[i].avMark << endl;
        }
        cout << endl << "You have " << students_ammount << " students in the list." << endl;
    }
    else {
        cout << "Nothing to print. Use 'Init' first." << endl;
    }
}

void SaveListOfStudents(){
    if (students_init_flag==1){
        FILE * f = fopen("stud.dat", "w");
        if (f!=NULL){
            fwrite(pStArr, sizeof(STUD), students_ammount, f);
            fclose(f);
        }
        cout << endl << "You have stored " << students_ammount << " records." << endl;
    }
    else {
        cout << "Nothing to store. Use 'Init' first." << endl;
    }
}

void ProcessListOfStudents(){
    if (students_init_flag==1){
        cout << endl << "You have processed " << students_ammount << " records." << endl;
    }
    else {
        cout << "Nothing to process. Use 'Init' first." << endl;
    }
}

void DeleteListOfStudents(){
    system("cls");
    if (students_init_flag==1){
        delete[] pStArr;
        cout << "You have deleted " << students_ammount << " students' records." << endl;
        students_init_flag = 0;
    }
    else
        cout << students_ammount << " records have been already deleted. Use 'Init' first." << endl;
}


#endif // CUSTOM_H_INCLUDED
