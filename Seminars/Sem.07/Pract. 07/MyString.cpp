#include "MyString.h"
#include "Utils.h"

// Big 4 follow
MyString::MyString(const char *data)
{
    _data = new char[DEFAULT_CAPACITY]{'\0'};
    _capacity = DEFAULT_CAPACITY;

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
// Big 4 end

// Big 4 helper functions follow
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

void MyString::free()
{
    delete[] _data;
    _data = nullptr;

    _size = 0;
    _capacity = 0;
}
// Big 4 helper functions end

// Member operators follow
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
    return operator[](idx);
}

const char &MyString::at(int idx) const
{
    if (idx < 0 || idx > _size)
    {
        throw "Index Out Of Bound Exception";
    }
    return operator[](idx);
}

MyString &MyString::operator+=(const MyString &other)
{
    return append(other._data);
}

MyString &MyString::operator+=(const char *data)
{
    return append(data);
}
// Member operators end

// not sorted
MyString &MyString::append(const MyString &other)
{
    if (other._data)
    {
        append(other._data);
    }
    return *this;
}

MyString &MyString::append(const char *data)
{
    if (data)
    {
        int size = myStrLen(data);

        manageCapacity(_size + size, true);
        myStrCpy(_data, data, _size);
        _size += size;
    }
    return *this;
}

void MyString::manageCapacity(int size, bool shouldCopy)
{
    if (size >= _capacity)
    {
        while (size >= _capacity)
        {
            _capacity *= 2;
        }
        resize(_data, _capacity, shouldCopy);
    }
}

int MyString::length() const
{
    return _size;
}

int MyString::size() const
{
    return _size;
}

bool MyString::empty() const
{
    return !_size;
}

void MyString::clear()
{
    resize(_data, DEFAULT_CAPACITY, false);

    _capacity = DEFAULT_CAPACITY;
    _data[0] = '\0';
    _size = 0;
}

int MyString::compare(const MyString &other) const
{
    if (!other._data)
    {
        throw "nullptr exception";
    }
    return myStrCmp(_data, other._data);
}

int MyString::compare(const char *data) const
{
    if (!data)
    {
        throw "nullptr exception";
    }
    return myStrCmp(_data, data);
}

void MyString::shrink_to_fit()
{
    if (_size + 1 == _capacity)
    {
        return;
    }

    _capacity = _size + 1;
    resize(_data, _capacity, true);
}

void MyString::push_back(char ch)
{
    manageCapacity(_size + 1, true);
    _data[_size++] = ch;
    _data[_size] = '\0';
}

void MyString::pop_back()
{
    if (_size)
    {
        _data[--_size] = '\0';
    }
}

const char *MyString::c_str() const
{
    return _data;
}