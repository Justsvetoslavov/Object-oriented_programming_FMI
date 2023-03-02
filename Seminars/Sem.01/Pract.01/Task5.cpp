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

ComplexNumber* additionOfTwoComplexNumbers(const ComplexNumber& first, const ComplexNumber& second) {
    ComplexNumber* result = new ComplexNumber;
    result->realPart = first.realPart + second.realPart;
    result->imaginaryPart = first.imaginaryPart + second.imaginaryPart;

    return result;
}

ComplexNumber additionOfTwoComplexNumbers(const ComplexNumber* first, const ComplexNumber* second) {
    ComplexNumber result = {first->realPart + second->realPart, first->imaginaryPart + second->imaginaryPart};

    return result;
}

int main() {

    ComplexNumber first = {3, -4};
    ComplexNumber second = {-5, 7};

    ComplexNumber result = additionOfTwoComplexNumbers(&first, &second);

    result.printComplexNumber();

    ComplexNumber* result2 = additionOfTwoComplexNumbers(first, second);

    result2->printComplexNumber();

    delete result2;

    first.addComplexNumber(second);

    first.printComplexNumber();

    return 0;
}