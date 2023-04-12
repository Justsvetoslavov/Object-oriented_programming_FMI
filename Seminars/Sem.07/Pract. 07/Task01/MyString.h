#pragma once
#include <cstdio>
#include <cstring>
class MyString {

    size_t size;
    char* data;

    void free();
    void copyFrom(const MyString &other);


public:

    MyString(const char *str = "");
    MyString(const MyString &str);
    ~MyString();

    const char* c_str();
    size_t length() const;

    bool empty() const;
    size_t compare(const MyString &other);

    MyString& clear();
    MyString& append(const MyString& other);
    MyString& append(const char* str);

    MyString& operator=(const MyString &other);
    MyString& operator+=(const MyString &other);

    friend MyString operator+(const MyString &lhs,const MyString &rhs);

    friend bool operator==(const MyString &lhs,const MyString &rhs);
    friend bool operator!=(const MyString &lhs,const MyString &rhs);

    friend bool operator>(const MyString &lhs,const MyString &rhs);
    friend bool operator<(const MyString &lhs,const MyString &rhs);
    friend bool operator>=(const MyString &lhs,const MyString &rhs);
    friend bool operator<=(const MyString &lhs,const MyString &rhs);

    friend MyString operator*(const MyString &lhs,size_t num);
    friend MyString operator*(size_t num,const MyString &rhs);

    char operator[](size_t i);
    char& operator[](size_t i) const;

    friend std::ostream& operator<<(std::ostream& os,const MyString& string);
    friend std::istream& operator>>(std::istream& is,MyString& string);


};



