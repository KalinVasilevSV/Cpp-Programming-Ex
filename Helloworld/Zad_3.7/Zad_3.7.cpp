/*
3.7) В една земеделска ферма се прави малка програма за работа с кравите.
Всяка крава се описва с номер, година на раждане, брой родени телета и (среден) млеконадой (реално число).
Изведете информация за: всички крави; кравите, които имат млеконадой над 15; кравите  с максимален и минимален млеконадой,
родени през 2017 г.; средно-аритметично на млеконадоя над 25.5.
*/

#include <iostream>
#include <stdlib.h> // rand(), srand()
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

//Types
struct Cow
{
	string No = "none";
	int Year = -1; // 2000 to 2019
	int Calves = -1; //0 to 8
	float Avg_Milk_Production = -1.0; // 0.0 to 40.0
};

//Functions
// Generate cow population
void GenerateCowPopulation(Cow cows[], const int pop_size) {
	for (int i = 0; i < pop_size; i++) {
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

		cows[i] = New_Cow;
	}
} //End of GenerateCowPopulation()

// Print all cows
void PrintAllCows(Cow cows[], const int pop_size) {
	cout << "All cow data.\n";
	for (int i = 0; i < pop_size; i++) {
		cout << "No -> " << cows[i].No << " | "
			<< "Year -> " << cows[i].Year << " | "
			<< "Calves -> " << cows[i].Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << cows[i].Avg_Milk_Production << " |" << endl;
	}
} //End of PrintAllCows()

// Print cows with above specified Average Milk Production
void PrintCowsAboveAvgMilk(Cow cows[], const int pop_size, const float query_avg) {
	cout << "\nCows with Average Milk Production above " << setprecision(4) << query_avg << " litres.\n";
	for (int i = 0; i < pop_size; i++) {
		if (cows[i].Avg_Milk_Production > query_avg) {
			cout << "No -> " << cows[i].No << " | "
				<< "Year -> " << cows[i].Year << " | "
				<< "Calves -> " << cows[i].Calves << " | "
				<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << cows[i].Avg_Milk_Production << " |" << endl;
		}
	}
} //End of PrintCowsAboveAvgMilk()

// Print cows with  Max and Min Milk Production for queried year
void PrintMinMaxCows(Cow cows[], const int pop_size, const int query_year) {
	Cow MinCow, MaxCow;
	MinCow.Avg_Milk_Production = MAX_AVG_MILK;
	MaxCow.Avg_Milk_Production = -1.0;
	for (int i = 0; i < MAX_COWS; i++) {
		if (cows[i].Avg_Milk_Production > MaxCow.Avg_Milk_Production)
			MaxCow = cows[i];
		if (cows[i].Avg_Milk_Production < MinCow.Avg_Milk_Production)
			MinCow = cows[i];
	}

	if (MinCow.No == MaxCow.No) {
		cout << "\nThere is only one cow in " << query_year << ".\n"
			<< "No -> " << MinCow.No << " | "
			<< "Year -> " << MinCow.Year << " | "
			<< "Calves -> " << MinCow.Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << MinCow.Avg_Milk_Production << " |" << endl;
	}
	else {
		cout << "\nCow with Min Average Milk Production for " << query_year << ".\n"
			<< "No -> " << MinCow.No << " | "
			<< "Year -> " << MinCow.Year << " | "
			<< "Calves -> " << MinCow.Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << MinCow.Avg_Milk_Production << " |" << endl;

		cout << "\nCow with Max Average Milk Production for " << query_year << ".\n"
			<< "No -> " << MaxCow.No << " | "
			<< "Year -> " << MaxCow.Year << " | "
			<< "Calves -> " << MaxCow.Calves << " | "
			<< "Average Milk Production -> " << right << setw(5) << setfill(' ') << setprecision(4) << MaxCow.Avg_Milk_Production << " |" << endl;
	}
} //End of PrintMinMaxCows()

// Print the Average Milk Production above specified average
void PrintAvgMilkAbove(Cow cows[], const int pop_size, const float query_avg_above) {
	float avg_sum = 0;
	int cows_qualified = 0;
	for (int i = 0; i < pop_size; i++) {
		if (cows[i].Avg_Milk_Production > query_avg_above) {
			avg_sum += cows[i].Avg_Milk_Production;
			cows_qualified++;
		}
	}

	if (cows_qualified > 0) {
		float avg_milk_prod = avg_sum / cows_qualified;
		cout << "\nAverage Milk Production above " << setprecision(4) << query_avg_above << ": " << setprecision(4) << avg_milk_prod << endl;
	}
	else {
		cout << "\nThere are no cows that have and Average Milk Production above " << setprecision(4) << query_avg_above << "." << endl;
	}
} //End of PrintAvgMilkAbove()

//Entry point
int main() {

	// Generate cow population
	Cow cows[MAX_COWS];
	GenerateCowPopulation(cows,MAX_COWS);

	// Print all cows
	PrintAllCows(cows, MAX_COWS);

	// Print cows with above specified Average Milk Production -> QUERY_AVERAGE = 15 
	PrintCowsAboveAvgMilk(cows, MAX_COWS, QUERY_AVERAGE);

	// Print cows with  Max and Min Milk Production for queried year -> QUERY_YEAR = 2017 
	PrintMinMaxCows(cows, MAX_COWS, QUERY_YEAR);

	// Print the Average Milk Production above specified average -> QUERY_AVERAGE_ABOVE = 25.5 
	PrintAvgMilkAbove(cows, MAX_COWS, QUERY_AVERAGE_ABOVE);

} //End of main()