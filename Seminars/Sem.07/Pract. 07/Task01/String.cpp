#include <cstring>
#include "String.hpp"
#pragma warning(disable:4996)


String::String(const char* string)
{
	size_t lengthOfString = strlen(string) + 1;
	this->myStr = new char[lengthOfString];
	strcpy(this->myStr, string);
}

String::String(String& other)
{
	size_t lengthOfOtherString = strlen(other.myStr) + 1;
	this->myStr = new char[lengthOfOtherString];
	strcpy(this->myStr, other.myStr);
}

String& String::operator=(String& other)
{
	strcpy(this->myStr, other.myStr);
	return *this;
}

char String::operator[](size_t index)
{
	return this->myStr[index];
}

String& String::operator+=(const String& other)
{
	size_t myStrLength = strlen(this->myStr);
	size_t otherStrLength = strlen(other.myStr);
	size_t newLength = myStrLength + otherStrLength + 1;
	String temp;
	temp.myStr = new char[newLength];
	strcpy(temp.myStr, this->myStr);
	strcpy(temp.myStr + myStrLength, other.myStr);
	delete[]this->myStr;
	this->myStr = new char[newLength];
	strcpy(this->myStr, temp.myStr);
	return *this;
}

String operator+(String& lStr, const String& rStr)
{
	String temp(lStr);
	temp += rStr;
	return temp;
}

bool operator==(const String& lStr,const String& rStr)
{
	return strcmp(lStr.myStr, rStr.myStr) == 0;
}

bool operator!=(const String& lStr, const String& rStr)
{
	return !(lStr == rStr);
}

bool operator<(const String& lStr, const String& rStr)
{
	return strcmp(lStr.myStr, rStr.myStr) > 0;
}

bool operator>(const String& lStr, const String& rStr)
{
	return !(lStr < rStr);
}

bool operator>=(const String& lStr, const String& rStr)
{
	return strcmp(lStr.myStr, rStr.myStr) >= 0;
}

bool operator<=(const String& lStr, const String& rStr)
{
	return !(lStr >= rStr);
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
	size_t indexHelper = 0;
	while (string.myStr[indexHelper] != '\0')
	{
		os << string.myStr[indexHelper];
	}
	return os;
}

// std::istream& operator>>(std::istream& is, const String& string)
// {
// 	size_t indexHelper = 0;
// 	while (string.myStr[indexHelper] != '\0')
// 	{
// 		is >> string.myStr[indexHelper];
// 	}
// 	return is;
// }
//
//Here I can't to think to idea how to make it.

void String::setMyStr(const char* string)
{
	size_t lengthOfString = strlen(string) + 1;
	this->myStr = new char[lengthOfString];
	strcpy(this->myStr, string);
}

char* String::getMyStr() const
{
	return this->myStr;
}

size_t length(const String& myStr)
{
	return strlen(myStr.myStr);
}

bool String::isEmpthy(const String& myStr)
{
	return myStr == "";
}

void String::clear(String& myStr)
{
	delete[] myStr.myStr;
}

const char* String::c_str(const String& myStr)
{
	return myStr.myStr;
}

String String::append(char letter)
{
	return this->myStr + letter;
}

String::~String()
{
	delete[]this->myStr;
	this->myStr = nullptr;
} 