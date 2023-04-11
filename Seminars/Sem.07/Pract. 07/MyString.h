#pragma once
#include <istream>
#include <ostream>

const int DEFAULT_CAPACITY = 8;

class MyString
{
    char *_data = nullptr;
    int _size = 0;
    int _capacity = 0;

public:
    // Big 4
    MyString();
    MyString(const char *);
    MyString(const MyString &);
    MyString &operator=(const MyString &);
    ~MyString();

    char *operator*() const;

public:
    // Capacity:
    int size() const;
    int length() const;
    void resize(int, char = '\0');
    int capacity() const;
    void reserve(int);
    void clear();
    bool empty() const;
    void shrink_to_fit();

    // Element access:
    char &operator[](int);
    const char &operator[](int) const;

    char &at(int);
    const char &at(int) const;

    char &front();
    const char &front() const;

    char &back();
    const char &back() const;

    // Modifiers:
    MyString &operator+=(const MyString &);
    MyString &operator+=(const char *);

    MyString &append(const MyString &);
    MyString &append(const char *);

    void push_back(char);

    MyString &replace(int, int, const MyString &);
    MyString &replace(int, int, int, char);

    void swap(MyString &);
    void pop_back();

    // String operations:
    const char *c_str() const;
    int find_first_of(char, int = 0) const;
    int find_last_of(char, int = INT_MAX) const;
    MyString substr(int, int) const;

    int compare(const MyString &) const;
    int compare(const char *) const;

private:
    // Big 4 helper functions
    void manageCapacity(int, bool);

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
