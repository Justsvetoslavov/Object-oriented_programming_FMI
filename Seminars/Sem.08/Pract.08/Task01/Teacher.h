#pragma once
#include "String.h"
class Teacher{
private:
	String name;

public:
	Teacher() = default;
	Teacher(const char* name);

	const char* GetName() const;
};

