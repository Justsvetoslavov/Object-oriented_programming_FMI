#pragma once

class SetOfNumbers {
private:
	unsigned char* data; 
	unsigned maxNumber;
public:
	SetOfNumbers() = default;
	SetOfNumbers(unsigned n);
	SetOfNumbers(const SetOfNumbers& other);
	SetOfNumbers& operator=(const SetOfNumbers& other);
	~SetOfNumbers();

	bool Contains(unsigned number) const;
	bool AddNumber(unsigned number);
	bool RemoveNumber(unsigned number);

	void print() const;

	friend SetOfNumbers UnionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs);
	friend SetOfNumbers IntersectionOfSets(const SetOfNumbers& lhs, const SetOfNumbers& rhs);
private:
	unsigned GetBucketIndex(unsigned number) const;
	unsigned GetBucketCount() const;
	unsigned char GetMask(unsigned number) const;

    void CopyFrom(const SetOfNumbers& other);
	void Free();
};