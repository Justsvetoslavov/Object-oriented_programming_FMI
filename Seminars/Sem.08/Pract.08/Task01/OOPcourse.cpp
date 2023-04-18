#include "OOPcourse.h"
#include <cstring>
#include <iostream>

void OOPcourse::copyFrom(const OOPcourse& other) {
	for (size_t i = 0; i < 3; ++i)
	{
		_assistants[i] = other.getAssistants()[i];
	}

	_studentsCount = other.getStudentsCount();
	_capacity = other.getCapacity();
	for (size_t i = 0; i < _studentsCount; i++)
	{
		_students[i] = other.getStudents()[i];
	}
}

void OOPcourse::free() {
	for (size_t i = 0; i < _studentsCount; ++i)
	{
		delete& _students[i];
	}

	delete[] _students;
	_studentsCount = 0;
}

void OOPcourse::resize() {
	_capacity *= 2;
	Student* students = new Student[_capacity];
	for (size_t i = 0; i < _studentsCount; ++i)
	{
		students[i] = _students[i];
	}

	free();
	_students = students;
}

Student* OOPcourse::getStudentByFN(const char* FN) {
	for (size_t i = 0; i < _studentsCount; ++i)
	{
		if (!strcmp(_students[i].getFN(), FN))
		{
			return &_students[i];
		}
	}
	return nullptr;
}

OOPcourse::OOPcourse(const char* lecturerName, const char* assistantName)
	: _lecturer(lecturerName) {
	_assistants[0] = Assistant(assistantName);
	_students = new Student[OOPcourseC::STARTING_STUDENTS_COUNT];
}

OOPcourse::OOPcourse(const char* lecturerName, const char* assistantName, const char* secondAssistantName) : _lecturer(lecturerName) {
	_assistants[0] = Assistant(assistantName);
	_assistants[1] = Assistant(secondAssistantName);
	_students = new Student[OOPcourseC::STARTING_STUDENTS_COUNT];
}

OOPcourse::OOPcourse(const char* lecturerName, const char* assistantName, const char* secondAssistantName, const char* thirdAssistantName) : _lecturer(lecturerName) {
	_assistants[0] = Assistant(assistantName);
	_assistants[1] = Assistant(secondAssistantName);
	_assistants[2] = Assistant(thirdAssistantName);
	_students = new Student[OOPcourseC::STARTING_STUDENTS_COUNT];
}

OOPcourse::OOPcourse(const OOPcourse& other) : _lecturer(other.getLecturer()) {
	copyFrom(other);
}

OOPcourse& OOPcourse::operator = (const OOPcourse& other) {
	if (this != &other)
	{
		_lecturer = other.getLecturer();
		free();
		copyFrom(other);
	}
	return *this;
}

OOPcourse::~OOPcourse() {
	free();
}

const Lecturer& OOPcourse::getLecturer() const {
	return _lecturer;
}

const Assistant* OOPcourse::getAssistants() const {
	return _assistants;
}

const Student* OOPcourse::getStudents() const {
	return _students;
}

size_t OOPcourse::getStudentsCount() const {
	return _studentsCount;
}

size_t OOPcourse::getCapacity() const {
	return _capacity;
}

void OOPcourse::addStudent(const char* name, const char* FN) {
	if (_studentsCount == _capacity)
	{
		resize();
	}

	_students[_studentsCount++] = *(new Student(name, FN));
}

void OOPcourse::addGrade(const char* FN, const char* task, double value, const char* teacherName) {
	Student* ptr = getStudentByFN(FN);
	try
	{
		ptr->addGrade(task, value, teacherName);
		delete ptr;
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}

void OOPcourse::editGrade(const char* FN, const char* task, double value, const char* teacherName) {
	Student* ptr = getStudentByFN(FN);
	try
	{
		ptr->editGrade(task, value, teacherName);
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}

double OOPcourse::getAverageForCourse() const {
	double result = 0;
	for (size_t i = 0; i < _studentsCount; ++i)
	{
		result += _students[i].getAverageGrade();
	}
	return _studentsCount > 0 ? result / _studentsCount : 0;
}

double OOPcourse::getAverageGradePerTask(const char* task) const {
	double result = 0;
	size_t count = 0;
	for (size_t i = 0; i < _studentsCount; i++)
	{
		for (size_t j = 0; j < _students[i].getGradesCount(); j++)
		{
			if (!strcmp(_students[i].getGrades()[j].getTask(), task))
			{
				result += _students[i].getGrades()[j].getValue();
				count++;
			}
		}
	}

	return _studentsCount > 0 ? result / count : 0;
}

double OOPcourse::getAverageFromTeacher(const char* name) const {
	double result = 0;
	size_t count = 0;
	for (size_t i = 0; i < _studentsCount; i++)
	{
		for (size_t j = 0; j < _students[i].getGradesCount(); j++)
		{
			if (!strcmp(_students[i].getGrades()[j].getTeacher(), name))
			{
				result += _students[i].getGrades()[j].getValue();
				count++;
			}
		}
	}

	return _studentsCount > 0 ? result / count : 0;
}

void OOPcourse::removeStudent(const char* FN) {

	Student* ptr = getStudentByFN(FN);
	if (ptr != nullptr)
	{
		_studentsCount--;
		std::swap(*ptr, _students[_studentsCount]);
		delete& _students[_studentsCount];
	}
}