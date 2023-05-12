#include "Teacher.h"

Teacher::Teacher(const char* name){
	this->name = name;
}

const char* Teacher::GetName() const{
	return name.c_str();
}
