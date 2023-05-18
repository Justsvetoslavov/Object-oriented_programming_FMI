#include "Student.h"

#include <cstring>
#pragma warning(disable : 4996)

#include <iostream>

Student::Student(const char* name, unsigned FN) {
	setName(name);
	setFN(FN);
}

const Grade* Student::getGrades() const {
	return _grades;
}

unsigned Student::getNumberOfGrades() const {
	return _numberOfGrades;
}

unsigned Student::getFN() const {
	return _FN;
}

const MyString& Student::getName() const {
	return _name;
}

void Student::setName(const char* name) {
	_name = MyString(name);
}

void Student::setGradeAtIndex(size_t ind, double newValue) {
	if (ind >= _numberOfGrades) {
		return;
	}
	_grades[ind].setValue(newValue);
}

void Student::setFN(unsigned FN) {
	_FN = FN;
}

double Student::getGradeValueAtIndex(size_t ind) const {
	if (ind >= _numberOfGrades) {
		return 0;
	}

	return _grades[ind].getValue();
}

int Student::getTaskIndex(const char* task) const {
	for (int i = 0; i < _numberOfGrades; i++) {
		if (strcmp(_grades[i].getTask().c_str(), task) == 0) {
			return i;
		}
	}
	
	return -1;
}

void Student::addGrade(double value, const char* task, const Teacher& teacher) {
	if (_numberOfGrades >= MAX_NUMBER_OF_GRADES) {
		return;
	}

	int gradeInd = getTaskIndex(task);
	// If the task exists
	if (gradeInd >= 0) {
		return;
	}

	_grades[_numberOfGrades++] = Grade(value, task, &teacher);
}

std::ostream& operator << (std::ostream& os, const Student& st) {
	os << st._name << ' ' << st._FN << std::endl;
	for (int i = 0; i < st._numberOfGrades; i++) {
		os << st._grades[i] << std::endl;
	}
	os << std::endl;
	return os;
}