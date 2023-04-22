#pragma once
#include <iostream>

class NVector {
private:
	int* data = nullptr;
	size_t size = 0;
public:
	NVector() = delete;
	NVector(size_t);
	NVector(const NVector&);
	NVector& operator=(const NVector&);
	~NVector();

	int operator[](size_t) const;
	int& operator[](size_t);

	NVector& operator+=(const NVector&);
	NVector& operator-=(const NVector&);
	NVector& operator*=(size_t);

	size_t GetSize() const;
	//size_t operator~() const; // return size

	void Print() const;

	friend bool IsParralel(const NVector&, const NVector&);
	friend bool IsPerpendicular(const NVector&, const NVector&);

	friend std::ostream& operator<<(std::ostream& os, const NVector&);
	friend std::istream& operator>>(std::istream& in, NVector&);
private:
	void CopyFrom(const NVector&);
	void Free();
};

NVector operator+(const NVector&, const NVector&);
NVector operator-(const NVector&, const NVector&);
NVector operator*(size_t, const NVector&);
NVector operator*(const NVector&, size_t);

//bool operator||(const NVector&, const NVector&);
//bool operator|=(const NVector&, const NVector&);