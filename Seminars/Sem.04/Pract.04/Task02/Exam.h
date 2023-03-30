#pragma once

#include "Task.h"

#include <cstdint>

const int MAX_TASKS_IN_EXAM = 16;

class Exam
{
private:
    Task m_tasks[MAX_TASKS_IN_EXAM];
    int m_currentTaskIndex = 0;

    int m_minScore;
public:
    Exam();
    Exam(int minPoints);
    Exam(int minPoints, const Task* tasks, size_t tasksLength);

    void AddTask(const Task &task);

    void WriteToFile(const char* fileName) const;

    void ReadFromFile(const char* fileName);

    void ChangeMin(int min);

    int GetMaxScore() const;

    void Print() const;
};
