#pragma once

#include <iostream>

class MyString
{
	char* _data;
	size_t size;

	void copyFrom(const MyString& data);
	void free();
public:

	MyString();
	MyString(const char* data);


	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	friend std::ostream& operator<<(std::ostream& os, const MyString& str);

	size_t length() const;
	MyString& operator+=(const MyString& other);

	const char* c_str() const;

	char& operator[](size_t index);
	char operator[](size_t index) const;
	~MyString();
};

MyString operator+(const MyString& lhs, const MyString& rhs);