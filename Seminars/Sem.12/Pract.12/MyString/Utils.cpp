#include <iostream>

void myStrCpy(char *destination, const char *source, size_t startIdx)
{
    if (!destination || !source)
        return;

    size_t idx = 0;

    while (source[idx])
    {
        destination[startIdx] = source[idx];
        ++startIdx;
        ++idx;
    }
    destination[startIdx] = '\0';
}

int myStrLen(const char *str)
{
    const char *s = str;

    while (*s)
    {
        ++s;
    }

    return (s - str);
}

void resizeUtil(char *&data, int capacity, bool shouldCopy)
{
    char *newData = new char[capacity];

    if (shouldCopy)
    {
        myStrCpy(newData, data, 0);
    }

    delete[] data;

    data = newData;
}

int myStrCmp(const char *s1, const char *s2)
{
    if (!s1 || !s2)
    {
        return false;
    }
    while (*s1 && *s1 == *s2)
    {
        ++s1;
        ++s2;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}