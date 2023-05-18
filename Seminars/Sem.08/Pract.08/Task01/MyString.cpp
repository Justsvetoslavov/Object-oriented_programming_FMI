#include "MyString.h"
#pragma warning(disable:4996)

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result;  //TBI ??

	return result;
}

MyString& MyString::operator+=(const MyString& other)
{
	char* result = new char[length() + other.length() + 1];
	result[0] = '\0'; //������ strcat!!
	strcat(result, _data);
	strcat(result, other._data);

	delete[] _data;
	_data = result;
	size = length() + other.length();

	return *this;
}

MyString::MyString()
{
	_data = new char[1];
	_data[0] = '\0';
	size = 0;
}

MyString::MyString(const char* data)
{
	size = strlen(data);
	_data = new char[size + 1];
	strcpy(_data, data);

}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}


void MyString::free()
{
	delete[] _data;
	_data = nullptr;
}
MyString::~MyString()
{
	free();
}

size_t MyString::length() const
{
	return size;
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	_data = new char[size + 1];
	strcpy(_data, other._data);
}

char& MyString::operator[](size_t index) //������������ ������
{
	return _data[index];
}

char MyString::operator[](size_t index) const //���������� ������ 
{
	return _data[index];
}

const char* MyString::c_str() const {
	return _data;
}

std::ostream& operator<<(std::ostream& os, const MyString& str) {
	return os << str._data;
}