#include <iostream>

struct ComplexNumber {
	double realPart;
	double complexPart;
};

ComplexNumber addComplexNumbers(const ComplexNumber& a, const ComplexNumber& b){
	ComplexNumber c;

	//Add the real parts and the imaginary parts together
	c.realPart = a.realPart + b.realPart;
	c.complexPart = a.complexPart + b.complexPart;

	return c;
}

void printComplexNumber(const ComplexNumber& a) {
	std::cout << a.realPart << " " << a.complexPart << "\n";
}

int main()
{
	ComplexNumber cn1 = { 3, 4 };
	ComplexNumber cn2 = { -10, 12 };
	ComplexNumber sum = addComplexNumbers(cn1, cn2);
	printComplexNumber(sum);
}

