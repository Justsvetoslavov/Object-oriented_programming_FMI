#pragma once
#include <iostream>
#include <cstring>


class String
{
	char* data;

public:
	String();
	String(const String& other);
	String(const char* data);
	String& operator=(const String& other);
	~String();

	char& operator[](size_t elem);
	String& operator+=(const String& string);
	bool operator==(const String& string);
	bool operator!=(const String& string);
	bool operator<=(const String& string);
	bool operator>=(const String& string);

	size_t length() const;
	bool empty() const;
	void clear();
	const char* c_str() const;
	String append(const String& lhs, const String& rhs) ;
	bool compare(const char* data1) const;

	friend String operator+(const String& lhs, const String& rhs);
	friend bool operator<(const String& lhs, const String& rhs);
	friend bool operator>(const String& lhs, const String& rhs);

	friend std::ostream& operator<<(std::ostream& os, const String& string);
	friend std::ostream& operator>>(std::istream& is, const String& string);
private:
	void CopyFrom(const String& other);
	void Free();
};

