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

// Constants
const int MAX_COWS = 20;
const int No_LENGTH = 9;
const int MAX_CALVES = 8;
const int START_YEAR = 2000;
const int MAX_YEAR_OFFSET = 19;
const float MAX_AVG_MILK = 40.0;
const int QUERY_YEAR = 2017;
const float QUERY_AVERAGE = 15.0;
const float QUERY_AVERAGE_ABOVE = 25.5;

struct Cow
{
	string No = "none";
	int Year = -1; // 2000 to 2019
	int Calves = -1; //0 to 8
	float Avg_Milk_Production = -1.0; // 0.0 to 40.0
};

Cow Cows[MAX_COWS];

int main() {
	// Generate cow population
	for (int i = 0; i < MAX_COWS; i++) {
		Cow New_Cow;

		string new_No = "";
		for (int j = 0; j < No_LENGTH; j++) {
			int digit = rand() % 10;
			new_No += to_string(digit);
		}
		New_Cow.No = new_No;

		New_Cow.Year = START_YEAR + rand() % (MAX_YEAR_OFFSET + 1);
		New_Cow.Calves = rand() % (MAX_CALVES + 1);

		float whole_part = rand() % int(MAX_AVG_MILK);
		float dec_part = float(rand() % 100) / 100;
		New_Cow.Avg_Milk_Production = whole_part + dec_part;

		if (rand() % 2 == 0) New_Cow.Avg_Milk_Production += 0.01; // Ensures Min and Max Values of Milk Output are reached.

		Cows[i] = New_Cow;
	}

	// Print all cows
	cout << "All cow data.\n";
	for (int i = 0; i < MAX_COWS; i++) {
		cout << "No -> " << Cows[i].No << " | "
			<< "Year -> " << Cows[i].Year << " | "
			<< "Calves -> " << Cows[i].Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << Cows[i].Avg_Milk_Production << " |" << endl;
	}

	// Print cows with Average Milk Production above 15 (QUERY_AVERAGE)
	cout << "\nCows with Average Milk Production above " << setprecision(4) << QUERY_AVERAGE << " litres.\n";
	for (int i = 0; i < MAX_COWS; i++) {
		if (Cows[i].Avg_Milk_Production > QUERY_AVERAGE) {
			cout << "No -> " << Cows[i].No << " | "
				<< "Year -> " << Cows[i].Year << " | "
				<< "Calves -> " << Cows[i].Calves << " | "
				<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << Cows[i].Avg_Milk_Production << " |" << endl;
		}
	}

	// Print cows with  Max and Min Milk Production for queried year (QUERY_YEAR)
	Cow MinCow, MaxCow;
	MinCow.Avg_Milk_Production = MAX_AVG_MILK;
	MaxCow.Avg_Milk_Production = -1.0;
	for (int i = 0; i < MAX_COWS; i++) {
		if (Cows[i].Avg_Milk_Production > MaxCow.Avg_Milk_Production)
			MaxCow = Cows[i];
		if (Cows[i].Avg_Milk_Production < MinCow.Avg_Milk_Production)
			MinCow = Cows[i];
	}

	if (MinCow.No == MaxCow.No) {
		cout << "\nThere is only one cow in " << QUERY_YEAR<< ".\n"
			<< "No -> " << MinCow.No << " | "
			<< "Year -> " << MinCow.Year << " | "
			<< "Calves -> " << MinCow.Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << MinCow.Avg_Milk_Production << " |" << endl;
	}
	else {
		cout << "\nCow with Min Average Milk Production for " << QUERY_YEAR << ".\n"
			<< "No -> " << MinCow.No << " | "
			<< "Year -> " << MinCow.Year << " | "
			<< "Calves -> " << MinCow.Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << MinCow.Avg_Milk_Production << " |" << endl;

		cout << "\nCow with Max Average Milk Production for " << QUERY_YEAR << ".\n"
			<< "No -> " << MaxCow.No << " | "
			<< "Year -> " << MaxCow.Year << " | "
			<< "Calves -> " << MaxCow.Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << MaxCow.Avg_Milk_Production << " |" << endl;
	}

	// Print the Average Milk Production above 25.5 (QUERY_AVERAGE_ABOVE)
	float avg_sum = 0;
	int cows_qualified = 0;
	for (int i = 0; i < MAX_COWS; i++) {
		if (Cows[i].Avg_Milk_Production > QUERY_AVERAGE_ABOVE) {
			avg_sum += Cows[i].Avg_Milk_Production;
			cows_qualified++;
		}
	}

	if (cows_qualified > 0) {
		float avg_milk_prod = avg_sum / cows_qualified;
		cout << "\nAverage Milk Production above " << setprecision(4) << QUERY_AVERAGE_ABOVE << ": " << setprecision(4) << avg_milk_prod << endl;
	}
	else {
		cout << "\nThere are no cows that have and Average Milk Production above " << setprecision(4) << QUERY_AVERAGE_ABOVE << "." << endl;
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
