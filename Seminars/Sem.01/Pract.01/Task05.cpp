#include <iostream>

struct ComplexNumber
{
	double realPart;
	double imaginaryPart;
};

ComplexNumber sumComplexNumbers(const ComplexNumber& num1, const ComplexNumber& num2)
{
	ComplexNumber result{ 0, 0 };
	result.realPart = num1.realPart + num2.realPart;
	result.imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;
	return result;
}

bool compareDoubles(const double& d1, const double& d2)
{
	const double EPSILON = 0.0000001;
	return abs(d1 - d2) < EPSILON;
}

void printComplexNumber(const ComplexNumber& num)
{
	const bool hasRealPart = num.realPart > 0 || num.realPart < 0;
	const bool hasImaginaryPart = num.imaginaryPart > 0 || num.imaginaryPart < 0;
	const bool imaginaryPartCloseToOne = compareDoubles(num.imaginaryPart, 1.);
	const bool imaginaryPartCloseToMinusOne = compareDoubles(num.imaginaryPart, -1.);

	if (hasRealPart)
	{
		std::cout << num.realPart;
		if (hasImaginaryPart)
		{
			if (num.imaginaryPart > 0)
			{
				std::cout << " + ";
			}
			else if (num.imaginaryPart < 0)
			{
				std::cout << " - ";
			}

			if (!imaginaryPartCloseToOne && !imaginaryPartCloseToMinusOne)
			{
				std::cout << abs(num.imaginaryPart);
			}
			std::cout << 'i';
		}
	}
	else
	{
		if (hasImaginaryPart)
		{
			if (num.imaginaryPart < 0)
			{
				std::cout << " - ";
			}

			if (!imaginaryPartCloseToOne && !imaginaryPartCloseToMinusOne)
			{
				std::cout << num.imaginaryPart;
			}
			std::cout << 'i';
		}
		else
		{
			std::cout << num.realPart << '+' << num.imaginaryPart << 'i';
		}
	}
}

int main()
{
	ComplexNumber c1{ 1,2 };
	ComplexNumber c2{ -2,4 };
	printComplexNumber(c1);
	std::cout << '\n';
	printComplexNumber(c2);
	std::cout << '\n';
	printComplexNumber(sumComplexNumbers(c1, c2));
	std::cout << "\n\n";

	ComplexNumber c3{ 0.0025,-1.0001 };
	ComplexNumber c4{ -1.0011,0.0001 };
	printComplexNumber(c3);
	std::cout << '\n';
	printComplexNumber(c4);
	std::cout << '\n';
	printComplexNumber(sumComplexNumbers(c3, c4));
}