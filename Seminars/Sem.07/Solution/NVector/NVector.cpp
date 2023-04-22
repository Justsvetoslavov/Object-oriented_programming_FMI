#include "NVector.h"

NVector::NVector(size_t size) : size(size) {
	data = new int[size];

	for (size_t i = 0; i < size; ++i) {
		data[i] = 0;
	}
}

NVector::NVector(const NVector& other) {
	CopyFrom(other);
}

NVector& NVector::operator=(const NVector& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}

	return *this;
}

NVector::~NVector() {
	Free();
}

int NVector::operator[](size_t index) const {
	if (index < 0 || index >= size) {
		throw "Invalid index";
	}

	return data[index];
}

int& NVector::operator[](size_t index) {
	if (index < 0 || index >= size) {
		throw "Invalid index";
	}

	return data[index];
}

NVector& NVector::operator+=(const NVector& other) {
	if (size != other.size) {
		throw "Vectors should be of the same size";
	}

	for (size_t i = 0; i < size; ++i) {
		data[i] += other.data[i];
	}

	return *this;
}

NVector& NVector::operator-=(const NVector& other) {
	if (size != other.size) {
		throw "Vectors should be of the same size";
	}

	for (size_t i = 0; i < size; ++i) {
		data[i] -= other.data[i];
	}

	return *this;
}

NVector& NVector::operator*=(size_t scalar) {
	for (size_t i = 0; i < size; ++i) {
		data[i] *= scalar;
	}

	return *this;
}

size_t NVector::GetSize() const {
	return size;
}

//size_t NVector::operator~() const { // return size
//	return size;
//}

void NVector::Print() const {
	std::cout << "{ ";
	for (size_t i = 0; i < size; ++i) {
		std::cout << data[i] << " ,";
	}
	std::cout << " }";
}

std::ostream& operator<<(std::ostream& os, const NVector& v) {
	os << "{ ";
	for (size_t i = 0; i < v.size; ++i) {
		os << v[i] << " ,";
	}
	os << " }";
	// { 1 ,2 ,4 }

	return os;
}

std::istream& operator>>(std::istream& in, NVector& v) {
	for (size_t i = 0; i < v.size; ++i) {
		in >> v[i];
	}

	return in;
}

void NVector::CopyFrom(const NVector& other) {
	size = other.size;
	data = new int[size];

	for (size_t i = 0; i < size; ++i) {
		data[i] = other.data[i];
	}
}

void NVector::Free() {
	delete[] data;
}

NVector operator+(const NVector& lhs, const NVector& rhs) {
	NVector temp(lhs);
	temp += rhs;
	return temp;
}

NVector operator-(const NVector& lhs, const NVector& rhs) {
	NVector temp(lhs);
	temp -= rhs;
	return temp;
}

NVector operator*(size_t scalar, const NVector& rhs) {
	NVector temp(rhs);
	temp *= scalar;
	return temp;
}

NVector operator*(const NVector& lhs, size_t scalar) {
	return scalar * lhs; //operator*(scalar, lhs)
}

//bool operator||(const NVector& lhs, const NVector& rhs) {
//	if (~lhs != ~rhs) return false; //compare sizes
//
//	for (size_t i = 0; i < ~lhs - 1; ++i) {
//		if (lhs[i] * rhs[i + 1] != lhs[i + 1] * rhs[i]) {
//			return false;
//		}
//	}
//
//	return true;
//}

bool IsParralel(const NVector& lhs, const NVector& rhs) {
	if (lhs.size != rhs.size) return false; //compare sizes

	for (size_t i = 0; i < lhs.size - 1; ++i) {
		if (lhs[i] * rhs[i + 1] != lhs[i + 1] * rhs[i]) {
			return false;
		}
	}

	return true;
}

//bool operator|=(const NVector& lhs, const NVector& rhs) {
//	if (~lhs != ~rhs) return false;
//
//	size_t result = 0;
//	for (size_t i = 0; i < ~lhs; ++i) {
//		result += lhs[i] * rhs[i];
//	}
//
//	return result == 0;
//}

bool IsPerpendicular(const NVector& lhs, const NVector& rhs) {
	if (lhs.size != rhs.size) return false;

	size_t result = 0;
	for (size_t i = 0; i < lhs.size; ++i) {
		result += lhs[i] * rhs[i];
	}

	return result == 0;
}