#include "SetOFNumbers.h"

#include <iostream>

#include <assert.h>

SetOfNumbers::SetOfNumbers(unsigned n) {
	data = new unsigned char[n / 8 + 1]; //10

	for (size_t i = 0; i < (n / 8 + 1); ++i) {
		data[i] = 0;
	}

	maxNumber = n - 1;
}

SetOfNumbers::SetOfNumbers(const SetOfNumbers& other) {
	CopyFrom(other);
}

SetOfNumbers& SetOfNumbers::operator=(const SetOfNumbers& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}

	return *this;
}

SetOfNumbers::~SetOfNumbers() {
	Free();
}

void SetOfNumbers::CopyFrom(const SetOfNumbers& other) {
	unsigned bucketCount = other.GetBucketCount();
	data = new unsigned char[bucketCount];

	for (size_t i = 0; i < bucketCount; ++i) {
		data[i] = other.data[i];
	}

	maxNumber = other.maxNumber;
}

void SetOfNumbers::Free() {
	delete[] data;
	data = nullptr;
}

unsigned  SetOfNumbers::GetBucketIndex(unsigned number) const {
	return number / 8;
}

unsigned  SetOfNumbers::GetBucketCount() const {
	return (maxNumber / 8 + 1);
}

unsigned char  SetOfNumbers::GetMask(unsigned number) const {
	unsigned indexInBucket = number % 8; //

	char mask = 1; // 00000001 -> 000100000

	mask <<= (7 - indexInBucket); //7 - 3 -> 4 -> 000100000

	return mask;
}

bool SetOfNumbers::Contains(unsigned number) const {
	unsigned bucketIndex = GetBucketIndex(number);
	unsigned mask = GetMask(number);

	return (mask & data[bucketIndex]);
}

bool SetOfNumbers::AddNumber(unsigned number) {
	if (number > maxNumber || Contains(number)) return false;

	unsigned bucketIndex = GetBucketIndex(number);
	unsigned mask = GetMask(number);

	data[bucketIndex] |= mask;
	return true;
}

bool SetOfNumbers::RemoveNumber(unsigned number) {
	if (number > maxNumber || !Contains(number)) return false;

	unsigned bucketIndex = GetBucketIndex(number);
	unsigned mask = GetMask(number);

	data[bucketIndex] ^= mask;
	
	return true;
}

void SetOfNumbers::print() const {
	std::cout << "{ ";
	unsigned temp = 0;
	
	for (size_t i = 0; i < GetBucketCount(); ++i) {
		for (unsigned char j = 128; j >= 1; j >>= 1) {
			if (data[i] & j) {
				std::cout << temp << " ";
			}
			++temp;
		}
	}

	std::cout << " }\n";
}

SetOfNumbers UnionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs) {
	assert(lhs.maxNumber == rhs.maxNumber);

	SetOfNumbers result(lhs.maxNumber + 1);

	for (size_t i = 0; i < lhs.GetBucketCount(); ++i) {
		result.data[i] = (lhs.data[i] | rhs.data[i]);
	}

	return result;
}

SetOfNumbers IntersectionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs) {
	assert(lhs.maxNumber == rhs.maxNumber);

	SetOfNumbers result(lhs.maxNumber + 1);

	for (size_t i = 0; i < lhs.GetBucketCount(); ++i) {
		result.data[i] = (lhs.data[i] & rhs.data[i]);
	}

	return result;
}
