#include <iostream>
#include "ComplexNum.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	double a, b, c, d;
	cout << "Enter the perameters:" << endl;
	cin >> a >> b >> c >> d;
	ComplexNum complexNum1(a, b);
	ComplexNum complexNum2(c, d);
	ComplexNum result;
	cout << "If they equal: " << std::boolalpha << complexNum1.isEqual(complexNum1, complexNum2) << endl;
	result = result.add(complexNum1, complexNum2);
	cout << "The added: ";
	result.print();
	result = result.multiply(complexNum1, complexNum2);
	cout << "The multuply: ";
	result.print();
	result = result.substract(complexNum1, complexNum2);
	cout << "The substract: ";
	result.print();
	cout << "The conjugated: ";
	result.conjugate();
	result.print();
	cout << "Get Conjugated number ";
	ComplexNum conjugated = result.getConjugated();
	conjugated.print();
}