#include "String.h"
#include<cstring>
#include<iostream>
#pragma warning (disable: 4996)

void  String::copyFrom(const  String&other) {
	size = other.size;
	content = new char[size + 1];
	strcpy(content, other.content);
}

void String::free() {
	delete[]content;
	content = nullptr;
	size = 0;
}

String::String() {
	size = 0;
	content = new char[1];
	content[0] = '\0';
}

String::String(const char* newContent) {
	size = strlen(newContent);
	content = new char[size + 1];
	strcpy(content, newContent);
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

size_t  String::length()const {
	return size;
}

const char* String::c_str()const {
	return content;
}

void String::setName(const char* str) {
	delete[]content;
	size = strlen(str);
	content = new char[size + 1];
	strcpy(content, str);
}

char String:: operator[](size_t index)const {
	if (index >= size) {
		std::cout << "Error";
	}
	return content[index];
}

void String::concat(const String& other) {
	size = size + other.size;
	char* newContent = new char[size + 1];
	strcpy(newContent, content);
	strcat(newContent, other.content);
	delete[] content;
	content = newContent;
}

String& String:: operator +=(const String& other) {
	
	concat(other.content);
	return *this;
}

bool   operator==(const String& lhs, const String& rhs) {
	if (lhs.size != rhs.size) {
		return false;
	}
	return( std::strcmp(lhs.content, rhs.content)==0);

}

bool operator !=(const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}

String& operator+(const String& lhs, const String& rhs) {
	String temp(lhs);
	temp += rhs;
	return temp;
}

bool  operator<(const String& lhs, const String& rhs) {
	return(std::strcmp(lhs.content, rhs.content) < 0);

}

bool operator>(const String& lhs, const String& rhs) {
	return(std::strcmp(lhs.content, rhs.content) > 0);

}

bool operator <=(const String& lhs, const String& rhs) {
	return(std::strcmp(lhs.content, rhs.content) <= 0);

}

bool  operator >=(const String& lhs, const String& rhs) {
	return(std::strcmp(lhs.content, rhs.content) >= 0);

}

void String::clear() {
	free();
}

bool String::empty()const {
	return size == 0;
}

void String::append(char ch) {
	char* newContent = new char[size + 2];
	strcpy(newContent, content);
	newContent[size] = ch;
	newContent[size + 1] = '\0';
	delete[] content;
	content = newContent;
}

int String::compare(const String& other)const {
	return strcmp(content, other.content);
}