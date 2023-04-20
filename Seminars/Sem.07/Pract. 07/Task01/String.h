#pragma once
class String
{
	char* data;
	size_t size;

	void copyFrom(const String& other);
	void free();

public:
	String();
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	size_t length() const;
	bool empty() const;
	void clear();
	const char* c_str() const;
	void append(char symbol);
	int compare(const String& other) const;
	String substr(size_t start, size_t length) const;

	String& operator+=(const String& other);
	bool operator==(const String& other) const;
	bool operator!=(const String& other) const;

	char operator[](size_t idx) const;
	char& operator[](size_t idx);
};

String operator+(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);


