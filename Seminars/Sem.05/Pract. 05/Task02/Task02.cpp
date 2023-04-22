#include <iostream>
#include "ComplexNumbers.h"

int main()
{
    ComplexNumber number;
    ComplexNumber number2(3.5, 1.0);
    ComplexNumber number3(2, 2.5);
    number = number2.Multiply(number3);
    number.Print();
    number3.Conjugate();
    number3.Print();
    ComplexNumber conjugated = number2.GetConjugated(number2);
    conjugated.Print();
    ComplexNumber sum = number2.Add(number3);
    sum.Print();
    if (number2.IsEqual(number3))
        std::cout << "Num2 and num3 are equal!";
    else
        std::cout << "Num2 and num3 aren't equal!";
}


