#include "Complex.h"

Complex::Complex()
{
	realPart = 0;
	imgPart = 0;
}

Complex::Complex(const int realPart, const int imgPart)
{
	this->realPart = realPart;
	this->imgPart = imgPart;
}

bool Complex::isEqual(const Complex& compl1)const
{
	return (this->realPart == compl1.realPart && this->imgPart == compl1.imgPart);
}

Complex Complex::add(const Complex& compl1)const
{
	return Complex (this->realPart + compl1.realPart, this->imgPart + compl1.imgPart);
}

Complex Complex::subtract(const Complex& compl1)const
{
	return Complex (this->realPart - compl1.realPart, this->imgPart - compl1.imgPart);
}

Complex Complex::multiply(const Complex& compl1)const
{
	return Complex ((this->realPart * compl1.realPart) - (this->imgPart * compl1.imgPart), 
				 (this->realPart * compl1.imgPart) + (this->imgPart * compl1.realPart));
}

void Complex::conjugate()
{
	this->imgPart = -(this->imgPart);
}

Complex Complex::getConjugated()const
{
	return Complex (this->realPart, -(this->imgPart));
}

void Complex::print()const
{
	std::cout << this->realPart << " + " << this->imgPart << "i" << std::endl;
}