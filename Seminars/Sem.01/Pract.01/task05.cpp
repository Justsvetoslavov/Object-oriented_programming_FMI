#include <iostream>

using std::cin, std::cout, std::endl;

struct ComplexNumber {
    double real;
    double imaginary;
};

ComplexNumber additionOfComplexNumbers(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return {lhs.real + rhs.real, lhs.imaginary + rhs.imaginary};
}

void printComplexNumber(const ComplexNumber &number) {
    cout << number.real << " + " << number.imaginary << "i" << endl;
}

int main() {
    ComplexNumber a = {1.0, 2.0};
    ComplexNumber b = {3.0, 4.0};
    ComplexNumber c = additionOfComplexNumbers(a, b);
    printComplexNumber(c);
    return 0;
}
