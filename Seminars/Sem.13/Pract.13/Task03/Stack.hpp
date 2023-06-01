#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
	T* data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

public:
	Stack();
	Stack(size_t capacity);

	void Push(const T& obj);
	void Push(T&& obj);

	const T& Peek() const;
	void Pop();

	bool IsEmpty() const;

private:
	void CopyFrom(const Stack& other);
	void Free();
	void MoveFrom(Stack&& other);
	void Resize(size_t newCapacity);
};

template<typename T>
Stack<T>::Stack()
{
	this->capacity = 4;
	this->data = new T[capacity];
	this->size = 0;
}

template<typename T>
Stack<T>::Stack(size_t capacity)
{
	this->capacity = capacity;
	this->data = new T[capacity];
	this->size = 0;
}

template<typename T>
void Stack<T>::Push(const T& obj)
{
	if (this->size >= this->capacity)
		Resize(capacity * 2);

	this->data[size++] = obj;
}

template<typename T>
void Stack<T>::Push(T&& obj)
{
	if (this->size >= this->capacity)
		Resize(capacity * 2);

	this->data[size++] = std::move(obj);
}

template<typename T>
const T& Stack<T>::Peek() const
{
	if (IsEmpty()) {
		throw std::runtime_error("No elements in stack!");
	}
	return this->data[size - 1];
}

template<typename T>
void Stack<T>::Pop()
{
	if (IsEmpty()) {
		throw std::runtime_error("No elements in stack!");
	}

	this->size--;
}

template<typename T>
inline bool Stack<T>::IsEmpty() const
{
	return this->size == 0;
}

template<typename T>
void Stack<T>::CopyFrom(const Stack& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
void Stack<T>::Free()
{
	delete[] this->data;
	this->data = nullptr;
	this->capacity = this->size = 0;
}

template<typename T>
void Stack<T>::MoveFrom(Stack&& other)
{
	this->data = other.data;
	this->capacity = other.capacity;
	this->size = other.size;
	other.data = nullptr;
	other.capacity = 0;
	other.size = 0;
}

template<typename T>
void Stack<T>::Resize(size_t newCapacity)
{
	T* newData = this->data;
	this->data = new T[newCapacity];
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] = newData[i];
	}
	delete[] newData;
	this->capacity = newCapacity;
}