#include "Student.h"
#include <iostream>
#pragma warning (disable : 4996)
void Student::CopyFrom(const Student& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->fn = other.fn;
	this->tasksCount = other.tasksCount;
	for (size_t i = 0; i < tasksCount; i++)
	{
		this->tasks[i] = other.tasks[i];
	}
}
void Student::Free() {
	delete[] this->name;
	this->name = nullptr;
	this->fn = 0;
	this->tasksCount = 0;
}

Student::Student(const char* name, int fn) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->fn = fn;
}
Student::Student(const Student& other) {
	CopyFrom(other);
}
Student& Student::operator=(const Student& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
Student::~Student() {
	Free();
}

void Student::AddTask(const char* taskName, double grade, const char* teacherName) {
	if (tasksCount >= GRADES_MAX_COUNT)
		throw std::length_error("Tasks count should be max 7!");

	Task newTask(taskName, grade, teacherName);
	this->tasks[tasksCount++] = newTask;
}

int Student::GetFn() const {
	return this->fn;
}

int Student::GetTasksCount() const {
	return this->tasksCount;
}

const Task* Student::GetTasks() const {
	return this->tasks;
}