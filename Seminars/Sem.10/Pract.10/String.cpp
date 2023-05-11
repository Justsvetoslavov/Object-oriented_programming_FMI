#include <cstring>
#include <fstream>
#include <iostream>
#include "String.h"
#include "HelperFunctions.h"

void String::CopyFrom(const String& other)
{
	length = other.length;
	data = new char[length + 1];
	strcpy_s(data, length + 1, other.data);
}

void String::MoveFrom(String&& other)
{
	length = other.length;
	data = other.data;
	other.data = nullptr;
}

String::String(size_t n)
{
	length = GetDigitsCount(n);
	data = new char[length + 1];
	for (int i = (int)(length - 1); i >= 0; i--) //casting to int because of warning
	{
		data[i] = (n % 10) + '0';
		n /= 10;
	}
	data[length] = '\0';
}

void String::Free()
{
	delete[] data;
	length = 0;
}

String::String(const String& other)
{
	CopyFrom(other);
}

String::String(String&& other) noexcept
{
	MoveFrom(std::move(other));
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

String& String::operator=(String&& other) noexcept
{
	if (this != &other)
	{
		Free();
		MoveFrom(std::move(other));
	}
	return *this;
}

char& String::operator[](size_t index)
{
	if (index >= length) throw std::runtime_error("index out of range");
	return data[index];
}

const char String::operator[](size_t index) const
{
	if (index >= length) throw std::runtime_error("index out of range");
	return data[index];
}

String String::operator+=(const String& other)
{
	length += other.length;
	char* newData = new char[length + 1] {};
	strcat_s(newData, length + 1, data);
	strcat_s(newData, length + 1, other.data);
	delete[] data;
	data = newData;
	return *this;
}

String::~String()
{
	Free();
}

size_t String::GetLength() const
{
	return length;
}

bool String::empty() const
{
	return length == 0;
}

void String::clear()
{
	Free();
	data = new char[1] {};
}

const char* String::c_str() const
{
	return data;
}

void String::SaveToFile(std::ofstream& file) const
{
	file.write((const char*)&length, sizeof(length));
	file.write((const char*)data, length + 1);
}

void String::ReadFromFile(std::ifstream& file)
{
	Free();
	file.read((char*)&length, sizeof(length));
	data = new char[length + 1];
	file.read((char*)data, length + 1);
}

String::String()
{
	data = new char[1] {};
}

String::String(const char* str)
{
	length = strlen(str);
	data = new char[length + 1];
	strcpy_s(data, length + 1, str);
}

String operator+(const String& lhs, const String& rhs)
{
	String result(lhs);
	result += rhs;
	return result;
}

std::istream& operator>>(std::istream& is, String& str)
{
	char buff[MAX_BUFFER_SIZE]{};
	is >> buff;
	str.Free();
	str.length = strlen(buff);
	str.data = new char[str.length + 1];
	strcpy_s(str.data, str.length + 1, buff);
	return is;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.data;
	return os;
}

bool operator==(const String& lhs, const String& rhs)
{
	if (lhs.length != rhs.length) return false;
	if (strcmp(lhs.data, rhs.data) != 0) return false;
	return true;
}

bool operator!=(const String& lhs, const String& rhs)
{
	return !(lhs == rhs);
}

bool operator>(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) > 0;
}

bool operator<(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) < 0;
}

bool operator>=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) >= 0;
}

bool operator<=(const String& lhs, const String& rhs)
{
	return strcmp(lhs.data, rhs.data) <= 0;
}
