#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <cstdio>
#include <iostream>
#include <conio.h>


#include "stud.h"
#include "ui.h"
using namespace std;



void InitStudents() {
	if (students_init_flag == 0) {

		for (int i = 0; i<students_ammount; ++i) {

			if ((rand() % 2 + 1) == 1) {
				strcpy(pStArr[i].name, NameMArr[rand() % 5]);
				strcpy(pStArr[i].surname, SurnameMArr[rand() % 5]);
				pStArr[i].sex = 'm';
			}
			else {
				strcpy(pStArr[i].name, NameWArr[rand() % 5]);
				strcpy(pStArr[i].surname, SurnameWArr[rand() % 5]);
				pStArr[i].sex = 'w';
			}
			pStArr[i].avMark = 0;
			for (int j = 0; j<subj_ammount; ++j) {
				pStArr[i].ArrMarks[j] = rand() % 5 + 1;
				pStArr[i].avMark += pStArr[i].ArrMarks[j];
			}
			pStArr[i].avMark /= subj_ammount;
		}

		cout << "You have created " << students_ammount << " students' records." << endl;
		students_init_flag = 1;
	}
	else
		cout << students_ammount << " have been created already. Use 'Delete' first." << endl;
}

void PrintStudents() {
	if (students_init_flag == 1) {
		for (int i = 0; i<students_ammount; ++i) {
			cout << setw(name_size) << pStArr[i].name << " " << setw(name_size) << pStArr[i].surname << ". Marks:";
			for (int j = 0; j<subj_ammount; ++j) {
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

void SaveListOfStudents() {
	if (students_init_flag == 1) {
		FILE * f = fopen("stud.dat", "w");
		if (f != NULL) {
			fwrite(pStArr, sizeof(STUD), students_ammount, f);
			fclose(f);
		}
		cout << endl << "You have stored " << students_ammount << " records." << endl;
	}
	else {
		cout << "Nothing to store. Use 'Init' first." << endl;
	}
}

void ProcessListOfStudents() {
	if (students_init_flag == 1) {
		cout << endl << "You have processed " << students_ammount << " records." << endl;
	}
	else {
		cout << "Nothing to process. Use 'Init' first." << endl;
	}
}

void DeleteListOfStudents() {
	system("cls");
	if (students_init_flag == 1) {
		delete[] pStArr;
		cout << "You have deleted " << students_ammount << " students' records." << endl;
		students_init_flag = 0;
	}
	else
		cout << students_ammount << " records have been already deleted. Use 'Init' first." << endl;
}

////////////


int ChooseAction()
{
	int key_code = _getch();
	if (key_code == 27)
		return 1;
	else {
		switch (key_code) {
		case 'w': MTOP      // w 119
		case 'a': MLEFT     // a 97
		case 's': MDOWN     // s 115
		case 'd': MRIGHT    // d 100
		case 13:
			return 13;
			break;
		case 224:
			key_code = _getch();
			if (key_code == 72) { MTOP }
			if (key_code == 80) { MDOWN }
			if (key_code == 75) { MLEFT }
			if (key_code == 77) { MRIGHT }
		}
	}
	return 0;
}


int DoAction(int a)
{
	if (a == 1) return 0;
	if (a == 13) {
		system("cls");
		switch (MenuIndex) {
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

void DoClearing() {
	if (students_init_flag == 1) {
		cout << "clearing..";
		delete[] pStArr;
	}
	else
		cout << "nothing to clear";
}
