#pragma once
#include <ostream>

static const size_t DEFAULT_CAPACITY = 8;

class MyString
{
    char *_data = nullptr;
    size_t _size = 0;
    size_t _capacity = DEFAULT_CAPACITY;

public:
    // Big 6
    MyString();
    explicit MyString(const char *);

    MyString(const MyString &);
    MyString(MyString &&) noexcept;

    MyString &operator=(const MyString &);
    MyString &operator=(MyString &&) noexcept;

    ~MyString() noexcept;

    char *operator*() const noexcept;

public:
    // Capacity:
    size_t size() const noexcept;
    size_t length() const noexcept;
    void resize(size_t, char = '\0');
    size_t capacity() const noexcept;
    void reserve(size_t);
    void clear();
    bool empty() const noexcept;
    void shrink_to_fit();

    // Element access:
    char &operator[](size_t);
    const char &operator[](size_t) const;

    char &at(size_t);
    const char &at(size_t) const;

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

    void reset_data() noexcept;

    MyString &replace(size_t, size_t, const MyString &);
    MyString &replace(size_t, size_t, size_t, char);

    void swap(MyString &) noexcept;
    void pop_back() noexcept;

    // String operations:
    const char *c_str() const noexcept;
    size_t find_first_of(char, size_t = 0) const noexcept;
    size_t find_last_of(char, size_t = SIZE_MAX) const noexcept;
    MyString substr(size_t, size_t) const;

    size_t compare(const MyString &) const;
    size_t compare(const char *) const;

private:
    // Big 6 helper functions
    void manageCapacity(size_t, bool, bool = true);

    void free() noexcept;
    void copyFrom(const MyString &);
    void copyData(const char *);
    void moveFrom(MyString &&) noexcept;
};

std::ostream &operator<<(std::ostream &, const MyString &) noexcept;

MyString operator+(const MyString &, const MyString &);

bool operator==(const MyString &, const MyString &);
bool operator==(const char *, const MyString &);
bool operator==(const MyString &, const char *);

bool operator!=(const MyString &, const MyString &);
bool operator!=(const char *, const MyString &);
bool operator!=(const MyString &, const char *);

bool operator<(const MyString &, const MyString &);
bool operator>(const MyString &, const MyString &);

bool operator<=(const MyString &, const MyString &);
bool operator>=(const MyString &, const MyString &);
