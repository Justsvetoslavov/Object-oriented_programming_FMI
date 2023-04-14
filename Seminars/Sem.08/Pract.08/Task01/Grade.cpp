#include "Grade.h"

#include <cstring>
#pragma warning(disable : 4996)


bool Grade::isValidGrade() const {
	return (_value >= 2 && _value <= 6) && _task.length() != 0 && _teacher != nullptr;
}

void  Grade::setValue(double value) {
	if (value >= 2 && value <= 6) {
		_value = value;
	}
}

void  Grade::setTask(const char* task) {
	_task = MyString(task);
}

void Grade::setTeacher(const Teacher* teacher){
	_teacher = teacher;
}

double Grade::getValue() const {
	return _value;
}

const MyString& Grade::getTask() const {
	return _task;
}

const Teacher* Grade::getTeacher() const{
	return _teacher;
}

Grade::Grade(double value, const char* task, const Teacher* teacher) {
	setValue(value);
	setTask(task);
	setTeacher(teacher);
}

std::ostream& operator<<(std::ostream& os, const Grade& grade) {
	return os << grade._task << " " << *grade._teacher << " " << grade._value;
}