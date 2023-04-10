#include "String.h"

#include <iostream>

const char* DEFAULT_STR = "";

namespace {
	void myStrcpy(char* dest, const char* src) {
		if (dest == nullptr || src == nullptr) {
			return;
		}

		while (*src) {
			*dest = *src;

			src++;
			dest++;
		}

		*(dest) = '\0';
	}

	size_t myStrlen(const char* str) {
		if (str == nullptr) {
			return 0;
		}

		size_t ctr = 0;
		while (*str) {
			str++;
			ctr++;
		}
		return ctr;
	}

	char* myStrcat(char* dest, const char* src) {
		// There is a check for nullptr in myStrlen and myStrcpy
		size_t destLen = myStrlen(dest);
		dest += destLen;
		myStrcpy(dest, src);
		return dest;
	}

	int myStrcmp(const char* str1, const char* str2) {
		if (str1 == nullptr || str2 == nullptr) {
			return 0;
		}

		while (*str1 && *str2) {
			if (*str1 < *str2) {
				return -1;
			}
			if (*str1 > *str2) {
				return 1;
			}
			str1++;
			str2++;
		}

		if (!(*str1) && !(*str2)) {
			return 0;
		}

		return *str1 == '\0' ? -1 : 1;
	}
}

String::String() : String(DEFAULT_STR){

}

void String::free() {
	delete[] str;
	str = nullptr;
}

void String::copyFrom(const String& other) {
	copyStr(other.str);
}

void String::copyStr(const char* str) {
	this->str = new char[myStrlen(str) + 1];
	myStrcpy(this->str, str);
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

String::String(const char* str){
	copyStr(str);
}

String::String(char ch) {
	str = new char[2];
	str[0] = ch;
	str[1] = '\0';
}

char String::operator[](size_t ind) const{
	return str[ind];
}

char& String::operator[](size_t ind) {
	return str[ind];
}

String& String::operator+=(const String& other) {
	size_t len = length();
	char* newStr = new char[len + other.length() + 1];
	newStr[0] = '\0';
	myStrcat(newStr, str);
	myStrcat(newStr, other.str);

	delete[] str;
	str = newStr;

	return *this;
}

size_t String::length() const{
	return myStrlen(str);
}

bool String::empty() const{
	return (length() == 0);
}

void String::clear() {
	copyStr("");
}

const char* String::c_str() const {
	return str;
}

void String::append(char symbol) {
	String symbolStr(symbol);
	*this += symbolStr;
}

int String::compare(const String& other) const {
	return myStrcmp(str, other.str);
}

String operator+(const String& str1, const String& str2) {
	char* res = new char[str1.length() + str2.length() + 1];
	res[0] = '\0';
	myStrcat(res, str1.str);
	myStrcat(res, str2.str);

	String resultStr(res);
	delete[] res;
	return resultStr;
}

void String::print() const {
	std::cout << str << std::endl;
}

bool operator==(const String& str1, const String& str2) {
	return str1.compare(str2) == 0;
}

bool operator!=(const String& str1, const String& str2) {
	return !(str1 == str2);
}

bool operator<(const String& str1, const String& str2) {
	return str1.compare(str2) < 0;
}

bool operator>(const String& str1, const String& str2) {
	return str1.compare(str2) > 0;
}
bool operator<=(const String& str1, const String& str2) {
	return str1 < str2 || str1 == str2;
}

bool operator>=(const String& str1, const String& str2) {
	return str1 > str2 || str1 == str2;
}