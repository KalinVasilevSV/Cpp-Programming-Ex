/*
 Задача 1. (Без масиви)
 1.1) Вход от конзолата: три равнобедрени триъгълника; всеки се задава чрез дължина на едната страна и височина към нея;
 Изход: периметър и лице за всяка фигура, както и сумата на всички лица.
*/

#include <iostream>
#include<cmath>

using namespace std;

//Constants
const int NUM_TRI = 3; //The number of triangles

//Functions
float FindPerimeter(float a, float h) {
	a = a / 2;
	float b = (sqrt(pow(a,2)+pow(h,2)));
	return a + 2 * b;
} //End of FindPerimeter()

float FindSurface(float a, float h) {
	return (a * h) / 2;
} //End of FindSurface()

void EnterParameters(float &a, float &h) {
	cout << "\nEnter side \"a\": ";
	cin >> a;
	cout << "Enter height \"h\": ";
	cin >> h;
} //End of EnterParameters()

//Entry point
int main()
{
	float a, ha, p1, p2, p3, s1, s2, s3, sum_all_s;
	cout << "Enter three triangles using side and the height to this side.";

	cout << "\nTriangle Num 1.";
	EnterParameters(a, ha);
	p1 = FindPerimeter(a, ha);
	s1 = FindSurface(a, ha);

	cout << "\nTriangle Num 2.";
	EnterParameters(a, ha);
	p2 = FindPerimeter(a, ha);
	s2 = FindSurface(a, ha);

	cout << "\nTriangle Num 3.";
	EnterParameters(a, ha);
	p3 = FindPerimeter(a, ha);
	s3 = FindSurface(a, ha);

	sum_all_s = s1 + s2 + s3;

	//Print Result
	cout << endl <<"Results!\n" << endl;
	cout << "P1= " << p1 << ", S1=" << s1 << endl;
	cout << "P2= " << p2 << ", S2=" << s2 << endl;
	cout << "P3= " << p3 << ", S3=" << s3 << endl;
	cout << "S1+S2+S3= " << sum_all_s << endl;

	return 0;
} //End of main()
