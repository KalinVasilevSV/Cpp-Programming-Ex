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
#include <time.h> // time
#include <climits> //minmax values

using namespace std;

const int size_prim = 6;
const int size_sec = 9;
const int divisor = 5;

//Has to be defined before use
struct arr_data {
	int div_count = 0;
	float div_sum = 0;
	int max_el = INT_MIN;
};

void populate_int_array(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 151 - 100;
	}
} //End of populate_int_array()

void print_arr(int arr[]) {
	for (int i = 0; i < size_sec; i++) {
		cout << arr[i] << " ";
	}
} //End of print_arr()

arr_data get_arr_data(int arr[]) {
	arr_data div_result;

	for (int i = 0; i < size_sec; i++) {
		if (arr[i] > div_result.max_el)
			div_result.max_el = arr[i];

		if (arr[i] % 5 == 0) {
			div_result.div_count++;
			div_result.div_sum += arr[i];
		}
	}

	return div_result;
} //End of get_arr_data()

int main()
{
	int arr[size_prim][size_sec];
	int minmax_el_arrays = INT_MAX;

	for (int i = 0; i < size_prim; i++) {
		//Populate each array
		populate_int_array(arr[i], size_sec);

		//Print the populated array
		print_arr(arr[i]);

		//Collect individual array data
		arr_data data = get_arr_data(arr[i]);

		//Find average of elements divisible by divisor
		float avg_div;
		if(data.div_count>0)
			avg_div = data.div_sum / data.div_count;

		//Find min of all max elements
		if (data.max_el < minmax_el_arrays) minmax_el_arrays = data.max_el;

		//Print results
		cout << "\n";
		if (data.div_count > 0)
			cout << "Average of elements divided by" << divisor << ": " << avg_div << endl;
		else
			cout << "There are no elements divisible by " << divisor << endl;

		cout << "Max element in the current array: " << data.max_el << endl;
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
