#include <cstring>

class String {
    char *str;
    unsigned int size;

    void copyStr(const String& str);
public:
    String();

    String(const String& str);

    String(const char* str);

    String& operator=(const String& str);

    ~String();

    void clear();

    char& operator[](const unsigned int pos);

    char operator[](const unsigned int pos) const;

    const char* c_str() const;

    friend String operator+(const String& str1, const String& str2);

    String& operator+=(const String& str);

    friend bool operator==(const String& str1, const String& str2);

    friend bool operator!=(const String& str1, const String& str2);

    friend bool operator>(const String& str1, const String& str2);

    friend bool operator>=(const String& str1, const String& str2);

    friend bool operator<(const String& str1, const String& str2);

    friend bool operator<=(const String& str1, const String& str2);

    unsigned int length() const;

    bool empty() const;

    void append(const char sym);

    bool compare(const String& str) const;
};
