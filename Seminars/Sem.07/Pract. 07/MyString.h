#pragma once

const int DEFAULT_CAPACITY = 16;

class MyString
{
    char *_data = nullptr;
    int _size = 0;
    int _capacity = 0;

public:
    MyString(const char *);
    MyString(const MyString &);
    MyString &operator=(const MyString &);
    ~MyString();

    char &operator[](int);
    const char &operator[](int) const;

    char &at(int);
    const char &at(int) const;

    MyString &operator+=(const MyString &);
    MyString &operator+=(const char *);

public:
    int length() const;
    bool empty() const;
    void clear();
    const char *c_str() const;

    MyString &append(const MyString &);
    MyString &append(const char *);

    int compare();
    void shrink_to_fit();
    void push_back();
    void pop_back();

private:
    void setData(const char *);

    void free();
    void copyFrom(const MyString &);
    void copyData(const char *);
};

MyString operator+(MyString, const MyString &);

bool operator==(const MyString &, const MyString &);
bool operator!=(const MyString &, const MyString &);

bool operator<(const MyString &, const MyString &);
bool operator>(const MyString &, const MyString &);

bool operator<=(const MyString &, const MyString &);
bool operator>=(const MyString &, const MyString &);