#include "Teacher.h"
#include <cstring>
#pragma warning (disable : 4996)

void Teacher::CopyFrom(const Teacher& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}
void Teacher::Free() {
	delete[] this->name;
	this->name = nullptr;
}

Teacher::Teacher(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Teacher::Teacher(const Teacher& other) {
	CopyFrom(other);
}
Teacher& Teacher::operator=(const Teacher& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
Teacher::~Teacher() {
	Free();
}

const char* Teacher::GetName() const {
	return this->name;
}