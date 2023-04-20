#ifndef TASK1_STRING_H
#define TASK1_STRING_H

#include <fstream>

class String
{
    static const int CAPACITY_PADDING_AFTER_RESIZE = 15;

    char *m_data;
    size_t m_size;
    size_t m_capacity;

    void Free();
    void CopyFrom(const String &other);

public:
    String();
    String(const char *str);
    String(const String &copy);
    ~String();
    String &operator=(const String &other);

    size_t length() const;
    bool empty() const;
    void clear();
    const char *c_str() const;
    String &append(char ch);
    int compare(const String &str);

    char operator[](size_t index) const;
    char& operator[](size_t index);

    String &operator+=(const String &other);

    bool operator==(const String &other) const;
    bool operator!=(const String &other) const;

    bool operator<(const String &other) const;
    bool operator<=(const String &other) const;
    bool operator>(const String &other) const;
    bool operator>=(const String &other) const;

    friend std::ostream &operator<<(std::ostream &ofs, const String &str);
    friend std::istream &operator>>(std::istream &ifs, String &str);
};

String operator+(const String &lhs, const String &rhs);
std::ostream &operator<<(std::ostream &ofs, const String &str);
std::istream &operator>>(std::istream &ifs, String &str);

#endif //TASK1_STRING_H
