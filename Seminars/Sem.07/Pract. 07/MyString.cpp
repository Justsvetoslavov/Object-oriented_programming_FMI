#include "MyString.h"
#include "Utils.h"

// Big 4 follow
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

MyString &MyString::operator+=(const MyString &other)
{
    return append(other._data);
}

MyString &MyString::operator+=(const char *data)
{
    return append(data);
}

char *MyString::operator*() const
{
    return _data;
}
// Member operators end

// Member functions follow
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

int MyString::capacity() const
{
    return _capacity;
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

MyString MyString::substr(int start, int len) const
{
    MyString temp;

    for (int i = 0; i < len; ++i)
    {
        temp.push_back(at(start + i));
    }

    return temp;
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
// Member functions end

// non-member functions follow
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

std::ostream &operator<<(std::ostream &out, const MyString &obj)
{
    return out << obj._data;
}

std::istream &operator>>(std::istream &in, const MyString &obj)
{
    return in >> obj._data;
}

// non-member functions end