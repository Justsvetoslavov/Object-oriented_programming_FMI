#pragma once

const int DEFAULT_CAPACITY = 2;

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
    int size() const;
    bool empty() const;
    void clear();
    const char *c_str() const;

    MyString &append(const MyString &);
    MyString &append(const char *);

    int compare(const MyString &) const;
    int compare(const char *) const;
    void shrink_to_fit();
    void push_back(char);
    void pop_back();

private:
    void manageCapacity(int, bool);
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