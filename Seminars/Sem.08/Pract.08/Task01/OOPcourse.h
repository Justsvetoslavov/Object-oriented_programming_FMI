#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Grade.h"

const int max_Teachers_Count = 4;

class OOPCourse {
private:
	Teacher teachers[max_Teachers_Count];
	unsigned teachersCount = 0;
	Student** students = nullptr;
	unsigned studentsCapacity = 2;
	unsigned studentsCount = 0;

public:
	OOPCourse(const Teacher* teacher, const Teacher* as1 = nullptr, const Teacher* as2 = nullptr, const Teacher* as3 = nullptr);
	OOPCourse(const OOPCourse& other);
	OOPCourse& operator=(const OOPCourse& other);
	~OOPCourse();

	void AddStudent(const char* name, int facultyNumber);
	void AddGrade(int facNum, const char* task, int grade, const Teacher* teacher);
	void ChangeGrade(int facNum, const char* task, int newGrade, const Teacher* teacher);
	int IndexOfStudent(int facNum) const;
	double GetAverageForCourse() const;
	void RemoveStudent(int facNum);
	double GetAverageGradePerTask(const char* task) const;
	double GetAverageFromTeacher(const char* teacher) const;

private:
	void free();
	void copyFrom(const OOPCourse& other);
	void Resize();
};

