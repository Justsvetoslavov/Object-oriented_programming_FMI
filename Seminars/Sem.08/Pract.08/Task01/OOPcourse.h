#pragma once

#include "Student.h"
#include "Teacher.h"

const int MAX_NUMBER_OF_ASSISTANTS = 3;
const int START_ARRAY_SIZE = 2;

class OOPcourse {
	// A student exists intependently, outside the course 
	Student** _students = nullptr;

	// One lecturer/assistant can teach multiple OOP courses 
	Teacher* _lecturer = nullptr;
	Teacher* _assistants[MAX_NUMBER_OF_ASSISTANTS]{ nullptr };
	
	unsigned _numberOfStudents = 0;
	unsigned _arraySize = START_ARRAY_SIZE;

	void copyFrom(const OOPcourse& other);
	void free();
	void resize();
	int find(unsigned FN);

public:

	OOPcourse();
	OOPcourse(Teacher* lecturer, Teacher* a1 = nullptr, Teacher* a2 = nullptr, Teacher* a3 = nullptr);
	OOPcourse(const OOPcourse& other);
	OOPcourse& operator=(const OOPcourse& other);
	~OOPcourse();

	void addStudent(Student& st);
	void addGrade(unsigned FN, const char* taskName, double gradeValue, const Teacher& teacher);
	double getAverageForCourse() const;
	bool removeStudent(unsigned FN);
	double getAverageGradePerTask(const char* taskName) const;
	double getAverageFromTeacher(const Teacher& teacher) const;

	void changeGrade(unsigned FN, const char* taskName, double newGrade);

	friend std::ostream& operator << (std::ostream& os, const OOPcourse& c);
};