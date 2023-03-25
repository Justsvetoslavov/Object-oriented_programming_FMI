#pragma once

#include <iostream>

class ComplexNumber {
    int real, imaginary;
public:
    ComplexNumber();

    ComplexNumber(int real, int imaginary);

    bool isEqual(const ComplexNumber &num) const;

    void add(const ComplexNumber &num);

    void minus(const ComplexNumber &num);

    void multiply(const ComplexNumber &num);

    void conjugate();

    ComplexNumber &operator=(const ComplexNumber &num);

    ComplexNumber getConjugated() const;

    void print() const;
};
