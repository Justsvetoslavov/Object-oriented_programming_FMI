#include "ComplexNum.hpp"
#include "iostream"
using std::cin;
using std::cout;
using std::endl;

ComplexNum::ComplexNum(double a, double b)
{
	this->a = a;
	this->b = b;
	cout << "Successful created complexNum" << endl;
}

void ComplexNum::setA(double a)
{
	this->a = a;
}

void ComplexNum::setB(double b)
{
	this->b = b;
}

double ComplexNum::getA() const
{
	return this->a;
}

double ComplexNum::getB() const
{
	return this->b;
}

bool ComplexNum::isEqual(const ComplexNum& complexNum1, const ComplexNum& complexNum2)
{
	return complexNum1.a == complexNum2.a && complexNum1.b == complexNum2.b;
}

ComplexNum ComplexNum::add(const ComplexNum& complexNum1, const ComplexNum& complexNum2)
{
	ComplexNum result;
	result.a = complexNum1.a + complexNum2.a;
	result.b = complexNum1.b + complexNum2.b;
	return result;
}

ComplexNum ComplexNum::substract(const ComplexNum& complexNum1, const ComplexNum& complexNum2)
{
	ComplexNum result;
	result.a = complexNum1.a - complexNum2.a;
	result.b = complexNum1.b - complexNum2.b;
	return result;
}

ComplexNum ComplexNum::multiply(const ComplexNum& complexNum1, const ComplexNum& complexNum2)
{
	ComplexNum result;
	result.a = (complexNum1.a * complexNum2.a) - (complexNum1.b * complexNum2.b);
	result.b = (complexNum1.a * complexNum2.b) + (complexNum1.b * complexNum2.a);
	return result;
}

ComplexNum ComplexNum::conjugate(ComplexNum& complexNum)
{
	complexNum.b = complexNum.b * (-1);
	return complexNum;
}

ComplexNum ComplexNum::getConjugated(ComplexNum& complexNum)
{
	complexNum.b = complexNum.b * (-1);
	return complexNum;
}

void ComplexNum::print(const ComplexNum& complexNum)
{
	cout << complexNum.a << " + " << complexNum.b << "i" << endl;
}


