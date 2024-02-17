#include "MyString.h"
#include "Utils.h"

// Big 4
MyString::MyString() : MyString(nullptr) {}

MyString::MyString(const char *data)
{
    if (!data)
    {
        _data = new char[_capacity];
        return;
    }

    size_t size = myStrLen(data);
    _size = size;

    manageCapacity(size, false, false);

    _data = new char[_capacity];
    myStrCpy(_data, data);
}

MyString::MyString(const MyString &other)
{
    copyFrom(other);
}

MyString::MyString(MyString &&other) noexcept
{
    moveFrom(std::move(other));
}

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

MyString &MyString::operator=(MyString &&other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

char *MyString::operator*() const noexcept
{
    return _data;
}

// Big 4 helper functions
void MyString::manageCapacity(size_t size, bool shouldCopy, bool shouldResize)
{
    if (size >= _capacity)
    {
        while (size >= _capacity)
        {
            _capacity <<= 1;
        }
        if (shouldResize)
            resizeUtil(_data, _capacity, shouldCopy);
    }
}

void MyString::free() noexcept
{
    delete[] _data;
    _data = nullptr;

    _size = 0;
    _capacity = 0;
}

void MyString::copyFrom(const MyString &other)
{
    _size = other._size;
    _capacity = other._capacity;
    copyData(other._data);
}

void MyString::copyData(const char *data)
{
    _data = new char[_capacity]{'\0'};
    myStrCpy(_data, data);
}

void MyString::moveFrom(MyString &&other) noexcept
{
    _data = other._data;
    other._data = nullptr;

    _size = other._size;
    other._size = 0;

    _capacity = other._capacity;
    other._capacity = 0;
}

// Capacity:
size_t MyString::size() const noexcept
{
    return _size;
}

size_t MyString::length() const noexcept
{
    return _size;
}

void MyString::resize(size_t len, char ch)
{
    if (len < _size)
    {
        _size = len;
        _data[_size] = '\0';
    }
    else if (len > _size)
    {
        reserve(len);
        for (size_t i = _size; i < len; ++i)
        {
            _data[i] = ch;
        }
        _size = len;
        _data[_size] = '\0';
    }
}

size_t MyString::capacity() const noexcept
{
    return _capacity;
}

void MyString::reserve(size_t len)
{
    if (len <= _size)
    {
        return;
    }

    manageCapacity(len, true);
}

void MyString::clear()
{
    resizeUtil(_data, DEFAULT_CAPACITY, false);

    _capacity = DEFAULT_CAPACITY;
    _data[0] = '\0';
    _size = 0;
}

bool MyString::empty() const noexcept
{
    return !_size;
}

void MyString::shrink_to_fit()
{
    if (_size + 1 == _capacity)
    {
        return;
    }

    _capacity = _size + 1;
    resizeUtil(_data, _capacity, true);
}

// Element access:
char &MyString::operator[](size_t idx)
{
    return _data[idx];
}

const char &MyString::operator[](size_t idx) const
{
    return _data[idx];
}

char &MyString::at(size_t idx)
{
    if (idx >= _size)
        throw std::out_of_range("Index out of range.");

    return _data[idx];
}

const char &MyString::at(size_t idx) const
{
    if (idx >= _size)
        throw std::out_of_range("Index out of range.");

    return _data[idx];
}

char &MyString::front()
{
    if (!_size || !_data)
        throw std::invalid_argument("Empty String Exception (nullptr).");

    return _data[0];
}

const char &MyString::front() const
{
    if (!_size || !_data)
        throw std::invalid_argument("Empty String Exception (nullptr).");

    return _data[0];
}

char &MyString::back()
{
    if (!_size || !_data)
        throw std::invalid_argument("Empty String Exception (nullptr).");

    return _data[_size - 1];
}

const char &MyString::back() const
{
    if (!_size || !_data)
        throw std::invalid_argument("Empty String Exception (nullptr).");

    return _data[_size - 1];
}

// Modifiers:
MyString &MyString::operator+=(const MyString &other)
{
    return append(other._data);
}

MyString &MyString::operator+=(const char *data)
{
    return append(data);
}

MyString &MyString::append(const MyString &other)
{

    return append(other._data);
}

MyString &MyString::append(const char *data)
{
    if (data && data[0])
    {
        size_t size = myStrLen(data);

        manageCapacity(_size + size, true);
        myStrCpy(_data, data, _size);
        _size += size;
    }
    return *this;
}

void MyString::push_back(char ch)
{
    manageCapacity(_size + 1, true);
    _data[_size++] = ch;
    _data[_size] = '\0';
}

void MyString::reset_data() noexcept
{
    _data[0] = '\0';
    _size = 0;
}

MyString &MyString::replace(size_t start, size_t len, const MyString &other)
{
    MyString temp = substr(0, start);
    temp.append(other);
    temp.append(substr(start + len, _size - len - start));

    *this = temp;

    return *this;
}

MyString &MyString::replace(size_t start, size_t len, size_t count, char ch)
{
    MyString temp = substr(0, start);

    for (size_t i = 0; i < count; ++i)
    {
        temp.push_back(ch);
    }

    temp.append(substr(start + len, _size - len - start));

    *this = temp;

    return *this;
}

void MyString::swap(MyString &other) noexcept
{
    char *tempData = _data;
    size_t tempSize = _size;
    size_t tempCapacity = _capacity;

    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;

    other._data = tempData;
    other._size = tempSize;
    other._capacity = tempCapacity;
}

void MyString::pop_back() noexcept
{
    if (_size)
    {
        _data[--_size] = '\0';
    }
}

// String operations:
const char *MyString::c_str() const noexcept
{
    return _data;
}

size_t MyString::find_first_of(char ch, size_t pos) const noexcept
{
    for (size_t i = pos; i < _size; ++i)
    {
        if (_data[i] == ch)
        {
            return i;
        }
    }

    return -1;
}

size_t MyString::find_last_of(char ch, size_t pos) const noexcept
{
    if (pos == SIZE_MAX)
    {
        pos = _size - 1;
    }

    for (size_t i = pos; i >= 0; --i)
    {
        if (_data[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

// MyString MyString::substr(size_t start, size_t len) const
// {
//     if (start > _size || len == 0)
//     {
//         throw std::invalid_argument("Indexes out of range.");
//     }

//     MyString temp;

//     if (start == _size)
//     {
//         return temp;
//     }

//     temp.reserve(len);

//     for (size_t i = 0; i < len; ++i)
//     {
//         if (start + i > _size)
//         {
//             break;
//         }
//         temp.push_back(at(start + i));
//     }

//     return temp;
// }

MyString MyString::substr(size_t start, size_t len) const
{
    if (start > _size || len == 0)
        throw std::invalid_argument("Indexes out of range.");

    MyString temp("");

    if (start == _size)
        return temp;

    temp.reserve(len);

    char *p = _data + start;
    char *end = p + len;

    while (p < end && p < _data + _size)
        temp.push_back(*p++);

    return temp;
}

size_t MyString::compare(const MyString &other) const
{
    return compare(other._data);
}

size_t MyString::compare(const char *data) const
{
    if (!data)
        throw std::invalid_argument("Empty String Exception (nullptr).");

    return myStrCmp(_data, data);
}

// Operators:
std::ostream &operator<<(std::ostream &out, const MyString &obj) noexcept
{
    return out << obj.c_str();
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    MyString temp(lhs);
    temp += rhs;
    return temp;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    return lhs.compare(rhs) == 0;
}

bool operator==(const char *lhs, const MyString &rhs)
{
    return rhs.compare(lhs) == 0;
}

bool operator==(const MyString &lhs, const char *rhs)
{
    return lhs.compare(rhs) == 0;
}

bool operator!=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const char *lhs, const MyString &rhs)
{
    return !(lhs == rhs);
}

bool operator!=(const MyString &lhs, const char *rhs)
{
    return !(lhs == rhs);
}

bool operator<(const MyString &lhs, const MyString &rhs)
{
    return lhs.compare(rhs) < 0;
}

bool operator<(const char *lhs, const MyString &rhs)
{
    return rhs.compare(lhs) > 0;
}

bool operator>(const MyString &lhs, const MyString &rhs)
{
    return lhs.compare(rhs) > 0;
}

bool operator>(const char *lhs, const MyString &rhs)
{
    return rhs.compare(rhs) < 0;
}

bool operator>=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs < rhs);
}

bool operator>=(const char *lhs, const MyString &rhs)
{
    return !(lhs < rhs);
}

bool operator<=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs > rhs);
}

bool operator<=(const char *lhs, const MyString &rhs)
{
    return !(lhs > rhs);
}
