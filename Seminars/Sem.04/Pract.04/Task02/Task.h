#pragma once

const int MAX_TASK_NAME_SIZE = 31;
const int MAX_TASK_DESCRIPTION_SIZE = 127;

class Task
{
private:
    char m_name[MAX_TASK_NAME_SIZE + 1];
    char m_description[MAX_TASK_DESCRIPTION_SIZE + 1];
    int m_points;
public:
    Task();
    Task(const char *name, const char *description, int points);

    void SetName(const char *name);

    void SetDescription(const char *description);

    void SetPoints(int points);

    const char *GetName() const;

    const char *GetDescription() const;

    int GetPoints() const;
};
