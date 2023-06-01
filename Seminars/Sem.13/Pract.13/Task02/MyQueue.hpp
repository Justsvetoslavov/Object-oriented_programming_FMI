#pragma once
#include <exception>

template <typename T>
class MyQueue {
private:
	T* data;
	size_t size;
	size_t capacity;

	size_t get;
	size_t put;

public:
	MyQueue();
	MyQueue(const MyQueue<T>& other);
	MyQueue<T>& operator=(const MyQueue<T>& other);

	MyQueue(MyQueue<T>&& other);
	MyQueue<T>& operator=(MyQueue<T>&& other);

	~MyQueue();

	void Push(const T& other);
	void Push(T&& other);

	const T& Peek() const;
	void Pop();
	bool IsEmpty() const;

private:
	void CopyFrom(const MyQueue<T>& other);
	void Free();
	void MoveFrom(MyQueue<T>&& other);
	void Resize();
};

template <typename T>
MyQueue<T>::MyQueue() {
	this->capacity = 4;
	this->data = new T[capacity];
	this->size = 0;
	this->get = this->put = 0;
}
template <typename T>
MyQueue<T>::MyQueue(const MyQueue<T>& other) {
	CopyFrom(other);
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(const MyQueue<T>& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}

template <typename T>
MyQueue<T>::MyQueue(MyQueue<T>&& other) {
	MoveFrom(std::move(other));
}

template <typename T>
MyQueue<T>& MyQueue<T>::operator=(MyQueue<T>&& other) {
	if (this != &other) {
		Free();
		MoveFrom(std::move(other));
	}
	return *this;
}

template <typename T>
MyQueue<T>::~MyQueue() {
	Free();
}

template <typename T>
void MyQueue<T>::CopyFrom(const MyQueue<T>& other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->get = other.get;
	this->put = other.put;
	this->data = new T[this->capacity];
	for (size_t i = 0; i < capacity; i++)
	{
		this->data[i] = other.data[i];
	}
}

template <typename T>
void MyQueue<T>::Free() {
	delete[] this->data;
	this->data = nullptr;
	this->capacity = this->size = 0;
	this->put = this->get = 0;
}

template <typename T>
void MyQueue<T>::MoveFrom(MyQueue<T>&& other) {
	this->data = other.data;
	other.data = nullptr;

	this->capacity = other.capacity;
	this->size = other.size;
	this->capacity = this->size = 0;

	this->put = other.put;
	this->get = other.get;
	this->put = this->get = 0;
}

template <typename T>
void MyQueue<T>::Resize() {
	T* resizedData = new T[capacity * 2];
	for (size_t i = 0; i < size; i++)
	{
		resizedData[i] = this->data[get];
		(++get) %= capacity;
	}
	this->capacity *= 2;
	delete[] this->data;
	this->data = resizedData;
	this->get = 0;
	this->put = size;
}

template <typename T>
void MyQueue<T>::Push(const T& other) {
	if (this->size == this->capacity)
		Resize();

	this->data[put] = other;
	(++put) %= capacity;
	size++;
}

template <typename T>
void MyQueue<T>::Push(T&& other) {
	if (this->size == this->capacity)
		Resize();

	this->data[put] = std::move(other);
	(++put) %= capacity;
	size++;
}
template <typename T>
const T& MyQueue<T>::Peek() const {
	if (IsEmpty())
		throw std::logic_error("Empty queue!");

	return this->data[get];
}
template <typename T>
void MyQueue<T>::Pop() {
	if (IsEmpty())
		throw std::logic_error("Empty queue!");

	(++get) %= capacity;
	this->size--;
}

template <typename T>
bool MyQueue<T>::IsEmpty() const {
	return this->size == 0;
}

