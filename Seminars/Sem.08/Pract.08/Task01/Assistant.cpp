#include "Assistant.h"
#include <cstring>

void Assistant::copyFrom(const Assistant& other) {
	setName(other.getName());
}

void Assistant::free() {
	delete[] _name;
}

Assistant::Assistant() {
	_name = new char[1];
	_name[0] = '\0';
}

Assistant::Assistant(const char* name) {
	setName(name);
}

Assistant::Assistant(const Assistant& other) {
	copyFrom(other);
}

Assistant& Assistant::operator=(const Assistant& other) {
	try
	{
		if (this != &other)
		{
			free();
			copyFrom(other);
		}
		return *this;
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}

Assistant::~Assistant() {
	free();
}

const char* Assistant::getName() const {
	return _name;
}

void Assistant::setName(const char* name) {
	try
	{
		int len = strlen(name) + 1;
		_name = new char[len];
		strcpy(_name, name);
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}