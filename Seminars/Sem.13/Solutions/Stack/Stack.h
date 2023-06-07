#pragma once
#include <iostream>

template<typename T>
struct StackElement {
	T data;
	StackElement<T>* next;
};

template<typename T>
class Stack {
	StackElement<T>* top = nullptr;
public:
	Stack() = default;
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	~Stack();

	void push(const T&);
	T pop();

	T peek() const;
	bool empty() const;
private:
	void copy(const Stack<T>&);
	void free();
};

template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
	copy(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}

template <typename T>
Stack<T>::~Stack() {
	free();
}

template <typename T>
void Stack<T>::copy(const Stack<T>& s) {
	if (s.top == nullptr) {
		return;
	}

	StackElement<T>* toCopy = nullptr, *newElement = nullptr, *previousElement = nullptr;
	toCopy = s.top;

	newElement = new StackElement<T>;
	newElement->data = toCopy->data; //copy
	newElement->next = nullptr;
	top = newElement;

	previousElement = top;
	toCopy = toCopy->next;

	while (toCopy != nullptr) {
		newElement = new StackElement<T>;
		newElement->data = toCopy->data; //copy
		newElement->next = nullptr;

		previousElement->next = newElement;
		previousElement = newElement;
		toCopy = toCopy->next;
	}
}

template <typename T>
void Stack<T>::free() {
	StackElement<T>* toDelete;

	while (top != nullptr) {
		toDelete = top;
		top = top->next;
		delete toDelete;
	}
}

template <typename T>
void Stack<T>::push(const T& d) {
	StackElement<T>* p = new StackElement<T>;
	p->data = d;
	p->next = top;

	top = p;
}

template <typename T>
T Stack<T>::pop() {
	if (empty()) {
		throw "Stack is empty!";
	}

	StackElement<T>* p = top;
	top = top->next;
	T data = p->data;
	delete p;

	return data;
}

template <typename T>
T Stack<T>::peek() const {
	if (empty()) {
		throw "Stack is empty";
	}

	return top->data;
}

template <typename T>
bool Stack<T>::empty() const {
	return top == nullptr;
}
