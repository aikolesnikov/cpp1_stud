#pragma once

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

using namespace std;

const int name_size = 12;
const int subj_ammount = 4;


const char NameMArr[5][10] = { "Kolya","Vasya","Petya","Zhenya","Sasha" };
const char NameWArr[5][10] = { "Olya","Luda","Valya","Tanya","Katya" };
const char SurnameMArr[5][20] = { "Ivanov","Petrov","Sidorov","Vasechkin","Petechkin" };
const char SurnameWArr[5][20] = { "Ivanova","Petrova","Sidorova","Vasechkina","Petechkina" };


struct STUD {

	char name[name_size];
	char surname[name_size];
	char sex;
	int ArrMarks[subj_ammount];
	double avMark;
};


extern int students_ammount;
extern STUD *pStArr;
extern int students_init_flag;
extern int MenuIndex;

void InitStudents();
void PrintStudents();
void SaveListOfStudents();
void ProcessListOfStudents();


#define MTOP if (MenuIndex==1) {MenuIndex=menu_size;} else {MenuIndex-=1;}; break;
#define MDOWN if (MenuIndex==menu_size) {MenuIndex=1;} else {MenuIndex+=1;}; break;
#define MLEFT
#define MRIGHT


extern int esc_condition;

int ChooseAction();
int DoAction(int act);
void DoClearing();

#endif // DATA_H_INCLUDED
