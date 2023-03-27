#include "Exam.h"

#include <iostream>
#include <fstream>

Exam::Exam()
        : Exam(0)
{}

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
        m_tasks[m_currentTaskIndex++] = tasks[i];
    }
}

void Exam::AddTask(const Task &task)
{
    if (m_currentTaskIndex >= MAX_TASKS_IN_EXAM)
        return;

    m_tasks[m_currentTaskIndex++] = task;
}

void Exam::WriteToFile(const char* fileName) const
{
    std::ofstream file(fileName, std::ios::binary);

    if (!file.is_open())
        return;

    file.write((const char *) this, sizeof(Exam));

    file.close();
}

void Exam::ReadFromFile(const char* fileName)
{
    std::ifstream file(fileName, std::ios::binary);

    if (!file.is_open())
        return;

    Exam ex;

    file.read((char *) &ex, sizeof(Exam));

    m_minScore = ex.m_minScore;
    m_currentTaskIndex = ex.m_currentTaskIndex;
    for (int i = 0; i < ex.m_currentTaskIndex; ++i)
    {
        m_tasks[i] = ex.m_tasks[i];
    }

    file.close();
}

void Exam::ChangeMin(int min)
{
    m_minScore = min;
}

int Exam::GetMaxScore() const
{
    int maxScore = 0;

    for (int i = 0; i < m_currentTaskIndex; ++i)
    {
        maxScore += m_tasks[i].GetPoints();
    }

    return maxScore;
}

void Exam::Print() const
{
    for (int i = 0; i < m_currentTaskIndex; ++i)
    {
        std::cout <<
                  "Name: `" << m_tasks[i].GetName() << "`\n" <<
                  "Description: `" << m_tasks[i].GetDescription() << "`\n" <<
                  "Points: `" << m_tasks[i].GetPoints() << "`\n";
    }
}
