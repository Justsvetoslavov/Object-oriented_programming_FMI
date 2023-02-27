#include <iostream>
using namespace std;

struct ComplexNumber {
	double realPart;
	double imaginaryPart;
};

ComplexNumber Add(ComplexNumber a, ComplexNumber b) {
	return ComplexNumber{ a.realPart + b.realPart, a.imaginaryPart + b.imaginaryPart };
}

void PrintComplexNumber(ComplexNumber c) {
	cout << c.realPart << " + " << c.imaginaryPart << "i";
}

int main() {
	ComplexNumber result = Add(ComplexNumber{ 1, 4.4 }, ComplexNumber{ 3.4,5 });
	PrintComplexNumber(result);
}