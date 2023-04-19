#pragma once
#include <ostream>

class String
{
private:
	char* myStr;
public:
	String() = default;

	String(const char* string);

	String(String& other);

	String& operator=(String& other);

	char operator[](size_t index);

	String& operator+=(const String& other);

	friend String operator+(const String& lStr,const String& rStr);

	friend bool operator==(const String& lStr,const String& rStr);

	friend bool operator!=(const String& lStr, const String& rStr);

	friend bool operator>(const String& lStr, const String& rStr);

	friend bool operator<(const String& lStr, const String& rStr);

	friend bool operator>=(const String& lStr, const String& rStr);

	friend bool operator<=(const String& lStr, const String& rStr);

	friend std::ostream& operator<<(std::ostream& os, const String& string);
	
	friend std::istream& operator>>(std::istream& is, const String& string);

	void setMyStr(const char* string);

	char* getMyStr() const;

	friend size_t length(const String& myStr);

	bool isEmpthy(const String& myStr);

	void clear(String& myStr);

	const char* c_str(const String& myStr);

	String append(char letter);

	~String();
};