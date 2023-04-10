#include "MyString.h"
#include "Utils.h"

/*
------------------------------------------------------------------------------------------
Dear reviewer, I hope you will appreciate the effort I put for this task/mini project :)
Thank you
------------------------------------------------------------------------------------------
*/

// Big 4
MyString::MyString() : _data(new char[DEFAULT_CAPACITY]{'\0'}), _capacity(DEFAULT_CAPACITY) {}

MyString::MyString(const char *data) : _data(new char[DEFAULT_CAPACITY]{'\0'}), _capacity(DEFAULT_CAPACITY)
{
    setData(data);
}

MyString::MyString(const MyString &other)
{
    copyFrom(other);
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

MyString::~MyString()
{
    free();
}

char *MyString::operator*() const
{
    return _data;
}

// Big 4 helper functions
void MyString::manageCapacity(int size, bool shouldCopy)
{
    if (size >= _capacity)
    {
        while (size >= _capacity)
        {
            _capacity <<= 1;
        }
        resizeUtil(_data, _capacity, shouldCopy);
    }
}

void MyString::setData(const char *data)
{
    if (!data)
    {
        return;
    }

    int size = myStrLen(data);

    manageCapacity(size, false);
    myStrCpy(_data, data);
    _size = size;
}

void MyString::free()
{
    delete[] _data;
    _data = nullptr;

    _size = 0;
    _capacity = 0;
}

void MyString::copyFrom(const MyString &other)
{
    copyData(other._data);
}

void MyString::copyData(const char *data)
{
    _data = new char[DEFAULT_CAPACITY]{'\0'};
    _capacity = DEFAULT_CAPACITY;

    if (!data)
    {
        return;
    }

    int size = myStrLen(data);
    manageCapacity(size, false);
    myStrCpy(_data, data);
    _size = size;
}

// Capacity:
int MyString::size() const
{
    return _size;
}

int MyString::length() const
{
    return _size;
}

void MyString::resize(int len, char ch)
{
    if (len <= 0)
    {
        throw "Out of Range Exception";
    }

    if (len > _size)
    {
        int oldSize = _size;

        for (int i = 0; i < len - oldSize; ++i)
        {
            push_back(ch);
        }
        return;
    }

    if (len == _size)
    {
        return;
    }

    MyString temp;
    temp.append(substr(0, len));

    *this = temp;
}

int MyString::capacity() const
{
    return _capacity;
}

void MyString::reserve(int len)
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

bool MyString::empty() const
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
char &MyString::operator[](int idx)
{
    return _data[idx];
}

const char &MyString::operator[](int idx) const
{
    return _data[idx];
}

char &MyString::at(int idx)
{
    if (idx < 0 || idx > _size)
    {
        throw "Index Out Of Bound Exception";
    }
    return _data[idx];
}

const char &MyString::at(int idx) const
{
    if (idx < 0 || idx > _size)
    {
        throw "Index Out Of Bound Exception";
    }
    return _data[idx];
}

char &MyString::front()
{
    if (!_size)
    {
        throw "Empty String Exception";
    }

    return _data[0];
}

const char &MyString::front() const
{
    if (!_size)
    {
        throw "Empty String Exception";
    }

    return _data[0];
}

char &MyString::back()
{
    if (!_size)
    {
        throw "Empty String Exception";
    }

    return _data[_size - 1];
}

const char &MyString::back() const
{
    if (!_size)
    {
        throw "Empty String Exception";
    }

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
    if (data && data[0] != '\0')
    {
        int size = myStrLen(data);

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

MyString &MyString::replace(int start, int len, const MyString &other)
{
    MyString temp = substr(0, start);
    temp.append(other);
    temp.append(substr(start + len, _size - len - start));

    *this = temp;

    return *this;
}

MyString &MyString::replace(int start, int len, int count, char ch)
{
    MyString temp = substr(0, start);

    for (int i = 0; i < count; ++i)
    {
        temp.push_back(ch);
    }

    temp.append(substr(start + len, _size - len - start));

    *this = temp;

    return *this;
}

void MyString::swap(MyString &other)
{
    char *tempData = _data;
    int tempSize = _size;
    int tempCapacity = _capacity;

    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;

    other._data = tempData;
    other._size = tempSize;
    other._capacity = tempCapacity;
}

void MyString::pop_back()
{
    if (_size)
    {
        _data[--_size] = '\0';
    }
}

// String operations:
const char *MyString::c_str() const
{
    return _data;
}

int MyString::find_first_of(char ch, int pos) const
{
    if (pos < 0)
    {
        throw "Out Of Range Exception";
    }

    for (int i = pos; i < _size; ++i)
    {
        if (_data[i] == ch)
        {
            return i;
        }
    }

    return -1;
}

int MyString::find_last_of(char ch, int pos) const
{
    if (pos < 0)
    {
        throw "Out Of Range Exception";
    }

    if (pos == INT_MAX)
    {
        pos = _size - 1;
    }

    for (int i = pos; i >= 0; --i)
    {
        if (_data[i] == ch)
        {
            return i;
        }
    }
    return -1;
}

MyString MyString::substr(int start, int len) const
{
    if (start < 0 || start > _size || len <= 0)
    {
        throw "Out Of Range Exception";
    }

    if (start == _size)
    {
        return "";
    }

    MyString temp;
    temp.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        if (start + i > _size)
        {
            break;
        }
        temp.push_back(at(start + i));
    }

    return temp;
}

int MyString::compare(const MyString &other) const
{
    return compare(other._data);
}

int MyString::compare(const char *data) const
{
    if (!data)
    {
        throw "nullptr exception";
    }
    return myStrCmp(_data, data);
}

// Operators:
std::ostream &operator<<(std::ostream &out, const MyString &obj)
{
    return out << obj._data;
}

std::istream &operator>>(std::istream &in, const MyString &obj)
{
    return in >> obj._data;
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

bool operator!=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const MyString &lhs, const MyString &rhs)
{
    return lhs.compare(rhs) < 0;
}

// never gets called because const char* is converted to MyString object first by converting constructor.
// leaving code for completeness.
bool operator<(const char *lhs, const MyString &rhs)
{
    return rhs.compare(lhs) > 0;
}

bool operator>(const MyString &lhs, const MyString &rhs)
{
    return lhs.compare(rhs) > 0;
}

// never gets called because const char* is converted to MyString object first by converting constructor.
// leaving code for completeness.
bool operator>(const char *lhs, const MyString &rhs)
{
    return rhs.compare(rhs) < 0;
}

bool operator>=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs < rhs);
}

// never gets called because const char* is converted to MyString object first by converting constructor.
// leaving code for completeness.
bool operator>=(const char *lhs, const MyString &rhs)
{
    return !(rhs > rhs);
}

bool operator<=(const MyString &lhs, const MyString &rhs)
{
    return !(lhs > rhs);
}

// never gets called because const char* is converted to MyString object first by converting constructor.
// leaving code for completeness.
bool operator<=(const char *lhs, const MyString &rhs)
{
    return !(rhs < lhs);
}
