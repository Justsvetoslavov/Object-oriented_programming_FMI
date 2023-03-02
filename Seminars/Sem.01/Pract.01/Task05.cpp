#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct ComplexNumber {
    int realPart;
    int imaginaryPart;
};

ComplexNumber SumTwoComplexNumbers(const ComplexNumber& num1, const ComplexNumber& num2) {
    ComplexNumber product;

    product.realPart = num1.realPart + num2.realPart;
    product.imaginaryPart = num1.imaginaryPart + num2.imaginaryPart;

    return product;
}

void ReadComplexNumber(ComplexNumber& num) {
    std::cout << "Enter real part: ";
    std::cin >> num.realPart;
    std::cout << "Enter imaginary part: ";
    std::cin >> num.imaginaryPart;
}

void PrintComplexNumber(const ComplexNumber& num) {
    std::cout << "Complex number is: " << num.realPart
        << "+" << num.imaginaryPart << "i" << std::endl;
}

int main()
{
    ComplexNumber num1, num2;
    ReadComplexNumber(num1);
    ReadComplexNumber(num2);

    ComplexNumber product = SumTwoComplexNumbers(num1, num2);
    PrintComplexNumber(product);

}
