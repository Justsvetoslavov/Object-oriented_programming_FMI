#include "Lecturer.h"
#include <cstring>

void Lecturer::copyFrom(const Lecturer& other) {
	setName(other.getName());
}

void Lecturer::free() {
	delete[] _name;
}

Lecturer::Lecturer(const char* name) {
	setName(name);
}

Lecturer::Lecturer(const Lecturer& other) {
	try
	{
		copyFrom(other);
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}

Lecturer& Lecturer::operator=(const Lecturer& other) {
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

Lecturer::~Lecturer() {
	free();
}

const char* Lecturer::getName() const {
	return _name;
}

void Lecturer::setName(const char* name) {
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