#include "String.h"
#include <iostream>

String::String() : String("")
{

}

String::String(const char* text)
{
	copyFrom(text);
}

String::String(const String& text)
{
	copyFrom(text.getString());
}

String::~String()
{
	free();
}

char* String::getString() const
{
	return this->str;
}

void String::setString(const char* text)
{
	free();
	copyFrom(text);
}

String& String::operator=(const String& other)
{
	free();
	copyFrom(other.getString());
}

String& String::operator+(const String& other)
{
	String newStr(strcat(this->str, other.getString()));
	return newStr;
}

String& String::operator+=(const String& other)
{
	this->str = strcat(this->str, other.getString());
}

std::ostream& operator<<(std::ostream& os, const String& text)
{
	return os << text.getString();;
}

std::istream& operator>>(std::istream& is, String& text)
{
	//return is.getline(text.str, 123455);;
}

bool operator==(const String& str1, const String& str2)
{
	return strcmp(str1.getString(), str2.getString()) == 0;
}

bool operator!=(const String& str1, const String& str2)
{
	return !(str1 == str2);
}

bool operator<(const String& str1, const String& str2)
{
	return strcmp(str1.getString(), str2.getString()) < 0;
}

bool operator>(const String& str1, const String& str2)
{
	return strcmp(str1.getString(), str2.getString()) > 0;
}

bool operator<=(const String& str1, const String& str2)
{
	return !(str1 > str2);
}

bool operator>=(const String& str1, const String& str2)
{
	return !(str1 < str2);
}

int String::length() const
{
	return strlen(this->str);
}

bool String::empty() const
{
	return this->length() == 0;
}

void String::clear()
{
	free();
}

const char* String::c_str()
{
	return this->str;
}

int String::append(const char& symbol)
{
	this->str += symbol;
}

int String::compare(const String& other)
{
	return strcmp(this->str, other.str);
}

void String::free()
{
	delete[] this->str;
}

void String::copyFrom(const char* text)
{
	this->str = new char[strlen(text) + 1];
	strcpy(this->str, text);
}