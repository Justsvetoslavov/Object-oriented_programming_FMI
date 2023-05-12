#include "String.h"
#include <cstring>
#include <iostream>
#pragma warning(disable: 4996)

String::String() {
	string = new char[1];
	string[0] = '\0';
}

String::String(const char* str) {
	SetSize(str);
	this->string = new char[size + 1];
	strcpy(this->string, str);
}

String::String(const String& other) {
	copyFrom(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

String::~String() {
	free();
}

int String::Size() const {
	return size;
}

char& String::operator[](int index) {
	return string[index];
}

char String::operator[](int index) const {
	return string[index];
}

String& String::operator+=(const String& right) {
	String result;
	result.size = size + right.size;
	result.string = new char[result.size + 1];
	result.string[0] = '\0';

	strcpy(result.string, string);
	strcat(result.string, right.string);

	*this = result;

	return *this;
}

bool String::operator==(const String& right) const {
	return (this->Compare(right) == 0) ? true : false;
}

bool String::operator!=(const String& right) const {
	return !(*this == right);
}

bool String::operator<(const String& right) const {
	return (this->Compare(right) == -1) ? true : false;
}

bool String::operator>(const String& right) const {
	return !(*this < right);
}

bool String::operator<=(const String& right) const {
	return ((*this < right) || (*this == right));
}

bool String::operator>=(const String& right) const {
	return ((*this > right) || (*this == right));
}

bool String::IsEmpty() const {
	return (size > 0) ? false : true;
}

void String::Clear() {
	free();
}

void String::Append(char toBeAppended) {
	String result;
	result.size = size + 1;
	result.string = new char[result.size + 1];
	result.string[0] = '\0';
	strcpy(result.string, string);
	result.string[size] = toBeAppended;
	result.string[size + 1] = '\0';
	*this = result;
}

int String::Compare(const String& obj) const {
	if (obj.size > size)
		return -1;
	else if (obj.size < size)
		return 1;
	else {
		for (int i = 0; i < size; i++) {
			if (string[i] < obj.string[i])
				return 1;
			else if (string[i] > obj.string[i])
				return -1;
		}
	}
	return 0;
}

const char* String::c_str() const {
	return string;
}

int String::GetSize() const {
	return size;
}

void String::free() {
	delete[] string;
	string = nullptr;
	size = 0;
}

void String::copyFrom(const String& other) {
	size = other.size;
	string = new char[size + 1];
	strcpy(string, other.string);
}

void String::SetSize(const char* string) {
	if (string == nullptr)
		return;

	int length = 0;
	for (int i = 0; string[i] != '\0'; i++) {
		length++;
	}
	size = length;
}

String operator+(const String& left, const String& right) {
	String result(left);
	result += right;
	return result;
}

