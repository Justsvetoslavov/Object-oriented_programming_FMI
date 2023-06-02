#pragma once
#include "String.h"
#include "Teacher.h"

class Grade{
private:
	unsigned grade = 2;
	String task;
	const Teacher* teacher = nullptr;

	void SetGrade(int grade);
public:
	Grade() = default;
	Grade(int grade);
	Grade(const char* task, int grade, const Teacher* teacher);

	const String& GetTask() const;
	int GetGrade() const;
	const char* GetTeacher() const;
};

