#pragma once

#include "MyString.h"
#include "Teacher.h"

class Grade {
	double _value = 0;
	MyString _task;
	const Teacher* _teacher = nullptr;

	void setTask(const char* task);
	void setTeacher(const Teacher* teacher);

public:
	Grade() = default;
	Grade(double value, const char* task, const Teacher* teacher);

	void setValue(double value);

	double getValue() const;
	const MyString& getTask() const;
	const Teacher* getTeacher() const;

	bool isValidGrade() const;

	friend std::ostream& operator<<(std::ostream& os, const Grade& grade);
};

