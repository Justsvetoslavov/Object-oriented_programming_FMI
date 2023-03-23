#include "Exam_Task02.h"

#include <iostream>

Exam::Exam(int minPoints)
{
    m_minScore = minPoints;
}

Exam::Exam(int minPoints, const Task *tasks, size_t tasksLength)
{
    m_minScore = minPoints;

    if (tasksLength >= MAX_TASKS_IN_EXAM || !tasks)
        return;

    for (int i = 0; i < tasksLength; ++i)
    {
        m_tasks[m_currentTaskPtr++] = tasks[i];
    }
}

void Exam::AddTask(const Task &task)
{
    if (m_currentTaskPtr >= MAX_TASKS_IN_EXAM)
        return;

    m_tasks[m_currentTaskPtr++] = task;
}

void Exam::WriteToFile(std::ofstream &file) const
{
    if (!file.is_open())
        return;

    file.write((const char *) this, sizeof(Exam));
}

void Exam::ReadFromFile(std::ifstream &file)
{
    if (!file.is_open())
        return;

    Exam ex;

    file.read((char *) &ex, sizeof(Exam));

    m_minScore = ex.m_minScore;
    m_currentTaskPtr = ex.m_currentTaskPtr;
    for (int i = 0; i < ex.m_currentTaskPtr; ++i)
    {
        m_tasks[i] = ex.m_tasks[i];
    }
}

void Exam::ChangeMin(int min)
{
    m_minScore = min;
}

int Exam::GetMaxScore() const
{
    int maxScore = 0;

    for (int i = 0; i < m_currentTaskPtr; ++i)
    {
        maxScore += m_tasks[i].GetPoints();
    }

    return maxScore;
}

void Exam::Print() const
{
    for (int i = 0; i < m_currentTaskPtr; ++i)
    {
        std::cout <<
                  "Name: `" << m_tasks[i].GetName() << "`\n" <<
                  "Description: `" << m_tasks[i].GetDescription() << "`\n" <<
                  "Points: `" << m_tasks[i].GetPoints() << "`\n";
    }
}
