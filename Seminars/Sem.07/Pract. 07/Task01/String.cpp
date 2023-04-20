#include "String.h"
#include <cstring>

String::String()
{
    m_size = 0;
    m_capacity = CAPACITY_PADDING_AFTER_RESIZE;
    m_data = new char[m_capacity];
    m_data[0] = '\0';
}

String::String(const char *str)
{
    if (!str)
        return;

    m_size = strlen(str);
    m_capacity = m_size + CAPACITY_PADDING_AFTER_RESIZE;
    m_data = new char[m_capacity];
    strcpy(m_data, str);
}

String::String(const String &copy)
        : m_data(nullptr), m_size(0)
{
    CopyFrom(copy);
}

String::~String()
{
    Free();
}

String &String::operator=(const String &other)
{
    if (*this != other)
    {
        Free();
        CopyFrom(other);
    }

    return *this;
}

void String::Free()
{
    m_size = 0;
    m_capacity = 0;
    delete[] m_data;
}
void String::CopyFrom(const String &other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = new char[m_size];
    strcpy(m_data, other.m_data);
}
size_t String::length() const
{
    return m_size;
}
bool String::empty() const
{
    return m_size == 0;
}
void String::clear()
{
    Free();
    m_size = 0;
    m_capacity = CAPACITY_PADDING_AFTER_RESIZE;
    m_data = new char[m_capacity];
    m_data[0] = '\0';
}
const char *String::c_str() const
{
    return m_data;
}
String &String::append(char ch)
{
    if (m_size + 1 >= m_capacity) //resize
    {
        size_t newCapacity = m_capacity + CAPACITY_PADDING_AFTER_RESIZE;
        char *temp = new char[newCapacity];
        for (int i = 0; i < m_size; ++i)
        {
            temp[i] = m_data[i];
        }

        delete[] m_data;
        m_capacity = newCapacity;
        m_data = temp;
    }

    m_data[m_size++] = ch;
    m_data[m_size] = '\0';
}
int String::compare(const String &str)
{
    return strcmp(m_data, str.m_data);
}
char &String::operator[](size_t index)
{
    if (index >= m_size)
        throw std::range_error("Outside of the string!");

    return m_data[index];
}
char String::operator[](size_t index) const
{
    if (index >= m_size)
        throw std::range_error("Outside of the string!");

    return m_data[index];
}
String &String::operator+=(const String &other)
{
    m_size += other.m_size;
    m_capacity = m_size + CAPACITY_PADDING_AFTER_RESIZE;

    char *temp = new char[m_capacity];
    strcpy(temp, m_data);
    strcat(temp, other.m_data);

    delete[] m_data;
    m_data = temp;

    return *this;
}
bool String::operator==(const String &other) const
{
    return strcmp(m_data, other.m_data) == 0;
}
bool String::operator!=(const String &other) const
{
    return !(*this == other);
}
bool String::operator<(const String &other) const
{
    return strcmp(m_data, other.m_data) < 0;
}
bool String::operator<=(const String &other) const
{
    return strcmp(m_data, other.m_data) <= 0;
}
bool String::operator>(const String &other) const
{
    return strcmp(m_data, other.m_data) > 0;
}
bool String::operator>=(const String &other) const
{
    return strcmp(m_data, other.m_data) >= 0;
}
String operator+(const String &lhs, const String &rhs)
{
    String cpy(lhs);
    cpy.operator+=(rhs);
    return cpy;
}
std::ostream &operator<<(std::ostream &ofs, const String &str)
{
    return ofs << str.m_data;
}
std::istream &operator>>(std::istream &ifs, String &str)
{
    char buffer[1024];
    ifs >> buffer;

    str.Free();
    str = String(buffer);

    return ifs;
}
