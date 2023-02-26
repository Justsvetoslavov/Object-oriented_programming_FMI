#include <iostream>

using std::cout;

const IMAGINARY_SYMBOL = "i";

struct ComplexNum
{
	double realPart;
	double imaginaryPart;
};

ComplexNum getSumOfTwoComplexNumbers(const ComplexNum& firstNum, const ComplexNum& secondNum)
{
	return ComplexNum{(firstNum.realPart + secondNum.realPart), (firstNum.imaginaryPart + secondNum.imaginaryPart)};
}

void printComplexNum(const ComplexNum& num)
{
	cout << "(" << num.realPart << ", " << num.imaginaryPart << IMAGINARY_SYMBOL << ")";
}

int main()
{
	ComplexNum firstNum{ 5,3 };
	ComplexNum secondNum{ 3,1 };

	printComplexNum(getSumOfTwoComplexNumbers(firstNum, secondNum));
}