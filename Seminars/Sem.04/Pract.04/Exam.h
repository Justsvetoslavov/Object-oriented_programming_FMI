#pragma once

#include "Task.h"

struct Exam {
private:
    Task tasks[TASKS_COUNT];
    unsigned minPointsToPass;
public:
    Exam(const Task* tasks, int tasksLen, const unsigned int& minPointsToPass);
    Exam() = default;

    void writeToFile() const;

    void readFromFile();

    void changeMin(const unsigned& newMin);

    void getMax() const;
};