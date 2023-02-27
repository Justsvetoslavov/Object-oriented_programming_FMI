#include <iostream>

struct ComplexNumber {
	double real;
	double imaginary;
};

ComplexNumber sumOfComplexNumbers(const ComplexNumber& num1, const ComplexNumber& num2)
{
	return { num1.real + num2.real, num1.imaginary + num2.imaginary };
}

void printComplexNumbers(const ComplexNumber& num)
{
	std::cout << num.real << " + " << num.imaginary << "i" << std::endl;
}
int main()
{
	ComplexNumber num1 = { 2.3, 0.5 };
	ComplexNumber num2 = { 1.5, 0.3 };
	ComplexNumber sum = sumOfComplexNumbers(num1, num2);
	printComplexNumbers(sum);
}