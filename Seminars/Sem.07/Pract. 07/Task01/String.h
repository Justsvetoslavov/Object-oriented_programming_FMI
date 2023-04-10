#pragma once

class String {
	char* str = nullptr;

	void free();
	void copyFrom(const String& other);
	void copyStr(const char* str);

	// Helper function for append()
	String(char ch);

public:
	// BIG 4
	String();
	String(const String& other);
	String& operator=(const String& other);
	~String();

	String(const char* str);

	char operator[](size_t ind) const; // get
	char& operator[](size_t ind); // set
	String& operator+=(const String& other);

	size_t length() const;
	bool empty() const;
	void clear();
	const char* c_str() const;
	void append(char symbol);
	int compare(const String& other) const;

	void print() const;

	friend String operator+(const String& str1, const String& str2);
	friend bool operator==(const String& str1, const String& str2);
	friend bool operator!=(const String& str1, const String& str2);
	friend bool operator<(const String& str1, const String& str2);
	friend bool operator>(const String& str1, const String& str2);
	friend bool operator<=(const String& str1, const String& str2);
	friend bool operator>=(const String& str1, const String& str2);
};




