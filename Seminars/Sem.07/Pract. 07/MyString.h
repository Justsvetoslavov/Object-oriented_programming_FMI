#pragma once
#include <istream>
#include <ostream>

const int DEFAULT_CAPACITY = 2;

class MyString
{
    char *_data = nullptr;
    int _size = 0;
    int _capacity = 0;

public:
    MyString();
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

    char *operator*() const;

public:
    int length() const;
    int size() const;
    int capacity() const;
    bool empty() const;
    void clear();
    const char *c_str() const;

    char &front();
    const char &front() const;

    char &back();
    const char &back() const;

    MyString &replace(int, int, const MyString &);
    MyString &replace(int, int, int, char);

    MyString &append(const MyString &);
    MyString &append(const char *);

    int compare(const MyString &) const;
    int compare(const char *) const;
    void shrink_to_fit();
    void push_back(char);
    void pop_back();
    void swap(MyString &);

    MyString substr(int, int) const;

private:
    void manageCapacity(int, bool);
    void setData(const char *);

    void free();
    void copyFrom(const MyString &);
    void copyData(const char *);

private:
    friend std::istream &operator>>(std::istream &, const MyString &);
    friend std::ostream &operator<<(std::ostream &, const MyString &);
};

MyString operator+(const MyString &, const MyString &);

bool operator==(const MyString &, const MyString &);
bool operator!=(const MyString &, const MyString &);

bool operator<(const MyString &, const MyString &);
bool operator>(const MyString &, const MyString &);

bool operator<=(const MyString &, const MyString &);
bool operator>=(const MyString &, const MyString &);
