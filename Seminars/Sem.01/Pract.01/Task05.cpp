#include <iostream>

using std::cin; 
using std::cout;
using std::endl;

struct ComplexNumber
{
    double real;
    double imaginary;
};

void inputNumber(ComplexNumber& num)
{
    cout << "Enter the real part of the number: ";
    cin >> num.real;
    cout << "Enter the imaginary part of the number: ";
    cin >> num.imaginary;
};

ComplexNumber sum(const ComplexNumber& num1, const ComplexNumber& num2) {
    double realSum = num1.real + num2.real;
    double imagSum = num1.imaginary + num2.imaginary;
    return { realSum, imagSum };
}

void printComplexNumber(const ComplexNumber& num)
{
    if (num.imaginary >= 0) {
        cout << num.real << " + " << num.imaginary << "i" << endl;
    }
    else {
        cout << num.real << " " << num.imaginary << "i" << endl;
    }
}

int main()
{
    ComplexNumber(num1);
    inputNumber(num1);
    printComplexNumber(num1);
    cout << endl;

    ComplexNumber(num2);
    inputNumber(num2);
    printComplexNumber(num2);
    cout << endl;

    cout << "The sum of the complex numbers is: ";
    ComplexNumber result = sum(num1, num2);
    printComplexNumber(result);

    return 0;
}
