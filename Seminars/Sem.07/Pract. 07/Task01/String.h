#pragma once
class String
{
	char* content;
	size_t size;

	void copyFrom(const  String&);
	void free();

public:

	String();
	String(const char* );
	String(const String&);
	String& operator=(const String&);
	~String();
	
	char operator[](size_t index)const;
	void concat(const String& other);
	
	String& operator +=(const String& );
	friend String& operator+(const String& lhs, const String& rhs);
	friend bool operator ==(const String& lhs, const String& rhs);
	friend bool operator !=(const String& lhs, const String& rhs);
	friend bool operator <(const String& lhs, const String& rhs);
	friend bool operator >(const String& lhs, const String& rhs);
	friend bool operator <=(const String& lhs, const String& rhs);
	friend bool operator >=(const String& lhs, const String& rhs);

	size_t length()const;
	const char* c_str()const;
	void setName(const char*);
	void clear();
	bool empty()const;
	void append(char ch);
	int compare(const String& other)const;

}; 



