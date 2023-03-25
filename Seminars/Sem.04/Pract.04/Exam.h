#pragma once
#include "Task.h"

const int MAX_TASKS_COUNT = 20;

class Exam {
	Task tasks[MAX_TASKS_COUNT];
	unsigned tasksCount;
	unsigned minPoints;
	bool AreMinPointsValid(unsigned minPoints) const;
public:
	Exam();
	Exam(Task* tasks, unsigned tasksCount, unsigned minPoints);
	const Task* GetTasks() const;
	unsigned GetMinPoints() const;
	void SetTasks(Task* tasks, unsigned tasksCount);
	void SetMinPoints(unsigned newMinPoints);
	void WriteToFile(const char* fileName) const;
	void ReadFromFile(const char* fileName);
	unsigned GetMaxPoints() const;
};