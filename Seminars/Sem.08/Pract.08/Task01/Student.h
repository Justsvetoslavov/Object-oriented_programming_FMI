#pragma once

#include "Grade.h"

const int MAX_NUMBER_OF_GRADES = 7;

class Student {
	Grade _grades[MAX_NUMBER_OF_GRADES];
	unsigned _numberOfGrades = 0;
	unsigned _FN = 0;
	MyString _name;

public:
	Student() = default;
	Student(const char* name, unsigned FN);

	const Grade* getGrades() const;
	unsigned getNumberOfGrades() const;
	unsigned getFN() const;
	const MyString& getName() const;

	void setName(const char* name);
	void setFN(unsigned FN);

	int getTaskIndex(const char* task) const;

	void addGrade(double value, const char* task, const Teacher& teacher);

	double getGradeValueAtIndex(size_t ind) const;
	void setGradeAtIndex(size_t ind, double newValue);

	friend std::ostream& operator << (std::ostream& os, const Student& st);
};