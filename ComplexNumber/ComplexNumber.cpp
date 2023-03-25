#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() {
    real = 0;
    imaginary = 0;
}

ComplexNumber::ComplexNumber(int real, int imaginary) {
    this->real = real;
    this->imaginary = imaginary;
}

bool ComplexNumber::isEqual(const ComplexNumber &num) const {
    if (this->real == num.real && this->imaginary == num.imaginary)
        return true;
    return false;
}

void ComplexNumber::add(const ComplexNumber &num) {
    this->real += num.real;
    this->imaginary += num.imaginary;
}

void ComplexNumber::minus(const ComplexNumber &num) {
    this->real -= num.real;
    this->imaginary -= num.imaginary;
}

void ComplexNumber::multiply(const ComplexNumber &num) {
    int oldReal = this->real;
    this->real = this->real * num.real - this->imaginary * num.imaginary;
    this->imaginary = oldReal * num.imaginary + this->imaginary * num.real;
}

void ComplexNumber::conjugate() {
    this->imaginary *= -1;
}

ComplexNumber &ComplexNumber::operator=(const ComplexNumber &num) {
    if (this != &num) {
        this->real = num.real;
        this->imaginary = num.imaginary;
    }
    return *this;
}

ComplexNumber ComplexNumber::getConjugated() const {
    ComplexNumber res = *this;
    res.conjugate();
    return res;
}

void ComplexNumber::print() const {
    std::cout << this->real << (this->imaginary >= 0 ? " + " : " - ")
              << (this->imaginary >= 0 ? this->imaginary : this->imaginary * -1) << "i\n";
}