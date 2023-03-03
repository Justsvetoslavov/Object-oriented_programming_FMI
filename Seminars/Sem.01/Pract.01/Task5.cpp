#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct ComplexNumber {
    double realPart;
    double imaginaryPart;

    void addComplexNumber(const ComplexNumber& number) {
        realPart += number.realPart;
        imaginaryPart += number.imaginaryPart;
    }

    void printComplexNumber() {
        cout << realPart << " + " << imaginaryPart << "i" << endl;
    }
};

ComplexNumber additionOfTwoComplexNumbers(const ComplexNumber* first, const ComplexNumber* second) {
    ComplexNumber result = {first->realPart + second->realPart, first->imaginaryPart + second->imaginaryPart};

    return result;
}

int main() {

    ComplexNumber first = {3, -4};
    ComplexNumber second = {-5, 7};

    ComplexNumber result = additionOfTwoComplexNumbers(&first, &second);

    result.printComplexNumber();

    first.addComplexNumber(second);

    first.printComplexNumber();

    return 0;
}