#pragma once
#include "Grade.h"

namespace StudentC{
	const int MAX_GRADES_COUNT = 7;
}

class Student {
private:
	char* _name;
	char* _fn;
	Grade _grades[StudentC::MAX_GRADES_COUNT];
	size_t _gradesCount = 0;

	void copyFrom(const Student& other);
	void free();
	Grade* getGradeByTaskAndTeacher(const char* task, const char* teacher);
public:
	Student();
	Student(const char* name, const char* fn);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	const char* getName() const;
	const char* getFN() const;
	const Grade* getGrades() const;
	size_t getGradesCount() const;
	double getAverageGrade() const;

	void setName(const char* name);
	void setFN(const char* fn);

	void addGrade(const char* task, double value, const char* teacher);
	void editGrade(const char* task, double value, const char* teacher);
};