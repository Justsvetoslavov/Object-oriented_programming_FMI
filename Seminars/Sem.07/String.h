#pragma once

class String
{
private:
	char* str;
public:
	String();
	String(const char* text);
	String(const String& text);
	~String();

	char* getString() const;
	void setString(const char* text);

	String& operator=(const String& other);
	String& operator+(const String& other);
	String& operator+=(const String& other);
	friend std::ostream& operator<<(std::ostream& os, const String& text);
	friend std::istream& operator>>(std::istream& is, String& text);
	friend bool operator==(const String& str1, const String& str2);
	friend bool operator!=(const String& str1, const String& str2);
	friend bool operator<(const String& str1, const String& str2);
	friend bool operator>(const String& str1, const String& str2);
	friend bool operator<=(const String& str1, const String& str2);
	friend bool operator>=(const String& str1, const String& str2);
	
	int length() const;
	bool empty() const;
	void clear();
	const char* c_str();
	int append(const char& symbol);
	int compare(const String& other);

private:
	void free();
	void copyFrom(const char* text);
};