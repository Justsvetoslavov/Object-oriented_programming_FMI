#pragma once

class ComplexNumber
{
    double real;
    double imaginary;
    
    friend ComplexNumber add(const ComplexNumber &, const ComplexNumber &);
    friend ComplexNumber subtract(const ComplexNumber &, const ComplexNumber &);
    friend ComplexNumber multiply(const ComplexNumber &, const ComplexNumber &);

public:
    ComplexNumber();
    ComplexNumber(const double, const double);

    double getReal() const;
    double getImaginary() const;

    bool isEqual(const ComplexNumber &, const ComplexNumber &) const;
    void conjugate();
    ComplexNumber getConjugated() const;
    void print() const;
};

ComplexNumber add(const ComplexNumber &, const ComplexNumber &);
ComplexNumber subtract(const ComplexNumber &, const ComplexNumber &);
ComplexNumber multiply(const ComplexNumber &, const ComplexNumber &);
