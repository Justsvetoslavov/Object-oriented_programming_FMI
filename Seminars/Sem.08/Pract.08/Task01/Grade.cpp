#include "Grade.h"
#include <cstring>

void Grade::free() {
	delete[] _task;
	delete[] _teacher;
}

void Grade::copyFrom(const Grade& other) {
	setTask(other.getTask());
	setValue(other.getValue());
	setTeacher(other.getTeacher());
}

Grade::Grade() {
	_value = 2;
	_task = nullptr;
	_teacher = nullptr;
}

Grade::Grade(double value, const char* task, const char* teacher) {
	setTask(task);
	setValue(value);
	setTeacher(teacher);
}

Grade::Grade(const Grade& other) {
	copyFrom(other);
}

Grade& Grade::operator=(const Grade& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Grade::~Grade() {
	free();
}

double Grade::getValue() const {
	return _value;
}
const char* Grade::getTask() const {
	return _task;
}

const char* Grade::getTeacher() const {
	return _teacher;
}

void Grade::setValue(double value) {
	_value = value;
}

void Grade::setTask(const char* task) {
	int len = strlen(task) + 1;
	_task = new char[len];
	strcpy(_task, task);
}

void Grade::setTeacher(const char* teacher) {
	int len = strlen(teacher) + 1;
	_teacher = new char[len];
	strcpy(_teacher, teacher);
}