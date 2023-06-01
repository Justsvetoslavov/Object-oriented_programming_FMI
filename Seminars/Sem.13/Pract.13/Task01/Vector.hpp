#pragma once
#include <iostream>
#include <stdexcept>

namespace globals {
	const int RESIZE_COUNT = 4;
}

template <typename T>
class Vector
{
	T* data = nullptr;
	size_t count = 0;
	size_t capacity = globals::RESIZE_COUNT;

	void free();
	void copyFrom(const Vector<T>& other);
	void moveFrom(Vector<T>&& other);
	void resize();
public:
	Vector();
	Vector(size_t capacity);

	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);

	Vector(Vector<T>&& other);
	Vector<T>& operator=(Vector<T>&& other);

	~Vector();

	void pushBack(const T& element);
	void pushAt(size_t idx, const T& element);

	void popBack();
	void popAt(size_t idx);

	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;
	size_t length() const;

	bool contains(const T& element);
	bool empty();
	void clear();

	void swap(size_t lIdx, size_t rIdx);
};

template <typename T>
void Vector<T>::free() {
	delete[] data;
	data = nullptr;
	count = 0;
	capacity = globals::RESIZE_COUNT;
}

template <typename T>
void Vector<T>::copyFrom(const Vector<T>& other) {
	count = other.count;
	capacity = other.capacity;

	data = new T[capacity];
	for (size_t i = 0; i < count; i++)
		data[i] = other.data[i];
}

template <typename T>
void Vector<T>::moveFrom(Vector<T>&& other) {
	count = other.count;
	other.count = 0;

	capacity = other.capacity;
	other.capacity = globals::RESIZE_COUNT;

	data = other.data;
	other.data = nullptr;
}

template<typename T>
inline void Vector<T>::resize()
{
	capacity += globals::RESIZE_COUNT;

	T* newData = new T[capacity];
	for (size_t i = 0; i < count; i++)
		newData[i] = data[i];

	delete[] data;
	data = newData;
}

template<typename T>
inline Vector<T>::Vector()
{
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(size_t capacity)
{
	data = new T[capacity];
}

template<typename T>
inline Vector<T>::Vector(const Vector<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Vector<T>::Vector(Vector<T>&& other)
{
	moveFrom(std::move(other));
}

template<typename T>
inline Vector<T>& Vector<T>::operator=(Vector<T>&& other)
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline Vector<T>::~Vector()
{
	free();
}

template<typename T>
inline void Vector<T>::pushBack(const T& element)
{
	if (count == capacity)
		resize();

	element[count++] = element;
}

template<typename T>
inline void Vector<T>::pushAt(size_t idx, const T& element)
{
	if (idx >= count)
		throw std::invalid_argument("Index out of range");

	if (count == capacity)
		resize();

	for (size_t i = idx; i < count - 1; i++)
		data[i + 1] = data[i];

	data[idx] = element;
	count++;
}

template<typename T>
inline void Vector<T>::popBack()
{
	if (count == 0)
		throw std::runtime_error("Vector is empty");

	count--;
}

template<typename T>
inline void Vector<T>::popAt(size_t idx)
{
	if (idx >= count)
		throw std::invalid_argument("Index out of range");

	for (size_t i = idx; i < count - 1; i++)
		data[i] = data[i + 1];

	count--;
}

template<typename T>
inline T& Vector<T>::operator[](size_t idx)
{
	if (idx >= count)
		throw std::invalid_argument("Index out of range");

	return data[idx];
}

template<typename T>
inline const T& Vector<T>::operator[](size_t idx) const
{
	if (idx >= count)
		throw std::invalid_argument("Index out of range");

	return data[idx];
}

template<typename T>
inline size_t Vector<T>::length() const
{
	return count;
}

template<typename T>
inline bool Vector<T>::contains(const T& element)
{
	for (size_t i = 0; i < count; i++)
		if (data[i] == element)
			return true;

	return false;
}

template<typename T>
inline bool Vector<T>::empty()
{
	return count == 0;
}

template<typename T>
inline void Vector<T>::clear()
{
	count = 0;
}

template<typename T>
inline void Vector<T>::swap(size_t lIdx, size_t rIdx)
{
	if (lIdx >= count || rIdx >= count)
		throw std::invalid_argument("Index out of range");

	T temp = data[lIdx];
	data[lIdx] = data[rIdx];
	data[rIdx] = temp;
}
