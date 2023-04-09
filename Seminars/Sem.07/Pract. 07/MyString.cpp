#include "MyString.h"
#include "Utils.h"

// Big 4 follow
MyString::MyString(const char *data)
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
// Big 4 end

// Big 4 helper functions follow
void MyString::setData(const char *data)
{
    if (!data)
    {
        _data = new char[DEFAULT_CAPACITY]{'\0'};
        return;
    }

    int size = myStrLen(data);

    if (size >= _capacity)
    {
        while (size >= _capacity)
        {
            _capacity *= 2;
        }
        resize(_data, _capacity, false);
    }

    myStrCpy(_data, data);
    _size = size;
}

void MyString::copyFrom(const MyString &other)
{
    copyData(other._data);
}

void MyString::copyData(const char *data)
{
    setData(data);
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

        if (size >= _capacity)
        {
            while (size >= _capacity)
            {
                _capacity *= 2;
            }
            resize(_data, _capacity, true);
        }

        myStrCpy(_data, data, size);
        _size += size;
    }
    return *this;
}
