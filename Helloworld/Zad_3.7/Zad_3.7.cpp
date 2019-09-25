// Zad_3.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
3.7) В една земеделска ферма се прави малка програма за работа с кравите. 
Всяка крава се описва с номер, година на раждане, брой родени телета и (среден) млеконадой (реално число). 
Изведете информация за: всички крави; кравите, които имат млеконадой над 15; кравите  с максимален и минимален млеконадой, 
родени през 2017 г.; средно-аритметично на млеконадоя над 25.5.
*/

#include <iostream>
#include <stdlib.h> //rand(), srand()
#include <iomanip>  // provides formatting for cout
#include <string>

using namespace std;

const int MAX_COWS = 20;
const int No_LENGTH = 9;
const int QUERY_YEAR = 2017;
const float QUERY_AVERAGE = 15.0;
const float QUERY_AVERAGE_ABOVE = 25.5;

struct Cow {
	string No = "none";
	int Year = -1; // 2000 to 2019
	int Calves = -1; //0 to 8
	float Avg_Milk_Production = -1.0; // 0.0 to 40.0
};

Cow Cows[MAX_COWS];

void GenerateCows(Cow cows[], int cow_count) {

}

int main()
{
	// Generate cow population
	for (int i = 0; i < MAX_COWS; i++) {
		Cow new_Cow;
		
		string new_No = "";
		for (int j = 0; j < No_LENGTH; j++) {
			int digit = rand() % 10;
			new_No += to_string(digit);
		}
		new_Cow.No = new_No;

		new_Cow.Year = 2000 + rand() % 20;
		new_Cow.Calves = rand() % 9;

		float whole_part = rand() % 40;
		float dec_part = float(rand() % 100)/100;
		new_Cow.Avg_Milk_Production = whole_part + dec_part;

		if (rand() % 2 == 0) new_Cow.Avg_Milk_Production += 0.01; // Ensures Min and Max Values of Milk Output are reached.

		Cows[i] = new_Cow;
	}

	// Print all cows
	cout << "All cow data.\n";
	for (int i = 0; i < MAX_COWS; i++) {
		cout << "No: " << Cows[i].No << " "
			<< "Year: " << Cows[i].Year << " "
			<< "Calves: " << Cows[i].Calves << " "
			<< "Average Milk Production: " << right << setw(5) << setfill(' ') << setprecision(4) << Cows[i].Avg_Milk_Production << ";" << endl;
	}

	//Print cows with Average Milk Production above 15
	cout << "\nCows with Average Milk Production above 15 litres.\n";
		for (int i = 0; i < MAX_COWS; i++) {
			if (Cows[i].Avg_Milk_Production > QUERY_AVERAGE) {
				cout << "No: " << Cows[i].No << " "
					<< "Year: " << Cows[i].Year << " "
					<< "Calves: " << Cows[i].Calves << " "
					<< "Average Milk Production: " << right << setw(5) << setfill(' ') << setprecision(4) << Cows[i].Avg_Milk_Production << ";" << endl;
			}
		}

} //End of main()

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
