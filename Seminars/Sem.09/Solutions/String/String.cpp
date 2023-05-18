#include "String.hpp"
#include <iostream>
#include <cstring>

#pragma warning(disable:4996)

String::String(const char* data) {
	printf("Constr with param\n");

	this->data = new char[strlen(data) + 1];
	strcpy(this->data, data);
}

String::String(const String& other) {
	printf("Copy constr\n");


	CopyFrom(other);
}
String& String::operator=(const String& other) {
	printf("Copy assignment\n");

	if (this != &other) {
		Free();
		CopyFrom(other);
	}

	return *this;
}
String::~String() {
	Free();
}

void String::Print() const {
	std::cout << data << std::endl;
}

void String::CopyFrom(const String& other) {
	this->data = new char[strlen(other.data) + 1];
	strcpy(data, other.data);
}
void String::Free() {
	delete[] data;
}

String::String(String&& other) {
	data = other.data;

	other.data = nullptr;
}

String& String::operator=(String&& other) {
	if (this != &other) {
		Free();

		data = other.data;
		other.data = nullptr;
	}
}