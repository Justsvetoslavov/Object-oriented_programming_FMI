#include "Teacher.h"

const char* DEFAULT_NAME = "";

Teacher::Teacher() : Teacher(DEFAULT_NAME){

}

Teacher::Teacher(const char* name) {
	_name = MyString(name);
}

std::ostream& operator << (std::ostream& os, const Teacher& teacher) {
	return os << teacher._name;
}