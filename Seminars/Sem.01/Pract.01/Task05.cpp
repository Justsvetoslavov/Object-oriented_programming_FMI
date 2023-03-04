//Gabriela Mladenova 
//SI
//Group 1
//3MI0600225

#include <iostream>

struct ComplexNumber
{
    int Re;
    int Im;
};

void inputComplexNumber(ComplexNumber& number)
{
    std::cout << "Enter the real part of the number: ";
    std::cin >> number.Re;
    std::cout << "Enter the imaginary part of the number: ";
    std::cin >> number.Im;
}

complexNumber sumOfComplexNumbers(const ComplexNumber& number1, const ComplexNumber& number2)
{
    ComplexNumber result;
    result.Re = number1.Re + number2.Re;
    result.Im = number1.Im + number2.Im;
    return result;
}

void printComplexNumber(const ComplexNumber& number)
{
    std::cout << number.Re << " + " << number.Im << "i";
}

int main()
{
    ComplexNumber number1 = {};
    ComplexNumber number2 = {};
    ComplexNumber resultOfSum = {};
    inputComplexNumber(number1);
    inputComplexNumber(number2);

    resultOfSum = sumOfComplexNumbers(number1, number2);
    printComplexNumber(number1);
    std::cout << "  +  ";
    printComplexNumber(number2);
    std::cout << "  =  ";
    printComplexNumber(resultOfSum);

    return 0;
}
