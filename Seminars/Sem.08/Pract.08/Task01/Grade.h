#pragma once

class Grade {
private:
	double _value;
	char* _task;
	char* _teacher;

	void free();
	void copyFrom(const Grade& other);

public:
	Grade();
	Grade(double value, const char* task, const char* teacher);
	Grade(const Grade& grade);
	Grade& operator=(const Grade& other);
	~Grade();

	double getValue() const;
	const char* getTask() const;
	const char* getTeacher() const;

	void setValue(double value);
	void setTask(const char* task);
	void setTeacher(const char* teacher);
};