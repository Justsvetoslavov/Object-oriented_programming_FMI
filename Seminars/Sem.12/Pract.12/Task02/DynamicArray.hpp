#pragma once
#include <exception>
#include <stdexcept>
#include <utility>

#include "MyString.h"

/**
 * @source https://github.com/Angeld55/Object-oriented_programming_FMI/blob/master/Week%2009/DynamicArrayOfA%20(with%20move)/DynamicArrayOfA.h
 * Manual template extension
 */

template <typename T>
class DynamicArray
{
	T* arr = nullptr;
	size_t size = 0;
	size_t capacity = 4;
	void moveFrom(DynamicArray&& other);
public:
	DynamicArray();
	DynamicArray(size_t capacity);
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);
	~DynamicArray();

	DynamicArray(DynamicArray&& other) noexcept;
	DynamicArray& operator=(DynamicArray&& other) noexcept;

private:
	void copyFrom(const DynamicArray& other);
	void free();
	void resize(size_t newCap);

public:
	void pushBack(const T& newElem); //add a new element in the end
	void pushBack(T&& newElem); //add a new element in the end

	void popBack(); //removes the last element

	void removeAt(size_t index);

	void setAtIndex(const T& element, size_t index);
	void setAtIndex(T&& element, size_t index);

	size_t getSize() const;
	bool isEmpty() const;

	bool contains(const T& element) const;

	const T& operator[](size_t index) const;
	T& operator[](size_t index);
};

template <typename T>
DynamicArray<T>::DynamicArray() : DynamicArray(8) {}

static size_t closestPowerOfAwo(size_t n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;

	return n + 1;
};

template <typename T>
DynamicArray<T>::DynamicArray(const size_t capacity) : size(0)
{
	this->capacity = closestPowerOfAwo(capacity);
	arr = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
{
	copyFrom(other);
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	free();
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
void DynamicArray<T>::copyFrom(const DynamicArray<T>& other)
{

	arr = new T[other.capacity];

	for (size_t i = 0; i < other.size; i++)
		arr[i] = other.arr[i];

	size = other.size;
	capacity = other.capacity;
}

template <typename T>
void DynamicArray<T>::moveFrom(DynamicArray<T>&& other)
{
	arr = other.arr;
	other.arr = nullptr;
	size = other.size;
}

template <typename T>
void DynamicArray<T>::free()
{
	delete[] arr;
}

template <typename T>
void DynamicArray<T>::resize(size_t newCap)
{
	T* temp = arr;
	arr = new T[newCap];

	for (size_t i = 0; i < size; i++)
		//arr[i] = temp[i]; // UniquePointer doesn't have lvalue op=
		arr[i] = std::move(temp[i]);

	capacity = newCap;
	delete[] temp;
}

template <typename T>
void DynamicArray<T>::pushBack(const T& newElem)
{
	if (size >= capacity)
		resize(capacity * 2);

	arr[size++] = newElem;
}

template <typename T>
void DynamicArray<T>::pushBack(T&& newElem)
{
	if (size >= capacity)
		resize(capacity * 2);

	arr[size++] = std::move(newElem); //move op =
}

template <typename T>
void DynamicArray<T>::popBack()
{
	if (size)
		size--;
	else
		throw std::length_error("Already empty!");

	if (size * 4 <= capacity && capacity > 1)
		resize(capacity / 2);
}

/**
 * Manual extension
 */
template <typename T>
void DynamicArray<T>::removeAt(size_t index)
{
	if (index < 0 || index >= this->size)
	{
		throw std::range_error("Element index out of range.");
	}

	for (size_t i = index; i < this->size - 1; i++)
	{
		this->arr[i] = this->arr[i + 1];
	}
	--this->size;
}

template <typename T>
void DynamicArray<T>::setAtIndex(const T& element, size_t index)
{
	if (index >= size)
		throw std::length_error("No such index!");

	arr[index] = element;
}

template <typename T>
void DynamicArray<T>::setAtIndex(T&& element, size_t index)
{
	if (index >= size)
		throw std::length_error("No such index!");

	arr[index] = std::move(element); //move op =
}

template <typename T>
size_t DynamicArray<T>::getSize() const
{
	return size;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const
{
	return size == 0;
}

/**
 * Manual extension
 * T needs op==
 */
template <typename T>
bool DynamicArray<T>::contains(const T& element) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->arr[i] == element) return true;
	}
	return false;
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t index) const
{
	if (index > size)
		throw std::out_of_range("Out of range!");
	return arr[index];
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index)
{
	if (index > size)
		throw std::out_of_range("Out of range!");
	return arr[index];
}