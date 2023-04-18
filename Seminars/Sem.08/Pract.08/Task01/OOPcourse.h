#pragma once
#include "Lecturer.h"
#include "Assistant.h"
#include "Student.h"

namespace OOPcourseC {
	const int MAX_ASSISTANTS_COUNT = 3;
	const int STARTING_STUDENTS_COUNT = 64;
	const int MAX_GRADES_COUNT = 7;
}

class OOPcourse {
private:
	Lecturer _lecturer;
	Assistant _assistants[OOPcourseC::MAX_ASSISTANTS_COUNT];
	Student* _students { nullptr };
	size_t _studentsCount;
	size_t _capacity = OOPcourseC::STARTING_STUDENTS_COUNT;

	void copyFrom(const OOPcourse& other);
	void free();
	void resize();
	Student* getStudentByFN(const char* FN);

public:
	OOPcourse(const char* lecturerName, const char* assistantName);
	OOPcourse(const char* lecturerName, const char* assistantName, const char* secondAssistantName);
	OOPcourse(const char* lecturerName, const char* assistantName, const char* secondAssistantName, const char* thirdAssistantName);
	OOPcourse(const OOPcourse& other);
	OOPcourse& operator=(const OOPcourse& other);
	~OOPcourse();

	const Lecturer& getLecturer() const;
	const Assistant* getAssistants() const;
	const Student* getStudents() const;
	size_t getStudentsCount() const;
	size_t getCapacity() const;

	void addStudent(const char* name, const char* FN);
	void addGrade(const char* FN, const char* task, double value, const char* teacherName);
	void editGrade(const char* FN, const char* task, double value, const char* teacherName);
	double getAverageForCourse() const;
	double getAverageGradePerTask(const char* task) const;
	double getAverageFromTeacher(const char* name) const;
	void removeStudent(const char* FN);
};
