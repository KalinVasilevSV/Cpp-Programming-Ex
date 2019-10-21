// Zad_3.1-Ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
3.1) 
В един университет се прави малка програма за работа със студенти. 
Всеки студент се описва с име, факултетен номер, година на записване и (средно-аритметичен) успех. Изведете информация за: всички студенти; 
студенти, които имат успех над 4.50; студентите с максимален и минимален успех, записани през 2018 г.; 
средно-аритметично на успехите за студентите с успех над 5.
*/
#include <iostream>
#include <string>
#include <stdlib.h> // rand(), srand()
#include <iomanip>

using namespace std;

const int MaxStudents(50); //It's possible to use "=" operator as well as "()" operator to initialize variables
const int FacNo_length = 9; // Watch for int overflow
const int MinMaxQueryYear = 2018;
const float Above_QueryValue = 4.50;
const float Avg_QueryValue = 5.00;

struct Student {
	string Name = "Not Entered Yet";
	string FacNo = "Not Entered Yet";
	int Year = -1;
	float AvgGrade= -1.0;
};

Student Students[MaxStudents + 1]; //Can remove +1 to set the value to 50

string RealNames[]= { //There are 20 names in this array
	"Petar", "Ivan", "Kiril", "Slavina", "Liliq", "Stamen", "Georgi", "Stefan", 
	"Andrei", "Katya", "Iordan", "Stoqn", "Zornica", "Monica",
	"Nadya", "Kamen", "Svetoslav", "Antoniya", "Kameliya", "Radost"};

string RealSurnames[]={ //There are 15 surnames in this array
	"Ivanov", "Petrov", "Kolev", "Vasilev", "Jordanov", "Stefanov", "Georgiev", "Kacarski", 
	"Todorov", "Milenkov", "Vajarski", "Stoikov", "Toshev", "Kostov", "Kovachki"
};

string ChooseRealName() {
	int name_selector = rand() % 20;
	return RealNames[name_selector];
} //End of ChooseRealName()

string ChooseRealSurname() {
	int surname_selector = rand() % 15;
	return RealSurnames[surname_selector];
} //End of ChooseRealSurname()

string GenerateName() {
	return ChooseRealName() + " " + ChooseRealSurname();
} //End of GenerateName()

string GenerateFacNo(int student_order) {
	string fac_prototype="";
	int fac_digit;

	bool UniqueFacNo = true;

	do {
		for (int i = 0; i < FacNo_length; i++) {
			fac_digit = rand() % 10;
			fac_prototype += to_string(fac_digit);
		}
		for (int i = 0; i < student_order; i++) {
			if (Students[i].FacNo == fac_prototype)
				UniqueFacNo = false;
		}
	} while (UniqueFacNo == false);

	return fac_prototype;
} //End of GenerateFacNo()

int GenerateYear() {
	return 1990 + rand() % 30;
} //End of GenerateYear()

float GenerateAvgGrade() {
	float int_part = rand() % 4+2;
	float dec_part = float((rand() % 100))/100;

	return int_part + dec_part;
} //End of GenerateAvgGrade()

Student GenerateStudent(int student_order) {
	Student student_prototype;
	student_prototype.Name = GenerateName();
	student_prototype.FacNo = GenerateFacNo(student_order);
	student_prototype.Year = GenerateYear();
	student_prototype.AvgGrade = GenerateAvgGrade();

	return student_prototype;
} //End of GenerateStudent()


void EnterAllStudents(Student StudentsArr[], const int arr_size){
	for (int i = 0; i < arr_size; i++) {
		StudentsArr[i] = GenerateStudent(i);
	}
} //End of EnterAllStudents()

void PrintStudent(Student student) {
	cout << "Name: " << left << setw(18) << setfill(' ') << student.Name << "| "
		<< "FacNo: " << student.FacNo << " | "
		<< "Year: " << student.Year << " | "
		<< "Average Grade: " << setw(4) << setfill('0') << student.AvgGrade<< " |"
		<< endl;
} //End of PrintStudent()

void PrintStudentsArray(Student Students[], int arr_size) {
	for (int i = 0; i < arr_size; i++) 
		PrintStudent(Students[i]);
} //End of PrintAllStudents()

void PrintAbove(Student students[], int arr_size) {
	for (int i = 0; i < arr_size; i++) {
		if (students[i].AvgGrade > Above_QueryValue)
			PrintStudent(students[i]);
	}
} //End of PrintAbove()

void PrintMinMax(Student students[], int arr_size) {
	Student MinStudent;
	MinStudent.AvgGrade = 7.0;
	Student MaxStudent;
	MaxStudent.AvgGrade = -1.0;

	for (int i = 0; i < arr_size; i++) {
		if (students[i].Year == MinMaxQueryYear) {
			if (students[i].AvgGrade > MaxStudent.AvgGrade)
				MaxStudent = students[i];
			if (students[i].AvgGrade < MinStudent.AvgGrade)
				MinStudent = students[i];
		}
	}

	if (MaxStudent.AvgGrade > 6.00) {
		cout << "There are no students signed up in "<<MinMaxQueryYear<<".\n";
	}
	else if (MinStudent.FacNo == MaxStudent.FacNo) {
		cout << "There is a single student signed up in "<<MinMaxQueryYear<<":\n";
		PrintStudent(MaxStudent);
	}
	else {
		cout << "Student with Highest Average Grade in " << MinMaxQueryYear << ":\n";
		PrintStudent(MaxStudent);
		cout << "Student with Lowest Average Grade in " << MinMaxQueryYear << ":\n";
		PrintStudent(MinStudent);
	}
}

void PrintAvgAbove(Student students[], int arr_size,float cutoff_grade) {
	int student_count = 0;
	float avg_sum = 0.0;
	float avg_grade = 0.0;

	for (int i = 0; i < arr_size; i++) {
		if (students[i].AvgGrade > cutoff_grade) {
			student_count++;
			avg_sum += students[i].AvgGrade;
		}
	}

	if (student_count == 0)
		cout << "\nThere are no students with Average Grade above " << left << setw(4) << setfill('0') << cutoff_grade <<".";
	else {
		avg_grade = avg_sum / student_count;
		cout << "\nAverage Grade for all students with a personal Average Grade above " << cutoff_grade<<": "<< left<< setw(4) <<setfill('0')<<setprecision(3)<< avg_grade<<"\n";
	}
}

int main()
{
	EnterAllStudents(Students, MaxStudents);
	cout << "All students:\n";
	PrintStudentsArray(Students, MaxStudents);
	cout << "\nStudents with Average Grade above " << left<<setw(4) << setfill('0') << Above_QueryValue << ":\n";
	PrintAbove(Students, MaxStudents);
	cout << "\nStudents with Highest and Lowest Average Grades.\n";
	PrintMinMax(Students, MaxStudents);
	cout << "\n";
	PrintAvgAbove(Students, MaxStudents, Avg_QueryValue);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
