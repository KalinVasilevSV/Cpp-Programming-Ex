// Zad_1.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
 Задача 1. (Без масиви)
 1.1) Вход от конзолата: три равнобедрени триъгълника; всеки се задава чрез дължина на едната страна и височина към нея;
 Изход: периметър и лице за всяка фигура, както и сумата на всички лица.
*/

#include <iostream>
#include<cmath>

using namespace std;

float find_p(float a, float h) {
	a = a / 2;
	float b = (sqrt(pow(a,2)+pow(h,2)));
	return a + 2 * b;
}

float find_s(float a, float h) {
	return (a * h) / 2;
}

int main()
{
	float a1, a2, a3, ha1, ha2, ha3, p1, p2, p3, s1, s2, s3, sum_all_s;
	cout << "Vavedete 3 ravnobedreni triagalnika sas strana i visochinata kam tqh." << endl;

	cout << "Triagalnik 1:" << endl;
	cout << "a1= ";
	cin >> a1;
	cout << "ha1= ";
	cin >> ha1;
	p1 = find_p(a1, ha1);
	s1 = find_s(a1, ha1);

	cout << "Triagalnik 2:" << endl;
	cout << "a2= ";
	cin >> a2;
	cout << "ha2= ";
	cin >> ha2;
	p2 = find_p(a2,ha2);
	s2 = find_s(a2, ha2);

	cout << "Triagalnik 3:" << endl;
	cout << "a3= ";
	cin >> a3;
	cout << "ha3= ";
	cin >> ha3;
	p3 = find_p(a3, ha3);
	s3 = find_s(a3, ha3);

	sum_all_s = s1 + s2 + s3;

	//Print Result
	cout << endl <<"Rezultati!\n" << endl;
	cout << "P1= " << p1 << ", S1=" << s1 << endl;
	cout << "P2= " << p2 << ", S2=" << s2 << endl;
	cout << "P3= " << p3 << ", S3=" << s3 << endl;
	cout << "S1+S2+S3= " << sum_all_s << endl;

	return 0;
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
