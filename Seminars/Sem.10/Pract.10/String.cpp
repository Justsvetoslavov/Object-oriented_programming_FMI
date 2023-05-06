#include "String.hpp"
#include <cstring>
#pragma warning(disable:4996)


String::String(char* string)
{
    size_t lengthOfString = strlen(string) + 1;
    this->myStr = new char[lengthOfString];
    strcpy(this->myStr, string);
}

String::String(const String& other)
{
    size_t lengthOfOtherString = strlen(other.myStr) + 1;
    this->myStr = new char[lengthOfOtherString];
    strcpy(this->myStr, other.myStr);
}

String& String::operator=(const String& other)
{
    size_t lengthOfOtherString = strlen(other.myStr) + 1;
    this->myStr = new char[lengthOfOtherString];
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
    strcpy(temp.myStr + *this->myStr, other.myStr);
    delete[] this->myStr;
    this->myStr = temp.myStr;
    delete[] temp.myStr;
    return *this;
}

String operator+(const String& lStr, const String& rStr)
{
    String temp(lStr);
    temp += rStr;
    return temp;
}

bool operator==(const String& lStr, const String& rStr)
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
    return !(lStr <= rStr);
}

bool operator>=(const String& lStr, const String& rStr)
{
    return strcmp(lStr.myStr, rStr.myStr) >= 0;
}

bool operator<=(const String& lStr, const String& rStr)
{
    return !(lStr > rStr);
}

std::ostream& operator<<(std::ostream& os, const String& string)
{
    size_t indexHelper = 0;
    while (string.myStr[indexHelper] != '\0')
    {
        os << string.myStr[indexHelper];
        indexHelper++;
    }
    return os;
}
//
//std::istream& operator>>(std::istream& is, const String& string)
//{
//
//    return is;
//}

char* String::getMyStr() const
{
    return this->myStr;
}

size_t length(const String& myStr)
{
    return strlen(myStr.myStr);
}

bool String::isEmpthy()
{
    return this->myStr == nullptr;
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
    size_t newLength = strlen(this->myStr) + 2;
    String temp;
    temp.myStr = new char[newLength];
    strcpy(temp.myStr, this->myStr);
    temp.myStr[strlen(this->myStr)] = letter;
    temp.myStr[strlen(this->myStr) + 1] = '\0';
    delete[] this->myStr;
    this->myStr = temp.myStr;
    delete[] temp.myStr;
    return *this;
}

String::~String()
{
    delete[]this->myStr;
    this->myStr = nullptr;
}