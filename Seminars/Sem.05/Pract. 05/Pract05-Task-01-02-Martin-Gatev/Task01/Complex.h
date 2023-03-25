#pragma once

#include<iostream>

class Complex {
private:
	int realPart;
	int imgPart;
public:
	Complex();
	Complex(const int realPart, const int imgPart);

	bool isEqual(const Complex& compl1)const;
	Complex add(const Complex& compl1)const;
	Complex subtract(const Complex& compl1)const;
	Complex multiply(const Complex& compl1)const;
	void conjugate();
	Complex getConjugated()const;
	void print()const;
};