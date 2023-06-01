#pragma once
#include <exception>
template <typename T>
class MyVector {
private:
	T* data;
	size_t capacity;
	size_t size;
public:
	MyVector();

	MyVector(const MyVector& other);
	MyVector<T>& operator=(const MyVector& other);

	MyVector(MyVector&& other) noexcept;
	MyVector<T>& operator=(MyVector&& other) noexcept;

	~MyVector();

private:
	void CopyFrom(const MyVector& other);
	void Free();
	void MoveFrom(MyVector&& other);
	void Resize(size_t newCapacity);

public:
	void PushBack(const T& newItem);
	void PushBack(T&& newItem);

	void PopBack();

	void SetAt(const T& newItem, size_t index);
	void SetAt(T&& newItem, size_t index);

	void PushAt(const T& newItem, size_t idx);
	void PushAt(T&& newItem, size_t idx);

	void PopAt(size_t idx);

	const T& operator[](size_t idx) const;
	T& operator[](size_t idx);
	
	bool Empty() const;
	void Clear();

	void Swap(size_t first, size_t second);

};
template <typename T>
void MyVector<T>::CopyFrom(const MyVector& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = other.data[i];
	}
}

template <typename T>
void MyVector<T>::Free() {
	delete[] this->data;
	this->data = nullptr;
	this->capacity = this->size = 0;
}

template <typename T>
void MyVector<T>::MoveFrom(MyVector&& other) {
	this->data = other.data;
	this->capacity = other.capacity;
	this->size = other.size;
	other.data = nullptr;
	other.size = other.capacity = 0;
}

template <typename T>
void MyVector<T>::Resize(size_t newCapacity) {
	T* temp = this->data;
	this->data = new T[newCapacity];
	this->capacity = newCapacity;
	for (size_t i = 0; i < capacity; i++)
	{
		this->data[i] = temp[i];
	}
	delete[] temp;

}

template <typename T>
MyVector<T>::MyVector() {
	this->capacity = 8;
	this->data = new T[capacity];
	this->size = 0;
}
template <typename T>
MyVector<T>::MyVector(const MyVector& other) {
	CopyFrom(other);
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
template <typename T>
MyVector<T>::MyVector(MyVector&& other) noexcept {
	MoveFrom(std::move(other));
}
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) noexcept {
	if (this != &other) {
		Free();
		MoveFrom(std::move(other));
	}
	return *this;
}
template <typename T>
MyVector<T>::~MyVector() {
	Free();
}
template <typename T>
void MyVector<T>::PushBack(const T& newItem) {
	if (this->size >= this->capacity)
		Resize(capacity * 2);

	this->data[size++] = newItem;
}
template <typename T>
void MyVector<T>::PushBack(T&& newItem) {
	if (this->size >= this->capacity)
		Resize(capacity * 2);

	this->data[size++] = std::move(newItem);
}
template <typename T>
void MyVector<T>::PopBack() {
	if (size == 0)
		throw std::length_error("Already empty!");

	size--;
}
template <typename T>
void MyVector<T>::SetAt(const T& newItem, size_t index) {
	if (index >= this->size)
		throw std::length_error("No such index!");

	this->data[index] = newItem;
}
template <typename T>
void MyVector<T>::SetAt(T&& newItem, size_t index) {
	if (index >= this->size)
		throw std::length_error("No such index!");

	this->data[index] = std::move(newItem);
}

template<typename T>
void MyVector<T>::PushAt(const T& newItem, size_t idx)
{
	if (idx >= this->size)
		throw std::exception("Invalid index!");

	this->data[idx] = newItem;
}

template<typename T>
void MyVector<T>::PushAt(T&& newItem, size_t idx)
{
	if (idx >= this->size)
		throw std::exception("Invalid index!");

	this->data[idx] = std::move(newItem);
}

template<typename T>
void MyVector<T>::PopAt(size_t idx)
{
	if (idx >= this->size)
		throw std::exception("Invalid index!");

	for (size_t i = idx; i < this->size - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->size--;
}

template<typename T>
const T& MyVector<T>::operator[](size_t idx) const
{
	return this->data[idx]
}

template<typename T>
T& MyVector<T>::operator[](size_t idx)
{
	return this->data[idx]
}

template<typename T>
bool MyVector<T>::Empty() const
{
	return this->size == 0;
}

template<typename T>
void MyVector<T>::Clear()
{
	if (this->size == 0)
		throw std::exception("Already empty!");

	this->size = 0;
}

template<typename T>
void MyVector<T>::Swap(size_t first, size_t second)
{
	if (second >= this->size || first >= this->size)
		throw std::exception("Invalid indexes!");

	std::swap(this->data[first], this->data[second]);
}
