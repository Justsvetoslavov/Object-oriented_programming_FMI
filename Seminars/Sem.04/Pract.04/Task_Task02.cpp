#include "Task_Task02.h"

#include <cstring>

Task::Task()
        : Task("", "", 0)
{}

Task::Task(const char *name, const char *description, int points)
{
    strcpy_s(m_name, name);
    strcpy_s(m_description, description);
    m_points = points;
}

void Task::SetName(const char *name)
{
    if(strlen(name) >= MAX_TASK_NAME_SIZE)
        return;

    strcpy_s(m_name, name);
}

void Task::SetDescription(const char *description)
{
    if(strlen(description) >= MAX_TASK_DESCRIPTION_SIZE)
        return;

    strcpy_s(m_description, description);
}

void Task::SetPoints(int points)
{
    m_points = points;
}

const char *Task::GetName() const
{
    return m_name;
}

const char *Task::GetDescription() const
{
    return m_description;
}

int Task::GetPoints() const
{
    return m_points;
}
