#pragma once
#include "String.h"
#include "Grade.h"
#include "Teacher.h"

const int max_Grades_Count = 7;

class Student{
private:
	String name;
	int facultyNumber;
	Grade grades[max_Grades_Count];
	unsigned gradesCount = 0;

	void SetGrade(const char* task, int grade, const Teacher* teacher);
	void ChangeGrade(const char* task, int grade, const Teacher* teacher);

public:
	Student() = default;
	Student(const char* name, int facultyNumber);

	int GetFN() const;

	friend class OOPCourse;
};

