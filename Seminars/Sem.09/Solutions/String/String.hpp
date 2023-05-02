#pragma once

class String {
private:
	char* data = nullptr;
public:
	String() = default;
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	//move semantics
	String(String&&) noexcept;
	String& operator=(String&&) noexcept;

	void Print() const;
private:
	void CopyFrom(const String&);
	void Free();
};