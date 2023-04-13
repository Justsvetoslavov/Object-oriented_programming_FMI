#include "Header.h"
#include <iostream>
#pragma warning (disable : 4996)

using std::cout;
using std::cin;
using std::endl;

String::String()
{
    data = nullptr;
}

String::String(const char* data)
{
    this->data = new char[strlen(data) + 1];
    strcpy(this->data, data);
}

String::String(const String& other)
{
    CopyFrom(other);
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

String::~String()
{
    Free();
}

char& String::operator[](size_t index)
{
    return data[index];
}

String& String::operator+=(const String& string)
{
    char* newData = new char[strlen(data) + strlen(string.data) + 1];
    strcpy(newData, data);
    strcpy(newData + length(), string.data);
    delete[] data;
    data = newData;

    return *this;
}

bool String::operator==(const String& string)
{
    return strcmp(data, string.data) == 0;
}

bool String::operator!=(const String& string)
{
    return !(*this == string);
}

bool String::operator<=(const String& string)
{
    return strcmp(data, string.data) <= 0;
}

bool String::operator>=(const String& string)
{
    return strcmp(data, string.data) >= 0;
}

size_t String::length() const
{
    return strlen(data);
}
bool String::empty() const
{
    return length() == 0;
}
void String::clear()
{
    delete[] data;
    data = new char[1];
    data[0] = '\0';
}
const char* String::c_str() const
{
    return data;
}
String String::append(const String& string) const
{
    String result;
    result.data = new char[length() + string.length() + 1];
    strcpy(result.data, data);
    strcpy(result.data + length(), string.data);
    delete[] data;
    data = result.data;

    return 
}
bool String::compare(const char* data1) const
{
    return strcmp(data, data1) == 0;
}
String operator+(const String& lhs, const String& rhs)
{
    String temp;
    temp.data = new char[strlen(lhs.data) + strlen(rhs.data) + 1];
    strcpy(temp.data, lhs.data);
    strcpy(temp.data + strlen(lhs.data), rhs.data);
    temp.data[strlen(lhs.data) + strlen(rhs.data)] = '\0';
    return temp;
}

bool operator<(const String& lhs, const String& rhs)
{
    return strcmp(lhs.data, rhs.data) < 0;
}

bool operator>(const String& lhs, const String& rhs)
{
    return strcmp(lhs.data, rhs.data) > 0;
}

void String::CopyFrom(const String& other)
{
    data = new char[strlen(other.data) + 1];
    strcpy(data, other.data);
    data[strlen(other.data)] = '\0';
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
    os << string.data;
    return os;
}

void String::Free()
{
    delete[] data;
}

int main()
{
    String str1;
    String str2("Hello");
    String str3(str2);

    cout << str2 << endl;
    cout << str3 << endl;

    str3 = "World";
    cout << str3 << endl;

    str3 += "!!";
    cout << str3 << endl;

    cout << (str2 == str3) ? true : false;

    cout << (str2 != str3) ? true : false;

    cout << (str2 < str3) ? true : false;

    cout << (str2 > str3) ? true : false;

    cout << (str2 <= str3) ? true : false;

    cout << (str2 >= str3) ? true : false;

    char c = str2[1];
    cout << c;

    
    String str4("Hello, world!");
    cout << str4.append("!!!") << endl;
    cout << str4.compare("1234") << endl;
    cout << str4.c_str() << endl;
    cout << str4.empty() << endl;
    cout << str4.length() << endl;
    str4.clear();
}

