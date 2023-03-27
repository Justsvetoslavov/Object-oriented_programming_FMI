#include <iostream>
#include "Task02.h"

const double EPSILON = 0.0001;

double absolute(double x)
{
    return x < 0 ? -x : x;
}

ComplexNumber::ComplexNumber()
{
    real = 0;
    imaginary = 0;
}

ComplexNumber::ComplexNumber(const double real, const double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

double ComplexNumber::getReal() const
{
    return this->real;
}

double ComplexNumber::getImaginary() const
{
    return this->imaginary;
}

bool ComplexNumber::isEqual(const ComplexNumber &x, const ComplexNumber &y) const
{
    return absolute(x.real - y.real) < EPSILON && absolute(x.imaginary - y.imaginary);
}

ComplexNumber add(const ComplexNumber &x, const ComplexNumber &y)
{
    return ComplexNumber(x.getReal() + y.getReal(), x.getImaginary() + y.getImaginary());
}

ComplexNumber subtract(const ComplexNumber &x, const ComplexNumber &y)
{
    return ComplexNumber(x.getReal() - y.getReal(), x.getImaginary() - y.getImaginary());
}

ComplexNumber multiply(const ComplexNumber &x, const ComplexNumber &y)
{
    return ComplexNumber(x.getReal() * y.getReal() - x.getImaginary() * y.getImaginary(), x.getReal() * y.getImaginary() - x.getImaginary() * y.getReal());
}

void ComplexNumber::conjugate()
{
    this->imaginary *= -1;
}

ComplexNumber ComplexNumber::getConjugated() const
{
    return ComplexNumber(this->real, -this->imaginary);
}

void ComplexNumber::print() const
{
    std::cout << this->real << (this->imaginary > 0 ? " + " : " ") << this->imaginary << "i" << std::endl;
}
