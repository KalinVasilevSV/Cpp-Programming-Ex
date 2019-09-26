// Zad_2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
2.2) Генерирайте 6 масива с 9 елемента, които са случайни цели числа в интервала [-100, +50). Отпечатайте масивите!
За всеки масив изведете средно-аритметично на числата, които се делят на 5 без остатък. За всеки масив изведете максималната стойност. 
Изведете минималната стойност от максималните стойности по масиви. Отпечатайте сортираните масиви (в обратен ред, намаляващо)!
*/

#include <iostream>
#include <cmath>
#include <stdlib.h> // rand, srand
#include <climits> //minmax values

using namespace std;

const int SIZE_PRIMARY = 6;
const int SIZE_SECONDARY = 9;
const int DIVISOR = 5;

struct ArrData {
	int DivCount = 0;
	float DivSum = 0;
	int MaxElement = INT_MIN;
};

void PopulateIntArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 151 - 100;
	}
} //End of PopulateIntArray()

void PrintArr(int arr[]) {
	for (int i = 0; i < SIZE_SECONDARY; i++) {
		cout << arr[i] << " ";
	}
} //End of PrintArr()

ArrData GetArrData(int arr[]) {
	ArrData div_result;

	for (int i = 0; i < SIZE_SECONDARY; i++) {
		if (arr[i] > div_result.MaxElement)
			div_result.MaxElement = arr[i];

		if (arr[i] % 5 == 0) {
			div_result.DivCount++;
			div_result.DivSum += arr[i];
		}
	}

	return div_result;
} //End of GetArrData()

int main()
{
	int Arr[SIZE_PRIMARY][SIZE_SECONDARY];
	int minmax_el_arrays = INT_MAX;

	for (int i = 0; i < SIZE_PRIMARY; i++) {
		//Populate each array
		PopulateIntArray(Arr[i], SIZE_SECONDARY);

		//Print the populated array
		if (i > 0) cout << "\n";
		PrintArr(Arr[i]);

		//Collect individual array data
		ArrData Data = GetArrData(Arr[i]);

		//Find average of elements divisible by divisor
		float avg_div;
		if(Data.DivCount>0)
			avg_div = Data.DivSum / Data.DivCount;

		//Find min of all max elements
		if (Data.MaxElement < minmax_el_arrays) minmax_el_arrays = Data.MaxElement;

		//Print results
		cout << "\n";
		if (Data.DivCount > 0)
			cout << "Average of elements divisible by " << DIVISOR << ": " << avg_div << endl;
		else
			cout << "There are no elements divisible by " << DIVISOR << endl;

		cout << "Max element in the current array: " << Data.MaxElement << endl;
	}
} //End of main()