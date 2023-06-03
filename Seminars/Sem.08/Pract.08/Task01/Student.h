#pragma once
#include "Task.h"

const int GRADES_MAX_COUNT = 7;

class Student
{
private:
	char* name = nullptr;
	int fn = 0;
	Task tasks[GRADES_MAX_COUNT]{};
	size_t tasksCount = 0;

public:
	Student() = default;
	Student(const char* name, int fn);
	Student(const Student& other);
	Student& operator=(const Student& other);
	~Student();

	void AddTask(const char* taskName, double grade, const char* teacherName);
	int GetFn() const;
	int GetTasksCount() const;
	const Task* GetTasks() const;
	void SetTask(const char* name, double grade);
private:
	void CopyFrom(const Student& other);
	void Free();
};

