#pragma once
#include <iostream>

class String {
private:
	char* string = nullptr;
	unsigned size = 0;

public:
	String();
	String(const char* str);
	String(const String& other);
	String& operator=(const String& other);
	~String();

	int Size() const;
	char& operator[](int index);
	char operator[](int index) const;
	String& operator+=(const String& right);
	bool operator==(const String& right) const;
	bool operator!=(const String& right) const;
	bool operator<(const String& right) const;
	bool operator<=(const String& right) const;
	bool operator>(const String& right) const;
	bool operator>=(const String& right) const;

	bool IsEmpty() const;
	void Clear();
	void Append(char toBeAppended);
	int Compare(const String& string) const;

	const char* c_str() const;
	int GetSize() const;

	friend String operator+(const String& left, const String& right);
	friend std::istream& operator>>(std::istream& is, String& string);

private:
	void free();
	void copyFrom(const String& other);
	void SetSize(const char* string);
};

std::istream& operator>>(std::istream& is, String& string);
