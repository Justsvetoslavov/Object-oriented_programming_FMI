#pragma once

class ComplexNumber
{
private:
	double real;
	double imag;
public:
	ComplexNumber();
	ComplexNumber(double real, double imag);

	double GetReal() const;
	double GetImag() const;

	bool IsEqual(const ComplexNumber& other) const;
	const ComplexNumber& Add(const ComplexNumber& other) const;
	const ComplexNumber& Subtract(const ComplexNumber& other) const;
	const ComplexNumber& Multiply(const ComplexNumber& num) const;
	void Conjugate();
	const ComplexNumber& GetConjugated(const ComplexNumber& num);
	void Print() const;
};



