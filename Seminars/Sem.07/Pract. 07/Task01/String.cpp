#include "String.h"
#include <cstring>
#pragma warning(disable:4996)

void String::copyFrom(const String& other)
{
	this->size = other.size;
	this->data = new char[this->size + 1] {};
	strcpy(this->data, other.data);
}

void String::free()
{
	delete[] this->data;
	data = nullptr;
	this->size = 0;
}

String::String()
{
	this->data = new char[1] {};
	this->size = 0;
}

String::String(const char* str)
{
	this->size = strlen(str);
	this->data = new char[this->size + 1] {};
	strcpy(this->data, str);
}

String::String(const String& other)
{
	copyFrom(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

String::~String()
{
	free();
}

size_t String::length() const
{
	return this->size;
}

bool String::empty() const
{
	return this->data[0] == '\0';
}

void String::clear()
{
	this->data[0] = '\0';
	this->size = 0;
}

const char* String::c_str() const
{
	return this->data;
}

int String::compare(const String& other) const
{
	return strcmp(this->data, other.data);
}

String String::substr(const size_t start, size_t length) const
{
	if (start > this->size)
	{
		return { "" };
	}
	if (start + length - 1 > this->size)
	{
		length = this->size - start + 1;
	}

	char* temp = new char[this->size + 1] {};
	strcat(temp, this->data);
	temp[start + length - 1] = 0;

	char* newData = new char[length + 1] {};
	strcat(newData, temp + start - 1);

	String result(newData);

	delete[] newData;
	delete[] temp;

	return result;
}

String& String::operator+=(const String& other)
{
	char* newData = new char[this->size + other.size + 1] {};
	strcat(newData, this->data);
	strcat(newData, other.data);

	delete[] this->data;
	this->data = newData;
	this->size += other.size;

	return *this;
}

bool String::operator==(const String& other) const
{
	return this->compare(other) == 0;
}

bool String::operator!=(const String& other) const
{
	return this->compare(other) != 0;
}

char String::operator[](const size_t idx) const
{
	return this->data[idx];
}

char& String::operator[](const size_t idx)
{
	return this->data[idx];
}

String operator+(const String& lhs, const String& rhs)
{
	char* newData = new char[lhs.length() + rhs.length() + 1] {};
	strcat(newData, lhs.c_str());
	strcat(newData, rhs.c_str());

	String result(newData);

	delete[] newData;

	return result;
}

bool operator>(const String& lhs, const String& rhs)
{
	return lhs.compare(rhs) == 1;
}

bool operator<(const String& lhs, const String& rhs)
{
	return lhs.compare(rhs) == -1;
}

bool operator>=(const String& lhs, const String& rhs)
{
	return lhs.compare(rhs) != -1;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return lhs.compare(rhs) != 1;
}

void String::append(const char symbol)
{
	if (symbol == 0)
	{
		return; // append empty char
	}

	char* newData = new char[this->size + 2] {};
	strcpy(newData, this->data);
	newData[this->size] = symbol;
	newData[this->size + 1] = '\0';

	delete[] this->data;
	this->data = newData;
	this->size += 1;
}
