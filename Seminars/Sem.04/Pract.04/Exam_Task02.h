#pragma once

#include "Task_Task02.h"

#include <fstream>

const int MAX_TASKS_IN_EXAM = 16;

class Exam
{
private:
    Task m_tasks[MAX_TASKS_IN_EXAM];
    int m_currentTaskPtr = 0;

    int m_minScore;
public:
    Exam(int minPoints = 0);
    Exam(int minPoints, const Task* tasks, size_t tasksLength);

    void AddTask(const Task &task);

    void WriteToFile(std::ofstream &file) const;

    void ReadFromFile(std::ifstream &file);

    void ChangeMin(int min);

    int GetMaxScore() const;

    void Print() const;
};
