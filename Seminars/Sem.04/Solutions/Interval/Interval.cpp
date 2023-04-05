#include <iostream>
#include <algorithm>
#include "Interval.h"

bool IsPrime(int n) {
	double temp = sqrt(n);
	for (size_t i = 2; i <= temp; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

bool IsPalindorme(int n) {
	int reversed = 0, lastDigit;

	while (n != 0) {
		lastDigit = n % 10;
		(reversed *= 10) += lastDigit;
		n /= 10;
	}

	return n == reversed;
}

bool ContainsOnlyDistinctNumbers(int n) {
	bool digits[10];
	for (size_t i = 0; i < 10; i++) {
		digits[i] = false;
	}

	int lastDigit;
	while (n != 0) {
		lastDigit = n % 10;
		if (digits[lastDigit]) {
			return false;
		}
		digits[n % 10] = true;
		n /= 10;
	}
	return true;
}

size_t Interval::CountNumbersInIntervalCondition(bool(*pred)(int)) const {
	size_t count = 0;
	for (int i = a; i <= b; i++) {
		if (pred(i)) {
			count++;
		}
	}
	return count;
}

Interval::Interval() : Interval(0, 0) {}

Interval::Interval(int a, int b) {
	if (a > b) {
		a = b = 0;
	}

	this->a = a;
	this->b = b;
}

int Interval::getA() const {
	return a;
}

int Interval::getB() const {
	return b;
}

bool Interval::setA(int a) {
	if (a > b) {
		return false;
	}
	this->a = a;
	return true;
}

bool Interval::setB(int b) {
	if (b < a) {
		return false;
	}
	this->b = b;
	return true;
}

size_t Interval::GetLength() const {
	return b - a + 1;
}

bool Interval::IsMemberOfInterval(int x) const {
	return (a <= x && x <= b);
}

size_t Interval::CalcPrimeNumbersInTheInterval() const {
	return CountNumbersInIntervalCondition(isPrime);
}

size_t Interval::CalcPalindromicNumbersInTheInterval() const {
	return CountNumbersInIntervalCondition(isPalindorme);
}

size_t Interval::CalcDiffrentDigitNumbersInTheInverval() const {
	return CountNumbersInIntervalCondition(containsOnlyDistinctNumbers);
}

bool Interval::AreStartAndEndPowersOfTwo() const {
	return (a == 0 || (a & a - 1) == 0) && (b == 0 || (b & b - 1) == 0);
}

Interval Interval::Intersect(const Interval& other) const {
	if (b < other.getA() || a > other.getB()) {
		return Interval(0, 0);
	}

	int newA = std::max(a, other.getA());
	int newB = std::min(b, other.getB());

	return Interval(newA, newB);
}

bool Interval::IsSuperInterval(const Interval& other) const {
	return a <= other.getA() && b >= other.getB();
}
