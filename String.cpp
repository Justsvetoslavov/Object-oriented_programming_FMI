#include "String.h"

String::String() {
    str = new char[1];
    str[0] = '\0';
    size = 0;
}

String::String(const char *str) {
    size = strlen(str);
    this->str = new char[size + 1];
    strcpy(this->str, str);
}

void String::copyStr(const String &str) {
    size = str.size;
    this->str = new char[size + 1];
    strcpy(this->str, str.str);
}

void String::clear() {
    delete[] str;
    size = 0;
}

String::~String() {
    clear();
}

String::String(const String &str) {
    copyStr(str);
}

String& String::operator=(const String &str) {
    if (this != &str) {
        clear();
        copyStr(str);
    }
    return *this;
}

char& String::operator[](const unsigned int pos) {
    return str[pos];
}

char String::operator[](const unsigned int pos) const {
    return str[pos];
}

String operator+(const String& str1, const String& str2) {
    String res;
    res.clear();
    res.str = new char[str1.size + str2.size + 1];
    strcpy(res.str, str1.str);
    strcat(res.str, str2.str);
    res.size = str1.size + str2.size;
    return res;
}

String& String::operator+=(const String &str) {
    char* res = new char[size + str.size + 1];
    strcpy(res, this->str);
    strcat(res, str.str);
    delete this->str;
    this->str = res;
    size += str.size;
    return *this;
}

const char* String::c_str() const {
    return str;
}

bool operator==(const String& str1, const String& str2) {
    if (str2.size == str1.size)
        if (strcmp(str1.str, str2.str) == 0)
            return true;
    return false;
}

bool operator!=(const String& str1, const String& str2) {
    return !(str1 == str2);
}

bool operator>(const String& str1, const String& str2) {
    if (str1.size > str2.size)
        return true;
    return false;
}

bool operator>=(const String& str1, const String& str2) {
    if (str1.size >= str2.size)
        return true;
    return false;
}

bool operator<=(const String& str1, const String& str2) {
    return !(str1 > str2);
}

bool operator<(const String& str1, const String& str2) {
    return !(str1 >= str2);
}

unsigned int String::length() const {
    return size;
}

bool String::empty() const {
    return size == 0;
}

void String::append(const char sym) {
    char *res = new char[size + 1 + 1];
    strcpy(res, str);
    res[size] = sym;
    res[++size] = '\0';
    delete str;
    str = res;
}

bool String::compare(const String &str) const {
    if (*this == str)
        return true;
    return false;
}