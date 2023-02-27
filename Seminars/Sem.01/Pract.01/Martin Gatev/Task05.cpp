#include <iostream>

using std::cin;
using std::cout;

struct ComplexNumber
{
	double realPart;
	double imgPart;
};

ComplexNumber sumOfComplexNumbers(const ComplexNumber& number1,
								  const ComplexNumber& number2)
{
	ComplexNumber sum{};

	sum.realPart = number1.realPart + number2.realPart;
	sum.imgPart = number1.imgPart + number2.imgPart;

	return sum;
}

void printComplexNumber(const ComplexNumber& number)
{
	cout << number.realPart << " + " << number.imgPart << "i";
}