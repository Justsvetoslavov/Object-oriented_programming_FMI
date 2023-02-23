#include <iostream>

using namespace std;

struct ComplexNumber {
    double real;
    double imaginary;
};

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    ComplexNumber result;
    result.real = lhs.real + rhs.real;
    result.imaginary = lhs.imaginary + rhs.imaginary;
    return result;
}

void printComplexNumber(const ComplexNumber& number) {
    cout << number.real << " + " << number.imaginary << "i" << endl;
}
int main() {
    ComplexNumber a = {1.0, 2.0};
    ComplexNumber b = {3.0, 4.0};
    ComplexNumber c = a + b;
    printComplexNumber(c);
    return 0;
}
