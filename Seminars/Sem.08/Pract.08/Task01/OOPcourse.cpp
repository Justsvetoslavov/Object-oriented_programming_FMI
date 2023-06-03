#include "OOPCourse.h"
#include <iostream>
#pragma warning (disable : 4996)
const int MAX_ASSISTANTS_SIZE = 3;

void OOPCourse::CopyFrom(const OOPCourse& other) {
	this->students = new Student[other.studentsCount];
	this->studentsCount = other.studentsCount;
	for (size_t i = 0; i < studentsCount; i++)
	{
		this->students[i] = other.students[i];
	}
	this->teachersCount = other.teachersCount;
	for (size_t i = 0; i < teachersCount; i++)
	{
		this->teachers[i] = other.teachers[i];
	}
}

OOPCourse::OOPCourse(const char* lecturer, const char* assistant1) {
	this->teachers[0] = Teacher(lecturer);
	this->teachers[1] = Teacher(assistant1);
	this->studentsCapacity = 8;
	this->students = new Student[studentsCapacity];
	this->teachersCount = 2;
}
OOPCourse::OOPCourse(const char* lecturer, const char* assistant1, const char* assistant2)
	: OOPCourse(lecturer, assistant1) {
	this->teachers[2] = Teacher(assistant2);
	this->teachersCount++;
}
OOPCourse::OOPCourse(const char* lecturer, const char* assistant1, const char* assistant2,
	const char* assistant3) : OOPCourse(lecturer, assistant1, assistant2) {
	this->teachers[3] = Teacher(assistant3);
	this->teachersCount++;
}

void OOPCourse::Free() {
	delete[] this->students;
	this->students = nullptr;
	this->teachersCount = 0;
	this->studentsCount = 0;
}

OOPCourse::OOPCourse(const OOPCourse& other) {
	CopyFrom(other);
}
OOPCourse& OOPCourse::operator=(const OOPCourse& other) {
	if (this != &other) {
		Free();
		CopyFrom(other);
	}
	return *this;
}
OOPCourse::~OOPCourse() {
	Free();
}

void OOPCourse::Resize(size_t newCapacity) {
	Student* temp = this->students;
	this->students = new Student[newCapacity];

	for (size_t i = 0; i < studentsCount; i++)
	{
		this->students[i] = temp[i];
	}
	this->studentsCapacity = newCapacity;
	delete[] temp;
}

void OOPCourse::AddStudent(const char* stName, int fn) {
	if (this->studentsCount >= this->studentsCapacity)
		Resize(this->studentsCapacity * 2);

	this->students[studentsCount++] = Student(stName, fn);
}

void OOPCourse::AddGrade(int fn, const char* taskName, double grade, const char* teacherName) {
	if (!taskName)
		throw std::invalid_argument("Invalid value for task name!");

	if (!TeacherExists(teacherName))
		throw std::invalid_argument("This teacher doesn't exist!");

	for (size_t i = 0; i < studentsCount; i++)
	{
		if (students[i].GetFn() == fn) {
			students[i].AddTask(taskName, grade, teacherName);
			return;
		}
	}

	throw std::invalid_argument("A student with this fn doesn't exist!");
}
double OOPCourse::GetAverigeForCourse() const {
	double gradesSum = 0;
	int gradesCount = 0;
	for (size_t i = 0; i < studentsCount; i++)
	{
		for (size_t j = 0; j < students[i].GetTasksCount(); i++)
		{
			gradesSum += students[i].GetTasks()[j].GetGrade();
			gradesCount++;
		}
	}
	return gradesCount > 0 ? gradesSum / gradesCount : 0;
}
void OOPCourse::RemoveStudent(int fn) {
	for (size_t i = 0; i < studentsCount; i++)
	{
		if (students[i].GetFn() == fn) {
			std::swap(students[i], students[studentsCount - 1]);
			studentsCount--;
			return;
		}
	}
	throw std::invalid_argument("A student with this fn doesn't exist!");
}
double OOPCourse::GetAverigeGradePerTask(const char* taskName) const {
	if (!taskName)
		throw std::invalid_argument("Invalid value for task name!");

	double gradesSum = 0;
	int gradesCount = 0;

	for (size_t i = 0; i < studentsCount; i++)
	{
		for (size_t j = 0; j < students[i].GetTasksCount(); j++)
		{
			if (!strcmp(students[i].GetTasks()[j].GetTaskName(), taskName)) {
				gradesCount++;
				gradesSum += students[i].GetTasks()[j].GetGrade();
			}
		}
	}
	return gradesCount > 0 ? gradesSum / gradesCount : 0;
}

bool OOPCourse::TeacherExists(const char* teacherName) const {
	if (!teacherName)
		return false;

	for (size_t i = 0; i < teachersCount; i++)
	{
		if (!strcmp(this->teachers[i].GetName(), teacherName))
			return true;
	}
	return false;
}

double OOPCourse::GetAverigeFromTeacher(const char* teacherName) const {
	if (!TeacherExists(teacherName))
		throw std::invalid_argument("This teacher doesn't exist!");

	double gradesSum = 0;
	int gradesCount = 0;

	for (size_t i = 0; i < studentsCount; i++)
	{
		for (size_t j = 0; j < students[i].GetTasksCount(); j++)
		{
			if (!strcmp(students[i].GetTasks()[j].GetTeacherName(), teacherName)) {
				gradesCount++;
				gradesSum += students[i].GetTasks()[j].GetGrade();
			}

		}
	}
	return gradesCount > 0 ? gradesSum / gradesCount : 0;
}