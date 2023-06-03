#pragma once
#include "Student.h"
#include "Teacher.h"

const int TEACHERS_MAX_SIZE = 4;

class OOPCourse
{
private:
	Teacher teachers[TEACHERS_MAX_SIZE];
	Student* students;
	size_t teachersCount = 0;
	size_t studentsCount = 0;
	size_t studentsCapacity = 0;
public:
	OOPCourse(const char* lecturer, const char* assistant1);
	OOPCourse(const char* lecturer, const char* assistant1, const char* assistant2);
	OOPCourse(const char* lecturer, const char* assistant1, const char* assistant2, const char* assistant3);
	OOPCourse(const OOPCourse& other);
	OOPCourse& operator=(const OOPCourse& other);
	~OOPCourse();

	void AddStudent(const char* stName, int fn);
	void AddGrade(int fn, const char* taskName, double grade, const char* teacherName);
	double GetAverigeForCourse() const;
	void RemoveStudent(int fn);
	double GetAverigeGradePerTask(const char* taskName) const;
	double GetAverigeFromTeacher(const char* teacherName) const;
private:
	void CopyFrom(const OOPCourse& other);
	void Free();
	bool TeacherExists(const char* teacherName) const;
	void Resize(size_t newCapacity);
};

