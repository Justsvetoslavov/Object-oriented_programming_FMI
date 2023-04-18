#include "Student.h"
#include <cstring>

void Student::copyFrom(const Student& other) {
	setName(other.getName());
	setFN(other.getFN());
	_gradesCount = other.getGradesCount();
	for (size_t i = 0; i < _gradesCount; ++i)
	{
		_grades[i] = other.getGrades()[i];
	}
}

void Student::free() {
	delete[] _name;
	delete[] _fn;
	_gradesCount = 0;
}

Grade* Student::getGradeByTaskAndTeacher(const char* task, const char* teacher) {
	for (size_t i = 0; i < _gradesCount; i++)
	{
		if (!(strcmp(_grades[i].getTask(), task) 
			| strcmp(_grades[i].getTeacher(), teacher)))
		{
			return &_grades[i];
		}
	}
	return nullptr;
}

Student::Student() {
	_name = nullptr;
	_fn = nullptr;
}

Student::Student(const char* name, const char* fn) {
	setName(name);
	setFN(fn);
}

Student::Student(const Student& other) {
	copyFrom(other);
}

Student& Student::operator=(const Student& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Student::~Student() {
	free();
}

const char* Student::getName() const {
	return _name;
}
const char* Student::getFN() const {
	return _fn;
}
const Grade* Student::getGrades() const {
	return _grades;
}
size_t Student::getGradesCount() const {
	return _gradesCount;
}
double Student::getAverageGrade() const {
	double result = 0;
	for (size_t i = 0; i < _gradesCount; ++i)
	{
		result += _grades[i].getValue();
	}

	return _gradesCount > 0 ? result / _gradesCount : 0;
}

void Student::setName(const char* name) {
	try
	{
		int len = strlen(name) + 1;
		_name = new char[len];
		strcpy(_name, name);
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}
void Student::setFN(const char* fn) {
	try
	{
		int len = strlen(fn) + 1;
		_fn = new char[len];
		strcpy(_fn, fn);
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}

void Student::addGrade(const char* task, double value, const char* teacher) {
	if (_gradesCount < StudentC::MAX_GRADES_COUNT)
	{
		_grades[_gradesCount++] = Grade(value, task, teacher);
	}
}

void Student::editGrade(const char* task, double value, const char* teacher) {
	Grade* ptr = getGradeByTaskAndTeacher(task, teacher);
	try
	{
		ptr->setValue(value);
		delete ptr;
	}
	catch (const std::nullptr_t&)
	{
		throw;
	}
}