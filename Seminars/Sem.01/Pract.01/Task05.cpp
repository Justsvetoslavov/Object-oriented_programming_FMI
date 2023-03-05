// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
#include <iostream>
using namespace std;
struct complexNumber {
	int rPart;
	int iPart;
};
void combinedComplexNumbers(const complexNumber& p1, const complexNumber& p2) {
	int combinedRPART = p1.rPart + p2.rPart;
	int combinedIPART = p1.iPart + p2.iPart;

	cout << "Z1 + Z2 = " << combinedRPART << " + " << combinedIPART << "i";
}
int main()
{
	complexNumber p1, p2;
	cout << "Enter the real part of the complexNumber:";
	cin >> p1.rPart;
	cout << "Now the other part: ";
	cin >> p1.iPart;
	cout << "Enter the real part for the second complexNumber: ";
	cin >> p2.rPart;
	cout << "Now the other part: ";
	cin >> p2.iPart;
	combinedComplexNumbers(p1, p2);
}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
