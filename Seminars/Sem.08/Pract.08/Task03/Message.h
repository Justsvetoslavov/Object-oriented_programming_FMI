#pragma once
#include "String.h"
#include <fstream>

class Message{
private:
	String text;
	String sentFrom;

public:
	Message() = default;
	Message(const char* sentFrom, const char* text);

	void Print() const;

	friend std::ostream& operator<<(std::ostream& os, const Message& message);
	friend std::istream& operator>>(std::istream& is, Message& message);
};

