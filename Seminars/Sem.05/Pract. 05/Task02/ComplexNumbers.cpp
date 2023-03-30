#include "ComplexNumbers.h"
#include "GlobalConstants.h"
#include <iostream>
#include <cmath>

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0) {}

ComplexNumber::ComplexNumber(double real, double imag) {
	this->real = real;
	this->imag = imag;
}

double ComplexNumber::GetReal() const {
	return this->real;
}

double ComplexNumber::GetImag() const {
	return this->imag;
}

const ComplexNumber& ComplexNumber::Multiply(const ComplexNumber& num) const {
	ComplexNumber result;
	result.real = (num.GetReal() * this->GetReal() - num.GetImag() * this->GetImag());
	result.imag = (num.GetReal() * this->GetImag() + num.GetImag() * this->GetReal());
	return result;
}

void ComplexNumber::Conjugate() {
	if (this->imag < 0)
		this->imag = abs(this->imag);
	else
		this->imag = -this->imag;
}

const ComplexNumber& ComplexNumber::GetConjugated(const ComplexNumber& num) {
	ComplexNumber copyNum = num;
	copyNum.Conjugate();
	return copyNum;
}

bool ComplexNumber::IsEqual(const ComplexNumber& other) const {
	return abs(this->real - other.real) < GlobalConstants::EPSILON
		&& abs(this->imag - other.imag) < GlobalConstants::EPSILON;
}

const ComplexNumber& ComplexNumber::Add(const ComplexNumber& other) const {
	ComplexNumber sum;
	sum.real = this->real + other.real;
	sum.imag = this->imag + other.imag;
	return sum;
}

const ComplexNumber& ComplexNumber::Subtract(const ComplexNumber& other) const {
	ComplexNumber sub;
	sub.real = this->real + other.real;
	sub.imag = this->imag + other.imag;
	return sub;
}

void ComplexNumber::Print() const {
	std::cout << "Your complex number is: ";
	std::cout << this->GetReal() << ' ';
	if (this->imag > 0)
		std::cout << "+ ";
	std::cout << this->GetImag() << "i\n";
}
