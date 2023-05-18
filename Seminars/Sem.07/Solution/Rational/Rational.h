#pragma once
#include <iostream>

class Rational {
	int num;
	int denom;
public:
	Rational();
	Rational(int, int);

	int GetNuminator() const;
	int GetDenominator() const;

	void SetNuminator(int);
	void SetDenominator(int);

	void rationalize();

	void Print() const;

	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);

	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);
};

Rational operator+(const Rational&, const Rational&);
Rational operator-(const Rational&, const Rational&);
Rational operator*(const Rational&, const Rational&);
Rational operator/(const Rational&, const Rational&);

bool operator==(const Rational&, const Rational&);
