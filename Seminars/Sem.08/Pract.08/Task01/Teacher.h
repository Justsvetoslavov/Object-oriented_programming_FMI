#pragma once

#include "MyString.h"

class Teacher {
	MyString _name;
public:
	Teacher();
	Teacher(const char* name);

	friend std::ostream& operator << (std::ostream& os, const Teacher& teacher);
};