#pragma once

#include <iostream>

template<typename T, typename U>
class PairOfOptionals {
private:
	T* first = nullptr;
	U* second = nullptr;
public:
	PairOfOptionals() = default;
	PairOfOptionals(const T& fData, const U& sData);
	PairOfOptionals(const PairOfOptionals<T, U>& other);
	PairOfOptionals(PairOfOptionals<T, U>&& other);
	PairOfOptionals <T, U>& operator=(const PairOfOptionals<T, U>& other);
	PairOfOptionals <T, U>& operator=(PairOfOptionals<T, U>&& other);
	~PairOfOptionals();

	void SetFirst(const T& data);
	void SetSecond(const U& data);

	const T& GetFirst() const;
	const U& GetSecond() const;

	void RemoveFirst();
	void RemoveSecond();

	bool ContainsFirst() const;
	bool ContainsSecond() const;
	bool IsEmpty() const;

	friend bool operator==(const PairOfOptionals<T, U>& lhs, const PairOfOptionals<T, U>& rhs);
private:
	void CopyFrom(const PairOfOptionals<T, U>& other);
	void MoveFrom(PairOfOptionals<T, U>&& other);
	void Free();
};

template<typename S>
bool CompareValues(const S* ptr1, const S* ptr2) {
	return (ptr1 == nullptr && ptr2 == nullptr) || (ptr1 != nullptr && ptr2 != nullptr && *ptr1 == *ptr2);
}

template<typename T, typename U>
bool operator==(const PairOfOptionals<T, U>& lhs , const PairOfOptionals<T, U>& rhs) {
	return CompareValues<T>(lhs.first, rhs.first) && CompareValues<U>(lhs.second, rhs.second);
}

template<typename T, typename U>
bool operator!=(const PairOfOptionals<T, U>& lhs, const PairOfOptionals<T, U>& rhs) {
	return !(lhs == rhs);
}

template<typename T, typename U>
PairOfOptionals<T, U>::PairOfOptionals(const T& fData, const U& sData) {
	first = new T(fData);
	second = new U(sData);
}

template<typename T, typename U>
void PairOfOptionals<T, U>::CopyFrom(const PairOfOptionals<T, U>& other) {
	first = new T(*other.first);
	second = new U(*other.second);
}

template<typename T, typename U>
void PairOfOptionals<T, U>::MoveFrom(PairOfOptionals<T, U>&& other) {
	first = other.first;
	second = other.second;

	other.first = other.second = nullptr;
}

template<typename T, typename U>
void PairOfOptionals<T, U>::Free() {
	delete first;
	delete second;

	first = second = nullptr;
}

template<typename T, typename U>
PairOfOptionals<T, U>::PairOfOptionals(const PairOfOptionals<T, U>& other) {
	CopyFrom(other);
}

template<typename T, typename U>
PairOfOptionals<T, U>::PairOfOptionals(PairOfOptionals<T, U>&& other) {
	MoveFrom(std::move(other));
}

template<typename T, typename U>
PairOfOptionals < T, U>& PairOfOptionals<T, U>::operator=(const PairOfOptionals<T, U>& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}

	return *this;
}

template<typename T, typename U>
PairOfOptionals < T, U>& PairOfOptionals<T, U>::operator=(PairOfOptionals<T, U>&& other) {
	if (this != &other) {
		Free();
		MoveFrom(std::move(other));
	}

	return *this;
}

template<typename T, typename U>
PairOfOptionals<T, U>::~PairOfOptionals() {
	Free();
}

template<typename T, typename U>
void PairOfOptionals<T, U>::SetFirst(const T& data) {
	delete first;
	first = new T(data);
}

template<typename T, typename U>
void PairOfOptionals<T, U>::SetSecond(const U& data) {
	delete second;
	second = new U(data);
}

template<typename T, typename U>
const T& PairOfOptionals<T, U>::GetFirst() const {
	if (!ContainsFirst()) {
		throw std::logic_error("No element!");
	}

	return *first;
}

template<typename T, typename U>
const U& PairOfOptionals<T, U>::GetSecond() const {
	if (!ContainsSecond()) {
		throw std::logic_error("No element!");
	}

	return *second;
}

template<typename T, typename U>
void PairOfOptionals<T, U>::RemoveFirst() {
	delete first;
	first = nullptr;
}

template<typename T, typename U>
void PairOfOptionals<T, U>::RemoveSecond() {
	delete second;
	second = nullptr;
}

template<typename T, typename U>
bool PairOfOptionals<T, U>::ContainsFirst() const {
	return first != nullptr;
}

template<typename T, typename U>
bool PairOfOptionals<T, U>::ContainsSecond() const {
	return second != nullptr;
}

template<typename T, typename U>
bool PairOfOptionals<T, U>::IsEmpty() const {
	return !(ContainsFirst() || ContainsSecond());
}