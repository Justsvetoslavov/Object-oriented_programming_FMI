#include "Task.h"
#include <iostream>
#pragma warning (disable : 4996)
void Task::CopyFrom(const Task& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->grade = other.grade;
	this->teacherName = new char[strlen(other.teacherName) + 1];
	strcpy(this->teacherName, other.teacherName);
}
void Task::Free() {
	delete[] this->name;
	delete[] this->teacherName;
	this->name = nullptr;
	this->teacherName = nullptr;
	this->grade = 0;
}

Task::Task(const char* name, double grade, const char* teacherName) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->grade = grade;
	this->teacherName = new char[strlen(teacherName) + 1];
	strcpy(this->teacherName, teacherName);
}
Task::Task(const Task& other) {
	CopyFrom(other);
}
Task& Task::operator=(const Task& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
Task::~Task() {
	Free();
}

double Task::GetGrade() const {
	return this->grade;
}

const char* Task::GetTaskName() const {
	return this->name;
}

const char* Task::GetTeacherName() const {
	return this->teacherName;
}