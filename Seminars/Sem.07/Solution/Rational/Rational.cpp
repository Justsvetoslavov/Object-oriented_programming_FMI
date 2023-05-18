#include "Rational.h"

size_t GetGcd(size_t a, size_t b) {
	if (a < b) {
		std::swap(a, b);
	}

	while (b != 0) {
		size_t temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

void Rational::rationalize() {
	size_t gcd = GetGcd(abs(num), abs(denom));
	num /= gcd;
	denom /= gcd;
}

Rational::Rational() : Rational(1, 1) {}

Rational::Rational(int num, int denom) {
	SetNuminator(num);
	SetDenominator(denom);
	rationalize();
}
 
int Rational::GetNuminator() const {
	return num;
}

int Rational::GetDenominator() const {
	return denom;
}

void Rational::SetNuminator(int num) {
	this->num = num;
}

void Rational::SetDenominator(int denom) {
	if (denom == 0) {
		denom = 1;
	}

	this->denom = denom;
}

void Rational::Print() const {
	std::cout << num << "/" << denom << std::endl;
}

Rational& Rational::operator+=(const Rational& other) {
	//*this *= other; //Rational 

	int otherNum = other.num * denom;

	num *= other.denom; //int
	denom *= other.denom; //int

	num += otherNum;
	rationalize();

	return *this;
}

Rational& Rational::operator-=(const Rational& other) {
	Rational temp(-other.num, other.denom);
	*this += temp;

	return *this;
}

Rational& Rational::operator*=(const Rational& other) {
	num *= other.num;
	denom *= other.denom;
	rationalize();

	return *this;
}

Rational& Rational::operator/=(const Rational& other) {
	//num *= other.denom;
	//denom *= other.num;
	//rationalize();
	//return *this;

	return (*this) *= Rational(other.denom, other.num);
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
	//os << r.num << "/" << r.denom;
	//return os;

	return os << r.num << "/" << r.denom;
}

std::istream& operator>>(std::istream& in, Rational& r) {
	return in >> r.num >> r.denom;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational temp(lhs);
	temp += rhs;
	return temp;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational temp(lhs);
	temp -= rhs;
	return temp;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational temp(lhs);
	temp *= rhs;
	return temp;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational temp(lhs);
	temp /= rhs;
	return temp;
}

bool operator==(const Rational& lhs, const Rational& rhs) {
	return lhs.GetNuminator() == rhs.GetNuminator() && lhs.GetDenominator() == rhs.GetDenominator();
}