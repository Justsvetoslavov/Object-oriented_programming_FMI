#pragma once

class MyString
{
    char *data = nullptr;
    int size = 0;
    int capacity = 0;

public:
    MyString(const char *);
    MyString(const MyString &);
    MyString &operator=(const MyString &);
    ~MyString();

    char &operator[](int idx);
    const char &operator[](int idx) const;

    char &at(int idx);
    const char &at(int idx) const;

    MyString &operator+=(const MyString &);

public:
    int length() const;
    bool empty() const;
    void clear();
    const char *c_str() const;
    void append();
    int compare();
    void shrink_to_fit();
    void push_back();
    void pop_back();
};

MyString operator+(MyString, const MyString &);

bool operator==(const MyString &, const MyString &);
bool operator!=(const MyString &, const MyString &);

bool operator<(const MyString &, const MyString &);
bool operator>(const MyString &, const MyString &);

bool operator<=(const MyString &, const MyString &);
bool operator>=(const MyString &, const MyString &);