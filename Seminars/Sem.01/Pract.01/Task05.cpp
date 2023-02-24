#include <iostream>

using std::cout;

const OPENING_BRACKET = "(";
const CLOSING_BRACKET = ")";
const IMAGINARY_SYMBOL = "i";
const COMMA = ",";
const WHITESPACE = " ";

struct ComplexNum
{
	double realPart;
	double imaginaryPart;
};

ComplexNum getSumOfTwoComplexNumbers(const ComplexNum& firstNum, const ComplexNum& secondNum)
{
	ComplexNum sum;

	sum.realPart = firstNum.realPart + secondNum.realPart;
	sum.imaginaryPart = firstNum.imaginaryPart + secondNum.imaginaryPart;

	return sum;
}

void printComplexNum(const ComplexNum& num)
{
	cout << OPENING_BRACKET << num.realPart << COMMA << WHITESPACE << num.imaginaryPart << IMAGINARY_SYMBOL << CLOSING_BRACKET;
}

int main()
{
	
}