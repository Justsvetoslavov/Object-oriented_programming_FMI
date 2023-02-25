// Bozhidar, Group 1, practicum date 22.02.2023

#include <iostream>

struct ComplexNumber
{
    double real = 0;
    double imaginary = 0;
};

ComplexNumber addTwoCNumbers(const ComplexNumber &x, const ComplexNumber &y)
{
    ComplexNumber result;

    result.real = x.real + y.real;
    result.imaginary = x.imaginary + y.imaginary;

    return result;
}

void printCNumber(const ComplexNumber &x)
{
    std::cout << x.real << " + "
              << x.imaginary << "i";
}

ComplexNumber initComplexNumber()
{
    ComplexNumber newComplexNumber;

    std::cout << "real: ";
    std::cin >> newComplexNumber.real;

    std::cout << "imaginary: ";
    std::cin >> newComplexNumber.imaginary;
    return newComplexNumber;
}

int main()
{
    ComplexNumber x = initComplexNumber();
    ComplexNumber y = initComplexNumber();

    printCNumber(addTwoCNumbers(x, y));

    return 0;
}

/* Sample input
2
5
3
7
*/